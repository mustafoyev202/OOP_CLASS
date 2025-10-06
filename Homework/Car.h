#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"
#include <iostream>

class Car : public Vehicle {
private:
    int doors;

public:
    Car(const std::string& b, int y, int d) : Vehicle(b, y), doors(d) {}

    void displayInfo() override {
        Vehicle::displayInfo();
        std::cout << "Doors: " << doors << std::endl;
    }

    ~Car() override {
        std::cout << "Car is destroyed" << std::endl;
    }
};

#endif