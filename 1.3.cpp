#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "Programming";
    string s2 = "Program";

    cout << "Original string: " << s1 << endl;
    cout << "Substring: " << s1.substr(0, 7) << endl;

    if (s1 == s2)
        cout << "Strings are equal." << endl;
    else
        cout << "Strings are not equal." << endl;

    char ch;
    cout << "Enter a character: ";
    cin >> ch;

    int frequency = 0;

    for (char c : s1) {
        if (c == ch)
            frequency++;
    }

    cout << "Frequency of " << ch << " = "
         << frequency << endl;

    return 0;
} 