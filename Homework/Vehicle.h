#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>
using namespace std;

class Vehicle {
private:
    string brand;
    int year;
    static int totalVehicles;

public:
    // Constructor
    Vehicle(string b, int y) : brand(b), year(y) {
        totalVehicles++;  // Increment the total vehicles count
    }

    // Method to display information
    virtual void displayInfo() const {
        cout << "Brand: " << brand << endl;
        cout << "Year: " << year << endl;
    }

    // Getter for totalVehicles
    static int getTotal() {
        return totalVehicles;
    }

    // Destructor
    virtual ~Vehicle() {
        cout << "Vehicle is destroyed" << endl;
    }
};

// Initialize the static variable
int Vehicle::totalVehicles = 0;

#endif
