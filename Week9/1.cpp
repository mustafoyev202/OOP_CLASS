#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;

    void normalize() {
        if (minutes >= 60) {
            hours += minutes / 60;
            minutes = minutes % 60;
        } else if (minutes < 0) {
            int borrow = (abs(minutes) + 59) / 60;
            hours -= borrow;
            minutes += borrow * 60;
        }
        if (hours < 0) hours = 0;
    }

public:
    Time() : hours(0), minutes(0) {
    }

    Time(int h, int m) : hours(h), minutes(m) {
        normalize();
    }

    Time& operator++() {
        minutes++;
        normalize();
        return *this;
    }

    Time operator++(int) {
        Time temp = *this;
        minutes++;
        normalize();
        return temp;
    }

    Time& operator--() {
        minutes--;
        normalize();
        return *this;
    }

    Time operator--(int) {
        Time temp = *this;
        minutes--;
        normalize();
        return temp;
    }

    Time operator+(const Time& other) const {
        Time temp(hours + other.hours, minutes + other.minutes);
        temp.normalize();
        return temp;
    }

    Time operator-(const Time& other) const {
        Time temp(hours - other.hours, minutes - other.minutes);
        temp.normalize();
        return temp;
    }

    Time operator*(const Time& other) const {
        int total1 = hours * 60 + minutes;
        int total2 = other.hours * 60 + other.minutes;
        int product = total1 * total2;
        Time temp(0, product);
        temp.normalize();
        return temp;
    }

    bool operator==(const Time& other) const {
        return (hours == other.hours && minutes == other.minutes);
    }

    Time& operator+=(const Time& other) {
        hours += other.hours;
        minutes += other.minutes;
        normalize();
        return *this;
    }

    Time& operator-=(const Time& other) {
        hours -= other.hours;
        minutes -= other.minutes;
        normalize();
        return *this;
    }

    Time& operator*=(const Time& other) {
        int total1 = hours * 60 + minutes;
        int total2 = other.hours * 60 + other.minutes;
        int product = total1 * total2;
        hours = 0;
        minutes = product;
        normalize();
        return *this;
    }

    friend istream& operator>>(istream& in, Time& t) {
        cout << "Enter hours and minutes: ";
        in >> t.hours >> t.minutes;
        t.normalize();
        return in;
    }

    friend ostream& operator<<(ostream& out, const Time& t) {
        out << "Hours: " << t.hours << ", Minutes: " << t.minutes;
        return out;
    }
};


int main() {
    Time t1(2, 45), t2(1, 30), t3;

    cout << "Initial Times:\n";
    cout << t1 << endl;
    cout << t2 << endl;

    cout << "\nTesting input operator >> :\n";
    cout << "Enter a new time (hours and minutes): ";
    cin >> t3;
    cout << "You entered: " << t3 << endl;

    cout << "\nTesting + operator:\n";
    t3 = t1 + t2;
    cout << t3 << endl;

    cout << "\nTesting - operator:\n";
    t3 = t1 - t2;
    cout << t3 << endl;

    cout << "\nTesting * operator:\n";
    t3 = t1 * t2;
    cout << t3 << endl;

    cout << "\nTesting prefix ++ and postfix ++:\n";
    ++t1;
    cout << t1 << endl;
    t1++;
    cout << t1 << endl;

    cout << "\nTesting prefix -- and postfix --:\n";
    --t2;
    cout << t2 << endl;
    t2--;
    cout << t2 << endl;

    cout << "\nTesting == operator:\n";
    if (t1 == t2)
        cout << "Equal times\n";
    else
        cout << "Not equal\n";

    cout << "\nTesting +=, -=, *= operators:\n";
    t1 += t2;
    cout << t1 << endl;
    t1 -= t2;
    cout << t1 << endl;
    t1 *= t2;
    cout << t1 << endl;

    return 0;
}
