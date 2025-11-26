#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

double safeSqrt(double x) {
    if (x < 0) {
        throw domain_error("Square root of negative number");
    }
    return sqrt(x);
}

int main() {
    try {
        cout << "safeSqrt(25) = " << safeSqrt(25) << endl;
    } catch (domain_error &e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        cout << "safeSqrt(-9) = " << safeSqrt(-9) << endl;
    } catch (domain_error &e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
