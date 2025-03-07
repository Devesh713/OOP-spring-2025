#include <iostream>
using namespace std;

class Account {
protected:
    int accountNumber;
    float balance;

public:
    Account(int accNum, float bal) : accountNumber(accNum), balance(bal) {}
    virtual void displayDetails() {
        cout << "Account Number: " << accountNumber << "\nBalance: " << balance << endl;
    }
};

class SavingsAccount : public Account {
private:
    float interestRate;

public:
    SavingsAccount(int accNum, float bal, float rate) : Account(accNum, bal), interestRate(rate) {}
    void displayDetails() override {
        cout << "Account Number: " << accountNumber << "\nBalance: " << balance 
             << "\nInterest Rate: " << interestRate << "%" << endl;
    }
};

class CheckingAccount : public Account {
private:
    float overdraftLimit;

public:
    CheckingAccount(int accNum, float bal, float limit) : Account(accNum, bal), overdraftLimit(limit) {}
    void displayDetails() override {
        cout << "Account Number: " << accountNumber << "\nBalance: " << balance 
             << "\nOverdraft Limit: " << overdraftLimit << endl;
    }
};

int main() {
    int accNum;
    float balance, interestRate, overdraftLimit;
    
    cout << "Enter Savings Account details:\n";
    cout << "Account Number: ";
    cin >> accNum;
    cout << "Balance: ";
    cin >> balance;
    cout << "Interest Rate: ";
    cin >> interestRate;
    SavingsAccount savings(accNum, balance, interestRate);
    
    cout << "\nEnter Checking Account details:\n";
    cout << "Account Number: ";
    cin >> accNum;
    cout << "Balance: ";
    cin >> balance;
    cout << "Overdraft Limit: ";
    cin >> overdraftLimit;
    CheckingAccount checking(accNum, balance, overdraftLimit);
    
    cout << "\n-----------------\n";
    savings.displayDetails();
    cout << "-----------------\n";
    checking.displayDetails();
    
    return 0;
}
