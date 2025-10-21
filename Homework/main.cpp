#include <iostream>
#include "Vehicle.h"
#include "Car.h"
#include "ElectricCar.h"
using namespace std;

int main() {
    cout << "--- Creating Vehicle ---" << endl;
    Vehicle v("Li", 2025);
    v.displayInfo();

    cout << "\n--- Creating Car ---" << endl;
    Car c("Cobalt", 2023, 4);
    c.displayInfo();

    cout << "\n--- Creating Electric Car ---" << endl;
    ElectricCar e("Gentra", 2024, 4, 550);
    e.displayInfo();

    Vehicle* ptr;
    ptr = &c;
    ptr->displayInfo();
    ptr = &e;
    ptr->displayInfo();

    cout << "\nTotal number of vehicles created is " << Vehicle::getTotal() << endl;

    return 0;
}