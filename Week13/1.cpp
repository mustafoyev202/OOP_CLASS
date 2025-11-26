#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cout << "Enter N: ";
    cin >> N;

    vector<int> v(N);
    cout << "Enter numbers: ";
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    int value;
    cout << "Enter value to search: ";
    cin >> value;

    if (find(v.begin(), v.end(), value) != v.end()) {
        cout << "Found!" << endl;
    } else {
        cout << "Not found!" << endl;
    }

    int occurrences = count(v.begin(), v.end(), value);
    cout << "Count = " << occurrences << endl;

    sort(v.begin(), v.end());

    cout << "Sorted vector: ";
    for (int x: v) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
