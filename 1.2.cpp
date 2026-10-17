#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s;
    cout << "Enter a word: ";
    cin >> s;

    bool palindrome = true;

    for (int i = 0; i < static_cast<int>(s.length()) / 2; i++) {
        if (tolower(static_cast<unsigned char>(s[i])) !=
            tolower(static_cast<unsigned char>(s[s.length() - 1 - i]))) {
            palindrome = false;
            break;
        }
    }

    cout << "Length: " << s.length() << endl;

    if (palindrome)
        cout << s << " is a palindrome." << endl;
    else
        cout << s << " is not a palindrome." << endl;

    char target;
    cout << "Enter a character to count: ";
    cin >> target;

    int count = 0;
    for (char ch : s) {
        if (tolower(static_cast<unsigned char>(ch)) ==
            tolower(static_cast<unsigned char>(target))) {
            count++;
        }
    }

    cout << "Frequency of " << target << " = " << count << endl;

    return 0;
}