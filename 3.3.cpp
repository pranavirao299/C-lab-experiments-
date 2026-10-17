#include <iostream>
using namespace std;

class Point {
private:
    int x, y;

public:
    Point(int a = 0, int b = 0) {
        x = a;
        y = b;
    }

    Point& set(int x, int y) {
        this->x = x;
        this->y = y;
        return *this;
    }

    Point translated(int dx, int dy) {
        return Point(x + dx, y + dy);
    }

    void display() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

void showPoint(Point p) {
    p.display();
}

int main() {
    Point p(2, 3);

    cout << "Original point: ";
    showPoint(p);

    Point q = p.translated(4, 5);
    cout << "Translated point: ";
    q.display();

    p.set(10, 20);
    cout << "Updated point: ";
    p.display();

    return 0;
}