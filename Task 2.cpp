#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <memory>
#include <stdexcept>
#include <limits>

using namespace std;

// Base class
class Student {
protected:
    string name;
    int rollNumber;

public:
    Student(const string& studentName, int roll)
        : name(studentName), rollNumber(roll) {}

    virtual void display() const {
        cout << "Name: " << name
             << "\nRoll Number: " << rollNumber << '\n';
    }

    virtual ~Student() = default;
};

// Derived class
class Result : public Student {
private:
    vector<int> marks;

    void validateMarks() const {
        for (int mark : marks) {
            if (mark < 0 || mark > 100) {
                throw invalid_argument(
                    "Marks must be between 0 and 100."
                );
            }
        }
    }

public:
    Result(const string& studentName, int roll,
           const vector<int>& subjectMarks)
        : Student(studentName, roll), marks(subjectMarks) {

        if (marks.size() != 3) {
            throw invalid_argument(
                "Exactly three subject marks are required."
            );
        }

        validateMarks();
    }

    int totalMarks() const {
        int total = 0;

        for (int mark : marks) {
            total += mark;
        }

        return total;
    }

    double percentage() const {
        return totalMarks() / 3.0;
    }

    string grade() const {
        double p = percentage();

        if (p >= 90) return "A+";
        if (p >= 80) return "A";
        if (p >= 70) return "B";
        if (p >= 60) return "C";
        if (p >= 50) return "D";

        return "F";
    }

    // Runtime polymorphism
    void display() const override {
        cout << left << setw(20) << name
             << setw(12) << rollNumber
             << setw(10) << marks[0]
             << setw(10) << marks[1]
             << setw(10) << marks[2]
             << setw(12) << totalMarks()
             << setw(12) << fixed << setprecision(2)
             << percentage()
             << grade() << '\n';
    }

    string toFileLine() const {
        ostringstream line;

        line << name << '|'
             << rollNumber << '|'
             << marks[0] << '|'
             << marks[1] << '|'
             << marks[2];

        return line.str();
    }
};

// Read an integer safely
int readInteger(const string& prompt) {
    while (true) {
        cout << prompt;

        string input;
        getline(cin, input);

        try {
            size_t position = 0;
            int value = stoi(input, &position);

            if (position != input.size()) {
                throw invalid_argument(
                    "Please enter a whole number."
                );
            }

            return value;
        }
        catch (const exception&) {
            cout << "Invalid input. Please enter a whole number.\n";
        }
    }
}

// Validate marks
int readMark(const string& prompt) {
    while (true) {
        int mark = readInteger(prompt);

        try {
            if (mark < 0 || mark > 100) {
                throw out_of_range(
                    "Marks must be between 0 and 100."
                );
            }

            return mark;
        }
        catch (const out_of_range& error) {
            cout << "Invalid marks: " << error.what()
                 << " Try again.\n";
        }
    }
}

// Save records to file
void saveRecords(const vector<Result>& students,
                 const string& fileName) {

    ofstream outFile(fileName);

    if (!outFile) {
        throw runtime_error(
            "Unable to open file for writing."
        );
    }

    for (const Result& student : students) {
        outFile << student.toFileLine() << '\n';
    }

    if (!outFile) {
        throw runtime_error(
            "An error occurred while writing records."
        );
    }
}

// Load records from file
vector<Result> loadRecords(const string& fileName) {
    ifstream inFile(fileName);

    if (!inFile) {
        throw runtime_error(
            "Unable to open file for reading."
        );
    }

    vector<Result> loadedStudents;
    string line;

    while (getline(inFile, line)) {
        if (line.empty()) continue;

        try {
            stringstream data(line);

            string studentName, rollText;
            string mark1Text, mark2Text, mark3Text;

            if (!getline(data, studentName, '|') ||
                !getline(data, rollText, '|') ||
                !getline(data, mark1Text, '|') ||
                !getline(data, mark2Text, '|') ||
                !getline(data, mark3Text)) {

                throw invalid_argument(
                    "Incomplete record in file."
                );
            }

            int roll = stoi(rollText);

            vector<int> subjectMarks = {
                stoi(mark1Text),
                stoi(mark2Text),
                stoi(mark3Text)
            };

            loadedStudents.emplace_back(
                studentName, roll, subjectMarks
            );
        }
        catch (const exception& error) {
            cerr << "Skipping invalid file record: "
                 << error.what() << '\n';
        }
    }

    return loadedStudents;
}

