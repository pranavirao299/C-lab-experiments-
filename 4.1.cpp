#include <iostream>
using namespace std;

class Demo {
private:
    int value;

public:
    Demo(int v) {
        value = v;
        cout << "Constructor called for " << value << endl;
    }

    ~Demo() {
        cout << "Destructor called for " << value << endl;
    }
};

int main() {
    cout << "Entering main()" << endl;

    Demo d1(1);
    Demo d2(2);

    {
        Demo d3(3);
        cout << "Inside block" << endl;
    }

    cout << "Leaving main()" << endl;

    return 0;
}