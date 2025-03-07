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
    Employee emp("Devesh", 80000);
    Manager mgr("Conor", 70000, 10000);
    
    emp.displayDetails();
    cout << "-----------------" << endl;
    mgr.displayDetails();
    
    return 0;
}
