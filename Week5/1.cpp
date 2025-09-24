#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    int age;

    Person() : name("NA"), age(0) {}

    Person(string n, int a) : name(n), age(a) {}

    virtual void introduce() {
        cout << "My name is " << name << " and I am " << age << " years old." << endl;
    }

    void haveBirthday() {
        age++;
        cout << "Happy Birthday! " << name << " is now " << age << " years old." << endl;
    }

    ~Person() {
        cout << "Person " << name << " is being destroyed." << endl;
    }
};

class Student : public Person {
private:
    string university;

public:
    Student(string n, int a, string uni) : Person(n, a), university(uni) {
        cout << "A student has been created: " << name << endl;
    }

    void introduce() override {
        Person::introduce();
        cout << "Hi, I am " << name << ", a " << age << "-year-old student at " << university << "." << endl;
    }

    void study() {
        cout << name << " is studying at " << university << "." << endl;
    }
};

int main() {
    Person person("John", 25);
    person.introduce();
    person.haveBirthday();
    Student s("Alice", 20, "NUU");
    s.introduce();
    s.study();
    s.haveBirthday();

    return 0;
}
