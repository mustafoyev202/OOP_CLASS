#include <iostream>
using namespace std;

template <typename T>
T power(T base, int exp) {
    if (exp == 0)
        return 1;
    return base * power(base, exp - 1);
}

int main() {
    double base;
    int exp;
    cin >> base >> exp;
    cout << power(base, exp) << endl;
    return 0;
}
