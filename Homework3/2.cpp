#include <iostream>
using namespace std;

template<typename T, typename U>
class PairHolder {
public:
    T first;
    U second;

    PairHolder(T f, U s) : first(f), second(s) {
    }

    T get_first() {
        return first;
    }

    U get_second() {
        return second;
    }

    bool isSame(const PairHolder<T, U> &other) {
        return first == other.first && second == other.second;
    }
};

int main() {
    PairHolder<int, double> P(10, 20.1);
    cout << "First value: " << P.get_first() << endl;
    cout << "Second value: " << P.get_second() << endl;

    int a;
    cout << "Enter first value for the second pair: ";
    cin >> a;

    double b;
    cout << "Enter second value for the second pair: ";
    cin >> b;

    PairHolder<int, double> oth(a, b);

    cout << "Are the pairs the same? " << (P.isSame(oth) ? "Yes" : "No") << endl;

    return 0;
}
