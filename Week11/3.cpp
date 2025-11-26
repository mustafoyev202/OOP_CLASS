#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

template<typename T>
class Box {
private:
    T first, second, third;

public:
    Box(T a, T b, T c) : first(a), second(b), third(c) {
    }

    void set(int index, T value) {
        switch (index) {
            case 0: first = value;
                break;
            case 1: second = value;
                break;
            case 2: third = value;
                break;
            default: throw out_of_range("Invalid index.");
        }
    }

    T get(int index) const {
        switch (index) {
            case 0: return first;
            case 1: return second;
            case 2: return third;
            default: throw out_of_range("Invalid index.");
        }
    }

    T sum() const {
        return first + second + third;
    }

    void display() const {
        cout << "Values: " << first << " " << second << " " << third << endl;
    }
};

int main() {
    Box<int> b1(3, 5, 7);
    b1.display();
    cout << "Sum = " << b1.sum() << endl;

    Box<double> b2(2.5, 4.0, 3.5);
    b2.display();
    cout << "Sum = " << b2.sum() << endl;

    Box<string> b3("Hi", " ", "there");
    b3.display();
    cout << "Sum = " << b3.sum() << endl;

    try {
        cout << b1.get(5) << endl;
    } catch (const exception &e) {
        cout << "Caught: " << e.what() << endl;
    }

    return 0;
}
