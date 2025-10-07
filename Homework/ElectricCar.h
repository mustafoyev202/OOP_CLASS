#ifndef ELECTRICCAR_H
#define ELECTRICCAR_H

#include "Car.h"

class ElectricCar : public Car {
private:
    int batteryRange;

public:
    // Constructor
    ElectricCar(string b, int y, int d, int br) : Car(b, y, d), batteryRange(br) {}

    // Override displayInfo() to print ElectricCar-specific details
    void displayInfo() const override {
        Car::displayInfo();  // Call the base class displayInfo()
        cout << "Battery Range: " << batteryRange << " km" << endl;
    }

    // Destructor
    ~ElectricCar() override {
        cout << "Electric car is destroyed" << endl;
    }
};

#endif
