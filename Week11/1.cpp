#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    int num1, num2;
    char operation;

    cout << "Enter two integers: ";
    cin >> num1 >> num2;

    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;

    try {
        double result;

        switch (operation) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 == 0)
                    throw runtime_error("Error: Division by zero.");
                result = static_cast<double>(num1) / num2;
                break;
            default:
                throw invalid_argument("Error: Unknown operation.");
        }

        cout << "Result: " << result << endl;
    } catch (const runtime_error &e) {
        cerr << e.what() << endl;
    } catch (const invalid_argument &e) {
        cerr << e.what() << endl;
    }

    return 0;
}
