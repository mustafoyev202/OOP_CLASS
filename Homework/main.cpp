#include <iostream>
#include "Vehicle.h"
#include "Car.h"
#include "ElectricCar.h"

using namespace std;

int main() {
    // Creating Vehicle objects
    Vehicle v1("Toyota", 2020);
    Vehicle v2("Honda", 2021);

    // Displaying information of vehicles
    cout << "Vehicle 1 Info:" << endl;
    v1.displayInfo();
    cout << "Vehicle 2 Info:" << endl;
    v2.displayInfo();

    // Creating Car objects
    Car c1("Ford", 2022, 4);
    Car c2("BMW", 2023, 2);

    // Displaying information of cars
    cout << "\nCar 1 Info:" << endl;
    c1.displayInfo();
    cout << "Car 2 Info:" << endl;
    c2.displayInfo();

    // Creating ElectricCar objects
    ElectricCar e1("Tesla", 2024, 4, 350);
    ElectricCar e2("Nissan", 2025, 5, 400);

    // Displaying information of electric cars
    cout << "\nElectric Car 1 Info:" << endl;
    e1.displayInfo();
    cout << "Electric Car 2 Info:" << endl;
    e2.displayInfo();

    // Displaying total number of vehicles created
    cout << "\nTotal Vehicles Created: " << Vehicle::getTotal() << endl;

    return 0;
}
