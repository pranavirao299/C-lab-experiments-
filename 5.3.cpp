#include <iostream>
using namespace std;

class A {
private:
    int value;

public:
    A(int v) {
        value = v;
    }

    friend class B;
};

class B {
public:
    void display(A obj) {
        cout << "Private value of class A: "
             << obj.value << endl;
    }
};

int main() {
    A objA(100);
    B objB;

    objB.display(objA);

    return 0;
}