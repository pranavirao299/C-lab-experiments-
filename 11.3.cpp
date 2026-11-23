<<<<<<< HEAD
#include <iostream>
#include <string>
using namespace std;

// Class template with TWO independent type parameters
template <typename K, typename V>
struct Pair {
    K key;
    V value;

    void show() const {
        cout << key << " -> " << value << endl;
    }
};

// Function template with TWO type parameters
template <typename A, typename B>
auto bigger(A a, B b) {
    return (a > b) ? a : b;
}

int main() {
    Pair<string, int> p{"ECE", 121};   // K=string, V=int
    p.show();

    Pair<int, double> q{7, 3.5};        // K=int, V=double
    q.show();

    cout << "bigger(3, 9.5) = " << bigger(3, 9.5) << endl;

    return 0;
=======
#include <iostream>
#include <string>
using namespace std;

// Class template with TWO independent type parameters
template <typename K, typename V>
struct Pair {
    K key;
    V value;

    void show() const {
        cout << key << " -> " << value << endl;
    }
};

// Function template with TWO type parameters
template <typename A, typename B>
auto bigger(A a, B b) {
    return (a > b) ? a : b;
}

int main() {
    Pair<string, int> p{"ECE", 121};   // K=string, V=int
    p.show();

    Pair<int, double> q{7, 3.5};        // K=int, V=double
    q.show();

    cout << "bigger(3, 9.5) = " << bigger(3, 9.5) << endl;

    return 0;
>>>>>>> bb7a10374dc0e5456bf47fc1efad8b0641cac135
}