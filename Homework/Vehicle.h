#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
using namespace std;

class Vehicle {
protected:
    string brand;
    int year;
    static int totalVehicles;
public:
    Vehicle() : brand("Unknown"), year(0) { totalVehicles++; }
    Vehicle(string b, int y) : brand(b), year(y) { totalVehicles++; }

    virtual void displayInfo() {
        cout << "Brand: " << brand << "\nYear: " << year << endl;
    }

    static int getTotal() { return totalVehicles; }

    virtual ~Vehicle() {
        cout << "Vehicle is destroyed" << endl;
    }
};

#endif