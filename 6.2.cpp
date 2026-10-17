#include <iostream>
using namespace std;

class Array {
private:
    int *data;
    int size;

public:
    Array(int n) {
        size = n;
        data = new int[size]();
    }

    Array(const Array &other) {
        size = other.size;
        data = new int[size];

        for (int i = 0; i < size; i++)
            data[i] = other.data[i];
    }

    Array& operator=(const Array &other) {
        if (this != &other) {
            int *newData = new int[other.size];

            for (int i = 0; i < other.size; i++)
                newData[i] = other.data[i];

            delete[] data;
            data = newData;
            size = other.size;
        }

        return *this;
    }

    ~Array() {
        delete[] data;
    }

    void set(int index, int value) {
        if (index >= 0 && index < size)
            data[index] = value;
    }

    void display() const {
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

    Array a2(2);
    a2 = a1;

    a2.set(0, 99);

    cout << "Original array: ";
    a1.display();

    cout << "Assigned array: ";
    a2.display();

    return 0;
}