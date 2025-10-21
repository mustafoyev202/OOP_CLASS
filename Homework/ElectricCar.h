#ifndef ELECTRICCAR_H
#define ELECTRICCAR_H

#include "Car.h"

class ElectricCar : public Car {
private:
    int batteryRange;
public:
    ElectricCar() : Car(), batteryRange(0) {}
    ElectricCar(string b, int y, int d, int br) : Car(b, y, d), batteryRange(br) {}

    void displayInfo() {
        cout << "Brand: " << brand
             << "\nYear: " << year
             << "\nDoors: " << doors
             << "\nBattery Range: " << batteryRange << " km" << endl;
    }

    ~ElectricCar() {
        cout << "Electric car is destroyed" << endl;
    }
};

#endif