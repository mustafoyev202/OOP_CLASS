#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    double x, y, z;
    cin >> x >> y >> z;
    vector<double> arr = {x, y, z};
    sort(arr.begin(), arr.end());
    cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
    return 0;
}