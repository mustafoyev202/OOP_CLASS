#include <iostream>
using namespace std;

class MusicRecord {
private:
    string title;
    int duration;

public:
    MusicRecord() : title(""), duration(0) {
    }

    MusicRecord(string t, int d) : title(t), duration(d) {
    }

    MusicRecord(const MusicRecord& other) {
        cout << "Copy constructor called" << endl;
        title = other.title;
        duration = other.duration;
    }

    MusicRecord& operator=(const MusicRecord& other) {
        cout << "Assignment operator called" << endl;
        if (this != &other) {
            title = other.title;
            duration = other.duration;
        }
        return *this;
    }

    void display() const {
        cout << "Title: " << title << ", Duration: " << duration << " seconds" << endl;
    }
};

int main() {
    MusicRecord r1("Bohemian Rhapsody", 354);
    MusicRecord r2 = r1;
    MusicRecord r3;
    r3 = r1;

    r1.display();
    r2.display();
    r3.display();

    return 0;
}
