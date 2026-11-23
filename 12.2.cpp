<<<<<<< HEAD
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    vector<int> scores = {50, 90, 20, 75, 60, 95, 40};

    priority_queue<int> pq(scores.begin(), scores.end());  // max-heap

    cout << "Top 3 scores: ";

    for (int k = 0; k < 3 && !pq.empty(); ++k) {
        cout << pq.top() << " ";     // largest first
        pq.pop();
    }

    cout << endl;
    return 0;
=======
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    vector<int> scores = {50, 90, 20, 75, 60, 95, 40};

    priority_queue<int> pq(scores.begin(), scores.end());  // max-heap

    cout << "Top 3 scores: ";

    for (int k = 0; k < 3 && !pq.empty(); ++k) {
        cout << pq.top() << " ";     // largest first
        pq.pop();
    }

    cout << endl;
    return 0;
>>>>>>> bb7a10374dc0e5456bf47fc1efad8b0641cac135
}