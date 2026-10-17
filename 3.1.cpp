#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string name;
    double balance;

public:
    BankAccount(string n, double b) {
        name = n;
        balance = b;
    }

    void deposit(double amount) {
        if (amount > 0)
            balance += amount;
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient balance or invalid amount." << endl;
    }

    void display() {
        cout << "Account holder: " << name << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    BankAccount account("Pranavi", 1000);

    account.deposit(500);
    account.withdraw(200);
    account.display();

    return 0;
}