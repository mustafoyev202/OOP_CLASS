#include <iostream>
using namespace std;

class Person {
private:
    int nationalID;

protected:
    string name;
    int age;

public:
    Person() {
        cout << "Default constructor of Person is called" << endl;
    }

    Person(int id, string name, int age) {
        nationalID = id;
        this->name = name;
        this->age = age;
        cout << "Person constructor is called" << endl;
    }

    void setName(string name) {
        this->name = name;
    }

    void setAge(int age) {
        this->age = age;
    }

    void setID(int id) {
        nationalID = id;
    }

    void displayPerson() {
        cout << "Name: " << name << " Age: " << age << " ID: " << nationalID << endl;
    }

    virtual ~Person() {
        cout << "Person destructor is called" << endl;
    }
};

class Student : virtual public Person {
protected:
    float gpa;

public:
    Student() {
        cout << "Default constructor of Student is called" << endl;
    }

    Student(int id, string name, int age, float gpa) : Person(id, name, age), gpa(gpa) {
        cout << "Student constructor is called" << endl;
    }

    void setGPA(float gpa) {
        this->gpa = gpa;
    }

    void displayStudent() {
        displayPerson();
        cout << "GPA: " << gpa << endl;
    }

    ~Student() {
        cout << "Student destructor is called" << endl;
    }
};

class Teacher : virtual public Person {
private:
    string subject;

public:
    Teacher() {
        cout << "Default constructor of Teacher is called" << endl;
    }

    Teacher(int id, string name, int age, string subject) : Person(id, name, age), subject(subject) {
        cout << "Teacher constructor is called" << endl;
    }

    void setSubject(string subject) {
        this->subject = subject;
    }

    void showRole() {
        cout << "I am a Teacher, Subject: " << subject << endl;
    }

    void displayTeacher() {
        displayPerson();
        cout << "Subject: " << subject << endl;
    }

    ~Teacher() {
        cout << "Teacher destructor is called" << endl;
    }
};

class TeachingAssistant : public Student, public Teacher {
private:
    int hoursPerWeek;

public:
    TeachingAssistant() {
        cout << "Default constructor of TeachingAssistant is called" << endl;
    }

    TeachingAssistant(string name, int age, int id, float gpa, string subject,
                      int hoursPerWeek)
        : Person(id, name, age), Student(id, name, age, gpa), Teacher(id, name, age, subject),
          hoursPerWeek(hoursPerWeek) {
        cout << "TeachingAssistant constructor is called" << endl;
    }

    void setTAInfo(int hoursPerWeek) {
        this->hoursPerWeek = hoursPerWeek;
    }

    void displayTA() {
        displayPerson();
        cout << "GPA: " << gpa << endl;
        showRole();
        cout << "HoursPerWeek: " << hoursPerWeek << endl;
    }

    ~TeachingAssistant() {
        cout << "TeachingAssistant destructor is called" << endl;
    }
};

int main() {
    TeachingAssistant ta("Alice", 25, 123456, 3.8, "Computer Science", 15);
    cout << "\nDisplaying TA Information:\n";
    ta.displayTA();

    cout << "\nProgram ends, destructors will now be called:\n";
    return 0;
}
