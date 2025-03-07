#include <iostream>
using namespace std;

class Employee {
protected:
    string name;
    float salary;

public:
    Employee(string n, float s) : name(n), salary(s) {}
    virtual void displayDetails() {
        cout << "Name: " << name << "\nSalary: " << salary << endl;
    }
};

class Manager : public Employee {
private:
    float bonus;

public:
    Manager(string n, float s, float b) : Employee(n, s), bonus(b) {}
    void displayDetails() override {
        cout << "Name: " << name << "\nSalary: " << salary << "\nBonus: " << bonus << endl;
    }
};

int main() {
    string name;
    float salary, bonus;
    
    cout << "Enter manager's name: ";
    getline(cin, name);
    cout << "Enter salary: ";
    cin >> salary;
    cout << "Enter bonus: ";
    cin >> bonus;
    
    Manager mgr(name, salary, bonus);
    cout << "-----------------" << endl;
    mgr.displayDetails();
    
    return 0;
}
