#include <iostream>
using namespace std;

class Device {
protected:
    int deviceID;
    bool status;

public:
    Device(int id, bool st) : deviceID(id), status(st) {}
    virtual void displayDetails() {
        cout << "Device ID: " << deviceID << "\nStatus: " << (status ? "On" : "Off") << endl;
    }
};

class SmartPhone : public Device {
protected:
    float screenSize;

public:
    SmartPhone(int id, bool st, float ss) : Device(id, st), screenSize(ss) {}
    void displayDetails() override {
        cout << "Device ID: " << deviceID << "\nStatus: " << (status ? "On" : "Off")
             << "\nScreen Size: " << screenSize << " inches" << endl;
    }
};

class SmartWatch : public Device {
protected:
    bool heartRateMonitor;

public:
    SmartWatch(int id, bool st, bool hrm) : Device(id, st), heartRateMonitor(hrm) {}
    void displayDetails() override {
        cout << "Device ID: " << deviceID << "\nStatus: " << (status ? "On" : "Off")
             << "\nHeart Rate Monitor: " << (heartRateMonitor ? "Yes" : "No") << endl;
    }
};

class SmartWearable : public SmartPhone, public SmartWatch {
private:
    int stepCounter;

public:
    SmartWearable(int id, bool st, float ss, bool hrm, int sc) 
        : Device(id, st), SmartPhone(id, st, ss), SmartWatch(id, st, hrm), stepCounter(sc) {}
    void displayDetails() override {
        cout << "Device ID: " << deviceID << "\nStatus: " << (status ? "On" : "Off")
             << "\nScreen Size: " << screenSize << " inches"
             << "\nHeart Rate Monitor: " << (heartRateMonitor ? "Yes" : "No")
             << "\nStep Counter: " << stepCounter << " steps" << endl;
    }
};

int main() {
    int deviceID, stepCounter;
    bool status, heartRateMonitor;
    float screenSize;
    
    cout << "Enter Smart Wearable details:\n";
    cout << "Device ID: ";
    cin >> deviceID;
    cout << "Status (1 for On, 0 for Off): ";
    cin >> status;
    cout << "Screen Size (in inches): ";
    cin >> screenSize;
    cout << "Heart Rate Monitor (1 for Yes, 0 for No): ";
    cin >> heartRateMonitor;
    cout << "Step Counter: ";
    cin >> stepCounter;
    
    SmartWearable wearable(deviceID, status, screenSize, heartRateMonitor, stepCounter);
    cout << "\n-----------------\n";
    wearable.displayDetails();
    
    return 0;
}
