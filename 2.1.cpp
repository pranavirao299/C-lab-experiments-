#include <iostream>
using namespace std;

inline int square(int n) {
    return n * n;
}

int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

int main() {
    cout << "Square of 5 = " << square(5) << endl;
    cout << "Integer addition = " << add(10, 20) << endl;
    cout << "Decimal addition = " << add(2.5, 3.5) << endl;

    return 0;
}