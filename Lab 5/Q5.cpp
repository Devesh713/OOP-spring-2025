#include <iostream>
#include <string>

using namespace std;

class TourGuide 
{
private:
    string name;          
    int experience; 
    string specialization; 
public:
    TourGuide(string n, int exp, string spec) 
        : name(n), experience(exp), specialization(spec) {}
   
    void displayDetails() const 
    {
        cout << "Guide Name: " << name << endl;
        cout << "Experience: " << experience << " years" << endl;
        cout << "Expertise: " << specialization << endl;
    }
};

class TravelAgency 
{
private:
    TourGuide** tourGuides; 
    int totalGuides;       
    int capacity;         
public:
    TravelAgency(int cap) : totalGuides(0), capacity(cap) 
    {
        tourGuides = new TourGuide*[capacity];
    }
    ~TravelAgency() 
    {
        for (int i = 0; i < totalGuides; i++) 
        {
            delete tourGuides[i];  
        }
        delete[] tourGuides;  
    }

    void addTourGuide(const string& name, int experience, const string& specialization) 
    {
        if (totalGuides < capacity) 
        {
            tourGuides[totalGuides] = new TourGuide(name, experience, specialization); 
            totalGuides++;
        } 
        else 
        {
            cout << "Capacity full! Cannot add more guides." << endl;
        }
    }

    void displayAgencyDetails() const
    {
        cout << "*** Travel Agency Overview ***" << endl;
        cout << "Total Guides: " << totalGuides << endl;
        for (int i = 0; i < totalGuides; i++) 
        {
            cout << "Guide " << (i + 1) << " Profile:" << endl;
            tourGuides[i]->displayDetails();
        }
    }
};

int main() 
{
    TravelAgency agency(3);
    agency.addTourGuide("David", 5, "Adventure");
    agency.addTourGuide("Emma", 10, "Cultural Heritage");
    agency.addTourGuide("Liam", 6, "Wildlife");
    agency.displayAgencyDetails();
    return 0;
}
