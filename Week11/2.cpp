#include <iostream>
using namespace std;

template<typename T>
T maxOfThree(T a, T b, T c) {
    T maxVal = a;
    if (b > maxVal) maxVal = b;
    if (c > maxVal) maxVal = c;
    return maxVal;
}

int main() {
    int x = 10, y = 25, z = 15;
    cout << "Max of ints: " << maxOfThree(x, y, z) << endl;

    double d1 = 4.5, d2 = 9.2, d3 = 7.8;
    cout << "Max of doubles: " << maxOfThree(d1, d2, d3) << endl;

    char c1 = 'a', c2 = 'z', c3 = 'm';
    cout << "Max of chars: " << maxOfThree(c1, c2, c3) << endl;

    return 0;
}
