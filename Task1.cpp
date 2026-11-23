#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    int* marks; // Dynamically allocated marks for 3 subjects
    static int studentCount; // Number of Student objects currently alive

public:
    // Parameterized constructor
    Student(const string& studentName, int roll, int m1, int m2, int m3)
        : name(studentName), rollNumber(roll), marks(new int[3]) {
        setMarks(m1, m2, m3);
        ++studentCount;
    }

    // Copy constructor (deep copy)
    Student(const Student& other)
        : name(other.name), rollNumber(other.rollNumber), marks(new int[3]) {
        for (int i = 0; i < 3; ++i) {
            marks[i] = other.marks[i];
        }
        ++studentCount;
    }

    // Copy assignment operator (deep copy)
    Student& operator=(const Student& other) {
        if (this != &other) {
            name = other.name;
            rollNumber = other.rollNumber;
            for (int i = 0; i < 3; ++i) {
                marks[i] = other.marks[i];
            }
        }
        return *this;
    }

    // Destructor releases dynamically allocated memory
    ~Student() {
        delete[] marks;
        --studentCount;
    }

    // Overloaded function 1: set all three marks individually
    void setMarks(int m1, int m2, int m3) {
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }

    // Overloaded function 2: set marks from an array
    void setMarks(const int newMarks[3]) {
        for (int i = 0; i < 3; ++i) {
            marks[i] = newMarks[i];
        }
    }

    double calculateAverage() const {
        return (marks[0] + marks[1] + marks[2]) / 3.0;
    }

    // Overloaded display functions
    void display() const {
        cout << name << " (Roll No: " << rollNumber << ")";
    }

    void display(bool showMarks) const {
        display();
        if (showMarks) {
            cout << " | Marks: " << marks[0] << ", " << marks[1]
                 << ", " << marks[2]
                 << " | Average: " << fixed << setprecision(2)
                 << calculateAverage();
        }
        cout << '\n';
    }

    // Overloaded > operator compares students by average marks
    bool operator>(const Student& other) const {
        return calculateAverage() > other.calculateAverage();
    }

    static int getStudentCount() {
        return studentCount;
    }

    // Friend function can access private data of Student
    friend void compareStudents(const Student& first, const Student& second);
};

int Student::studentCount = 0;

void compareStudents(const Student& first, const Student& second) {
    cout << "Friend function comparison: ";
    if (first.calculateAverage() > second.calculateAverage()) {
        cout << first.name << " has higher average marks than " << second.name << ".\n";
    } else if (first.calculateAverage() < second.calculateAverage()) {
        cout << second.name << " has higher average marks than " << first.name << ".\n";
    } else {
        cout << first.name << " and " << second.name << " have equal average marks.\n";
    }
}

int main() {
    cout << "========== STUDENT RECORD SYSTEM ==========" << '\n';

    Student student1("Asha", 101, 85, 90, 88);
    Student student2("Ravi", 102, 78, 82, 80);
    Student student3("Meera", 103, 92, 95, 94);

    cout << "\nStudent details:\n";
    student1.display(true);
    student2.display(true);
    student3.display(true);

    cout << "\nNumber of students: " << Student::getStudentCount() << '\n';

    cout << "\nOperator overloading (>):\n";
    cout << "Is Meera's average greater than Asha's? "
         << (student3 > student1 ? "Yes" : "No") << '\n';
    cout << "Is Ravi's average greater than Asha's? "
         << (student2 > student1 ? "Yes" : "No") << '\n';

    cout << '\n';
    compareStudents(student1, student2);

    cout << "\nProgram completed successfully.\n";
    return 0;
}