#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << (a & b) << " "
         << (a | b) << " "
         << ((~a) & b) << " "
         << (b ^ a) << " "
         << (a << 2) << " "
         << (b >> 3) << endl;
    return 0;
}
