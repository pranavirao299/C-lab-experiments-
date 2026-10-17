#include <iostream>
using namespace std;

class Student {
private:
    int rollNo;
    float marks;

public:
    Student() : Student(0, 0.0f) {
    }

    Student(int r) : Student(r, 0.0f) {
    }

    Student(int r, float m) {
        rollNo = r;
        marks = m;
    }

    void display() {
        cout << "Roll number: " << rollNo << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    Student s1;
    Student s2(101);
    Student s3(102, 87.5f);

    cout << "Student 1" << endl;
    s1.display();

    cout << "\nStudent 2" << endl;
    s2.display();

    cout << "\nStudent 3" << endl;
    s3.display();

    return 0;
}