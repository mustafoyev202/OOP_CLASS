#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <iostream>

class Vehicle {
private:
    std::string brand;
    int year;
    static int totalVehicles;

public:
    Vehicle(const std::string& b, int y) : brand(b), year(y) {
        totalVehicles++;
    }

    void displayInfo() {
        std::cout << "Brand: " << brand << std::endl;
        std::cout << "Year: " << year << std::endl;
    }

    static int getTotal() {
        return totalVehicles;
    }

    virtual ~Vehicle() {
        std::cout << "Vehicle is destroyed" << std::endl;
    }
};

// Initialize static member
int Vehicle::totalVehicles = 0;

#endif