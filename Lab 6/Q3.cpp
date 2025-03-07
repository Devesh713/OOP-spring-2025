#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}
    virtual void displayDetails() {
        cout << "Name: " << name << "\nAge: " << age << endl;
    }
};

class Teacher : public Person {
protected:
    string subject;

public:
    Teacher(string n, int a, string sub) : Person(n, a), subject(sub) {}
    void displayDetails() override {
        cout << "Name: " << name << "\nAge: " << age << "\nSubject: " << subject << endl;
    }
};

class Researcher : public Person {
protected:
    string researchArea;

public:
    Researcher(string n, int a, string rA) : Person(n, a), researchArea(rA) {}
    void displayDetails() override {
        cout << "Name: " << name << "\nAge: " << age << "\nResearch Area: " << researchArea << endl;
    }
};

class Professor : public Teacher, public Researcher {
private:
    int publications;

public:
    Professor(string n, int a, string sub, string rA, int pub) 
        : Person(n, a), Teacher(n, a, sub), Researcher(n, a, rA), publications(pub) {}
    void displayDetails() override {
        cout << "Name: " << name << "\nAge: " << age << "\nSubject: " << subject
             << "\nResearch Area: " << researchArea << "\nPublications: " << publications << endl;
    }
};

int main() {
    string name, subject, researchArea;
    int age, publications;
    
    cout << "Enter professor's name: ";
    getline(cin, name);
    cout << "Enter age: ";
    cin >> age;
    cin.ignore();
    cout << "Enter subject expertise: ";
    getline(cin, subject);
    cout << "Enter research area: ";
    getline(cin, researchArea);
    cout << "Enter number of publications: ";
    cin >> publications;
    
    Professor prof(name, age, subject, researchArea, publications);
    cout << "-----------------" << endl;
    prof.displayDetails();
    
    return 0;
}
