#ifndef ELECTRICCAR_H
#define ELECTRICCAR_H

#include "Car.h"
#include <iostream>

class ElectricCar : public Car {
private:
    int batteryRange;

public:
    ElectricCar(const std::string& b, int y, int d, int br)
        : Car(b, y, d), batteryRange(br) {}

    void displayInfo() override {
        Car::displayInfo();
        std::cout << "Battery Range: " << batteryRange << " km" << std::endl;
    }

    ~ElectricCar() override {
        std::cout << "Electric car is destroyed" << std::endl;
    }
};

#endif