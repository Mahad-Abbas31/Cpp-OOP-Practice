#include <iostream>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    void setData(string name, int accNo, double bal) {
        accountHolder = name;
        accountNumber = accNo;
        balance = bal;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount deposited successfully!\n";
        } else {
            cout << "Invalid amount!\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Amount withdrawn successfully!\n";
        } else {
            cout << "Insufficient balance or invalid amount!\n";
        }
    }

    void display() {
        cout << "\nAccount Holder: " << accountHolder;
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nBalance: " << balance << endl;
    }
};

int main() {
    BankAccount acc;

    acc.setData("Mahad Abbas", 101, 5000);

    acc.display();

    acc.deposit(2000);
    acc.display();

    acc.withdraw(1500);
    acc.display();

    return 0;
}
