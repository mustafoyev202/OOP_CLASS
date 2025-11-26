#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

int main() {
    vector<int> vec = {10, 20, 30, 40, 50};

    int index;
    cout << "Enter an index: ";
    cin >> index;

    try {
        int value = vec.at(index);
        cout << "Value at index " << index << " is: " << value << endl;
    } catch (out_of_range &e) {
        cout << "Index error: " << e.what() << endl;
    }

    return 0;
}
