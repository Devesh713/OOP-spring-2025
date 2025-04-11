#include <iostream>

using namespace std;

class Humidity;

class Temperature 
{
private:
    float tempC;

public:
    Temperature(float t) : tempC(t) {}

    friend float calculateHeatIndex(const Temperature&, const Humidity&);
};

class Humidity 
{
private:
    float humidityPercent;

public:
    Humidity(float h) : humidityPercent(h) {}

    friend float calculateHeatIndex(const Temperature&, const Humidity&);
};

float calculateHeatIndex(const Temperature& t, const Humidity& h) 
{
    float heatIndex = t.tempC + 0.1f * h.humidityPercent;
    return heatIndex;
}

int main() 
{
    Temperature temp(28.5f);
    Humidity hum(55.0f);

    float heatIndex = calculateHeatIndex(temp, hum);
    cout << "Calculated Heat Index: " << heatIndex << " Celsius" << endl;

    return 0;
}
