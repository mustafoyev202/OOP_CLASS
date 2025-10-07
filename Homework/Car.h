#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle {
private:
    int doors;

public:
    // Constructor
    Car(string b, int y, int d) : Vehicle(b, y), doors(d) {}

    // Override displayInfo() to print Car-specific details
    void displayInfo() const override {
        Vehicle::displayInfo();  // Call the base class displayInfo()
        cout << "Doors: " << doors << endl;
    }

    // Destructor
    ~Car() override {
        cout << "Car is destroyed" << endl;
    }
};

#endif
