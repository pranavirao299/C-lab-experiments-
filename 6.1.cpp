#include <iostream>
using namespace std;

class Complex {
private:
    int real, imag;

public:
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }

    Complex operator+(const Complex &c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    bool operator==(const Complex &c) const {
        return real == c.real && imag == c.imag;
    }

    friend ostream& operator<<(ostream &out, const Complex &c) {
        out << c.real;

        if (c.imag >= 0)
            out << " + " << c.imag << "i";
        else
            out << " - " << -c.imag << "i";

        return out;
    }
};

int main() {
    Complex c1(2, 3);
    Complex c2(1, -4);

    Complex c3 = c1 + c2;

    cout << "First number: " << c1 << endl;
    cout << "Second number: " << c2 << endl;
    cout << "Sum: " << c3 << endl;

    if (c1 == c2)
        cout << "Numbers are equal." << endl;
    else
        cout << "Numbers are not equal." << endl;

    return 0;
}