#include <iostream>
using namespace std;

class Distance {
private:
    int meters;
    double centimeters;

    void normalize() {
        while (centimeters >= 100.0) {
            centimeters -= 100.0;
            meters += 1;
        }
        while (centimeters < 0) {
            centimeters += 100.0;
            meters -= 1;
        }
    }

public:
    Distance() : meters(0), centimeters(0.0) {
    }

    Distance(int m, double cm) : meters(m), centimeters(cm) {
        normalize();
    }

    void get_data() {
        cout << "Enter meters: ";
        cin >> meters;
        cout << "Enter centimeters: ";
        cin >> centimeters;
        normalize();
    }

    void show_data() const {
        cout << meters << " meters and " << centimeters << " centimeters" << endl;
    }

    Distance &operator++() {
        centimeters += 1.0;
        normalize();
        return *this;
    }

    Distance operator++(int) {
        Distance temp = *this;
        centimeters += 1.0;
        normalize();
        return temp;
    }

    Distance &operator--() {
        centimeters -= 1.0;
        normalize();
        return *this;
    }

    Distance operator--(int) {
        Distance temp = *this;
        centimeters -= 1.0;
        normalize();
        return temp;
    }

    Distance operator+(const Distance &rhs) const {
        Distance result;
        result.meters = meters + rhs.meters;
        result.centimeters = centimeters + rhs.centimeters;
        result.normalize();
        return result;
    }

    Distance operator-(const Distance &rhs) const {
        Distance result;
        result.meters = meters - rhs.meters;
        result.centimeters = centimeters - rhs.centimeters;
        result.normalize();
        return result;
    }

    Distance operator*(const Distance &rhs) const {
        double total_cm1 = meters * 100.0 + centimeters;
        double total_cm2 = rhs.meters * 100.0 + rhs.centimeters;
        double product_cm = total_cm1 * total_cm2;

        Distance result;
        result.meters = static_cast<int>(product_cm) / 100;
        result.centimeters = product_cm - (result.meters * 100);
        result.normalize();
        return result;
    }

    bool operator==(const Distance &rhs) const {
        return (meters == rhs.meters) && (centimeters == rhs.centimeters);
    }

    Distance &operator+=(const Distance &rhs) {
        meters += rhs.meters;
        centimeters += rhs.centimeters;
        normalize();
        return *this;
    }

    Distance &operator-=(const Distance &rhs) {
        meters -= rhs.meters;
        centimeters -= rhs.centimeters;
        normalize();
        return *this;
    }

    Distance &operator*=(const Distance &rhs) {
        double total_cm1 = meters * 100.0 + centimeters;
        double total_cm2 = rhs.meters * 100.0 + rhs.centimeters;
        double product_cm = total_cm1 * total_cm2;

        meters = static_cast<int>(product_cm) / 100;
        centimeters = product_cm - (meters * 100);
        normalize();
        return *this;
    }
};

int main() {
    Distance d1(2, 75), d2(3, 50), d3;
    cout << "Initial Distances:\n";
    d1.show_data();
    d2.show_data();

    cout << "\nTesting + operator:\n";
    d3 = d1 + d2;
    d3.show_data();

    cout << "\nTesting - operator:\n";
    d3 = d1 - d2;
    d3.show_data();

    cout << "\nTesting * operator:\n";
    d3 = d1 * d2;
    d3.show_data();

    cout << "\nTesting prefix ++:\n";
    ++d1;
    d1.show_data();

    cout << "\nTesting postfix ++:\n";
    d1++;
    d1.show_data();

    cout << "\nTesting prefix --:\n";
    --d2;
    d2.show_data();

    cout << "\nTesting postfix --:\n";
    d2--;
    d2.show_data();

    cout << "\nTesting == operator:\n";
    if (d1 == d2)
        cout << "Equal distances\n";
    else
        cout << "Not equal\n";

    cout << "\nTesting +=, -=, *= operators:\n";
    d1 += d2;
    d1.show_data();
    d1 -= d2;
    d1.show_data();
    d1 *= d2;
    d1.show_data();

    return 0;
}
