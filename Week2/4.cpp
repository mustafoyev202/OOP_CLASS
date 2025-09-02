#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    srand(time(0));
    int secret = 1 + rand() % 15;
    int guess;
    string response;

    while (true) {
        cin >> guess;
        if (guess == secret) {
            cout << "You won!" << endl;
            break;
        } else {
            cout << "NO! Want to continue?" << endl;
            cin >> response;
            transform(response.begin(), response.end(), response.begin(), ::tolower);
            if (response == "yes") {
                continue;
            } else {
                break;
            }
        }
    }

    return 0;
}