#include <iostream>
using namespace std;

class Vehicle {
protected:
    string brand;
    int speed;

public:
    Vehicle(string b, int s) : brand(b), speed(s) {}
    virtual void displayDetails() {
        cout << "Brand: " << brand << "\nSpeed: " << speed << " km/h" << endl;
    }
};

class Car : public Vehicle {
protected:
    int seats;

public:
    Car(string b, int s, int se) : Vehicle(b, s), seats(se) {}
    void displayDetails() override {
        cout << "Brand: " << brand << "\nSpeed: " << speed << " km/h\nSeats: " << seats << endl;
    }
};

class ElectricCar : public Car {
private:
    int batteryLife;

public:
    ElectricCar(string b, int s, int se, int bl) : Car(b, s, se), batteryLife(bl) {}
    void displayDetails() override {
        cout << "Brand: " << brand << "\nSpeed: " << speed << " km/h\nSeats: " << seats << "\nBattery Life: " << batteryLife << " hours" << endl;
    }
};

int main() {
    string brand;
    int speed, seats, batteryLife;
    
    cout << "Enter electric car brand: ";
    getline(cin, brand);
    cout << "Enter speed: ";
    cin >> speed;
    cout << "Enter seating capacity: ";
    cin >> seats;
    cout << "Enter battery life: ";
    cin >> batteryLife;
    
    ElectricCar eCar(brand, speed, seats, batteryLife);
    cout << "-----------------" << endl;
    eCar.displayDetails();
    
    return 0;
}
