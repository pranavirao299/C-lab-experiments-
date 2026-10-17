#include <iostream>
using namespace std;

class Demo {
private:
    static int count;

public:
    Demo() {
        count++;
        cout << "Object created. Count = " << count << endl;
    }

    Demo(const Demo &) {
        count++;
        cout << "Object copied. Count = " << count << endl;
    }

    ~Demo() {
        count--;
        cout << "Object destroyed. Count = " << count << endl;
    }

    static int getCount() {
        return count;
    }
};

int Demo::count = 0;

int main() {
    Demo d1, d2;

    cout << "Current objects: " << Demo::getCount() << endl;

    {
        Demo d3;
        cout << "Inside block: " << Demo::getCount() << endl;
    }

    cout << "After block: " << Demo::getCount() << endl;

    return 0;
}