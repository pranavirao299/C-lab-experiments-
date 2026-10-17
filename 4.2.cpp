#include <iostream>
using namespace std;

class Array {
private:
    int *data;
    int size;

public:
    Array(int n) {
        size = n;
        data = new int[size];

        for (int i = 0; i < size; i++)
            data[i] = 0;
    }

    Array(const Array &other) {
        size = other.size;
        data = new int[size];

        for (int i = 0; i < size; i++)
            data[i] = other.data[i];
    }

    ~Array() {
        delete[] data;
    }

    void set(int index, int value) {
        if (index >= 0 && index < size)
            data[index] = value;
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << data[i] << " ";

        cout << endl;
    }
};

int main() {
    Array a1(3);

    a1.set(0, 10);
    a1.set(1, 20);
    a1.set(2, 30);

    Array a2 = a1;
    a2.set(0, 99);

    cout << "Original array: ";
    a1.display();

    cout << "Copied array: ";
    a2.display();

    return 0;
}