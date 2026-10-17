#include <iostream>
using namespace std;

int sum(int a, int b = 10, int c = 20) {
    return a + b + c;
}

int main() {
    cout << "Sum with one argument = " << sum(5) << endl;
    cout << "Sum with two arguments = " << sum(5, 15) << endl;
    cout << "Sum with three arguments = " << sum(5, 15, 25) << endl;

    return 0;
}