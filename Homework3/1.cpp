#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

int safeAccess(const vector<int> &v, int index) {
    try {
        return v.at(index);
    } catch (const out_of_range &e) {
        cout << "Index out of range!" << endl;
        return -1;
    }
}

int main() {
    vector<int> v = {1, 3, 3, 4, 5, 6};
    int index;

    cout << "Enter index: ";
    cin >> index;

    cout << safeAccess(v, index) << endl;

    return 0;
}
