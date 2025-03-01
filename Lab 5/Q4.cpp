#include <iostream>
#include <string>

using namespace std;

class Battery 
{
private:
    int capacity;  
public:
    Battery(int cap) : capacity(cap) {}

    void displayBatteryDetails() const 
    {
        cout << "Power Source: " << capacity << " mAh" << endl;
    }
};

class Smartphone 
{
private:
    string model;  
    Battery battery;  
public:
    Smartphone(string m, int batteryCapacity) : model(m), battery(batteryCapacity) {}
    void displayDetails() const 
    {
        cout << "Device Model: " << model << endl;
        battery.displayBatteryDetails();  
    }
};

int main() 
{
    
    Smartphone smartphone1("Pixel", 4500);  
    smartphone1.displayDetails();
    cout << endl;
    Smartphone smartphone2("OnePlus", 4800);  
    smartphone2.displayDetails();
    return 0;
}
