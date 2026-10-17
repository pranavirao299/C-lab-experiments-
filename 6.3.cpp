#include <iostream>
using namespace std;

class Counter {
private:
    int value;

public:
    Counter(int value = 0) :value(value) {}

    Counter& operator++() {
        ++value;
        return *this;
    }

    int Value() const {
        return value;
    }
};

class Array {
private:
    int data[5]={10,20,30,40,50};

public:
    int& operator[](int index) {
       if(index<0|| index>=5)
       { cout<<"out of range\n";
        return data[0];}
        return data[index];
    }
};

int main() {
    Counter c(5);

    cout << "Original value: " << c.Value() << endl;

    ++c;

    cout << "After increment: " << c.Value() << endl;

    Array arr;
    arr[10] = 99;

    return 0;
}