#include <iostream>
#include <string>

using namespace std;

class Professor 
{
private:
    string name;        
    string department;  

public:
    Professor(string n, string dept) : name(n), department(dept) {}
    void displayDetails() 
    {
        cout << "--- Professor Info ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Dept: " << department << endl;
    }
};

class University 
{
private:
    Professor** professors; 
    int totalProfessors;     
    int capacity;           

public:
    University(int cap) : totalProfessors(0), capacity(cap) 
    {
        professors = new Professor*[capacity];  
    }
    ~University() 
    {
        for (int i = 0; i < totalProfessors; i++) 
        {
            delete professors[i]; 
        }
        delete[] professors; 
    }

    void addProfessor(const string& name, const string& department) 
    {
        if (totalProfessors < capacity) 
        {
            professors[totalProfessors] = new Professor(name, department);  
            totalProfessors++;
            cout << "Professor added successfully!" << endl;
        } 
        else 
        {
            cout << "Error: No more capacity for new professors." << endl;
        }
    }

    void displayUniversityDetails() const 
    {
        cout << "===== University Summary =====" << endl;
        cout << "Total Professors: " << totalProfessors << endl;
        for (int i = 0; i < totalProfessors; i++) 
        {
            professors[i]->displayDetails();
        }
    }
};

int main() 
{    
    University fastUniversity(5);

    fastUniversity.addProfessor("Uzma Saleh", "MVC"); 
    fastUniversity.addProfessor("Atiya J", "OOP"); 
    fastUniversity.displayUniversityDetails();
    
    return 0;
}