// Display student records
void displayStudents(const vector<Result>& students) {

    cout << left
         << setw(20) << "Name"
         << setw(12) << "Roll No."
         << setw(10) << "Sub 1"
         << setw(10) << "Sub 2"
         << setw(10) << "Sub 3"
         << setw(12) << "Total"
         << setw(12) << "Percent"
         << "Grade\n";

    cout << string(96, '-') << '\n';

    // Base class pointers demonstrate runtime polymorphism
    vector<unique_ptr<Student>> studentViews;

    for (const Result& student : students) {
        studentViews.push_back(
            make_unique<Result>(student)
        );
    }

    for (const auto& student : studentViews) {
        student->display();
    }
}

// Main function
int main() {

    const string fileName = "student_records.txt";
    vector<Result> students;

    cout << "===============================================\n";
    cout << "       STUDENT RESULT MANAGEMENT SYSTEM\n";
    cout << "===============================================\n\n";

    int numberOfStudents =
        readInteger("Enter number of students: ");

    while (numberOfStudents <= 0) {
        cout << "Number of students must be greater than zero.\n";

        numberOfStudents =
            readInteger("Enter number of students: ");
    }

    for (int i = 0; i < numberOfStudents; ++i) {

        cout << "\nEnter details for student "
             << i + 1 << ":\n";

        string studentName;

        cout << "Name: ";
        getline(cin, studentName);

        while (studentName.empty() ||
               studentName.find('|') != string::npos) {

            cout << "Name cannot be empty or contain '|'. Enter again: ";
            getline(cin, studentName);
        }

        int roll = readInteger("Roll number: ");

        vector<int> subjectMarks;

        for (int subject = 1; subject <= 3; ++subject) {

            subjectMarks.push_back(
                readMark(
                    "Marks for subject " +
                    to_string(subject) + " (0-100): "
                )
            );
        }

        try {
            students.emplace_back(
                studentName, roll, subjectMarks
            );
        }
        catch (const invalid_argument& error) {
            cout << "Unable to add student: "
                 << error.what() << '\n';
            --i;
        }
    }

    try {

        // Save records
        saveRecords(students, fileName);

        cout << "\nRecords saved successfully to "
             << fileName << ".\n";

        // Retrieve records
        vector<Result> loadedStudents =
            loadRecords(fileName);

        cout << "Records retrieved successfully from "
             << fileName << ".\n";

        cout << "\n--------------- STUDENT RESULTS ---------------\n";

        displayStudents(loadedStudents);

        // Find students above threshold
        int threshold = readInteger(
            "\nEnter percentage threshold to find students scoring above it: "
        );

        vector<Result> highScorers;

        copy_if(
            loadedStudents.begin(),
            loadedStudents.end(),
            back_inserter(highScorers),

            [threshold](const Result& student) {
                return student.percentage() > threshold;
            }
        );

        cout << "\nStudents scoring above "
             << threshold << "%:\n";

        if (highScorers.empty()) {
            cout << "No students scored above the specified percentage.\n";
        }
        else {
            displayStudents(highScorers);
        }

        cout << "\nTotal records retrieved: "
             << loadedStudents.size() << '\n';

        cout << "Program completed successfully.\n";
    }

    catch (const exception& error) {
        cerr << "\nFile handling error: "
             << error.what() << '\n';

        return 1;
    }

    return 0;
<<<<<<< HEAD
}
=======
}
>>>>>>> 819385ebf9e1d423c84e236aad635a7aa5887781
