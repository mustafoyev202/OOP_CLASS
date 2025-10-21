#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle {
protected:
    int doors;
public:
    Car() : Vehicle(), doors(0) {}
    Car(string b, int y, int d) : Vehicle(b, y), doors(d) {}

    void displayInfo() {
        cout << "Brand: " << brand
             << "\nYear: " << year
             << "\nDoors: " << doors << endl;
    }

    ~Car() {
        cout << "Car is destroyed" << endl;
    }
};

#endif