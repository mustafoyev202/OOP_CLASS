#include <iostream>
using namespace std;

class Instrument {
protected:
    string name;
    string type;

public:
    Instrument(string name, string type) : name(name), type(type) {
    }

    virtual void play() {
        cout << "Playing a generic instrument sound...\n";
    }

    // virtual ~Instrument() {
    // }
};

class Guitar : public Instrument {
private:
    int strings;

public:
    Guitar(string name, string type, int strings)
        : Instrument(name, type), strings(strings) {
    }

    void play() override {
        cout << "Strumming a guitar with " << strings << " strings." << endl;
    }
};

class Drum : public Instrument {
private:
    double diameter;

public:
    Drum(string name, string type, double diameter)
        : Instrument(name, type), diameter(diameter) {
    }

    void play() override {
        cout << "Beating a drum of diameter " << diameter << " cm." << endl;
    }
};

class Flute : public Instrument {
private:
    string material;

public:
    Flute(string name, string type, string material)
        : Instrument(name, type), material(material) {
    }

    void play() override {
        cout << "Blowing a flute made of " << material << "." << endl;
    }
};

int main() {
    Instrument *orchestra[3];

    orchestra[0] = new Guitar("Guitar", "String", 6);
    orchestra[1] = new Drum("Drum", "Percussion", 40.5);
    orchestra[2] = new Flute("Flute", "Wind", "Bamboo");

    for (int i = 0; i < 3; i++)
        orchestra[i]->play();

    // for (int i = 0; i < 3; i++)
    //     delete orchestra[i];

    return 0;
}
