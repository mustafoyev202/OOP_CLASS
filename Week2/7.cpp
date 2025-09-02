#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int rolls = 1000;
    int count[6] = {0};

    for (int i = 0; i < rolls; i++) {
        int face = rand() % 6;
        count[face]++;
    }

    for (int i = 0; i < 6; i++) {
        cout << "Face " << i + 1 << ": " << count[i] << " times" << endl;
    }

    return 0;
}
