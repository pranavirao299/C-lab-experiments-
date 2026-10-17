#include <iostream>
using namespace std;

class Register {
private:
    unsigned char value;

public:
    void write(int v) {
        value = static_cast<unsigned char>(v & 255);
    }

    int read() {
        return value;
    }

    void display() {
        cout << "Register value: " << read() << endl;
    }
};

int main() {
    Register r[4];

    r[0].write(10);
    r[1].write(20);
    r[2].write(30);
    r[3].write(255);

    for (int i = 0; i < 4; i++) {
        cout << "R" << i << ": ";
        r[i].display();
    }

    return 0;
}