#include <iostream>
using namespace std;

void swapRef(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapPtr(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;

    cout << "Before swapping: x = " << x << ", y = " << y << endl;

    swapRef(x, y);
    cout << "After reference swap: x = " << x
         << ", y = " << y << endl;

    swapPtr(&x, &y);
    cout << "After pointer swap: x = " << x
         << ", y = " << y << endl;

    return 0;
}