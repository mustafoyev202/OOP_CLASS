#include <iostream>
#include <vector>
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

    void displayPerson() const {
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
    Student() : gpa(0.0) {
        cout << "Default constructor of Student is called" << endl;
    }

    Student(int id, string name, int age, float gpa) : Person(id, name, age), gpa(gpa) {
        cout << "Student constructor is called" << endl;
    }

    void setGPA(float gpa) {
        this->gpa = gpa;
    }

    void displayStudent() const {
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
    Teacher() : subject("") {
        cout << "Default constructor of Teacher is called" << endl;
    }

    Teacher(int id, string name, int age, string subject) : Person(id, name, age), subject(subject) {
        cout << "Teacher constructor is called" << endl;
    }

    void setSubject(string subject) {
        this->subject = subject;
    }

    void showRole() const {
        cout << "I am a Teacher, Subject: " << subject << endl;
    }

    void displayTeacher() const {
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
    TeachingAssistant() : hoursPerWeek(0) {
        cout << "Default constructor of TeachingAssistant is called" << endl;
    }

    TeachingAssistant(string name, int age, int id, float gpa, string subject, int hoursPerWeek)
        : Person(id, name, age), Student(id, name, age, gpa), Teacher(id, name, age, subject),
          hoursPerWeek(hoursPerWeek) {
        cout << "TeachingAssistant constructor is called" << endl;
    }

    void setTAInfo(int hoursPerWeek) {
        this->hoursPerWeek = hoursPerWeek;
    }

    void displayTA() const {
        displayPerson();
        cout << "GPA: " << gpa << endl;
        showRole();
        cout << "Hours per Week: " << hoursPerWeek << endl;
    }

    ~TeachingAssistant() {
        cout << "TeachingAssistant destructor is called" << endl;
    }
};

class Course {
private:
    Teacher courseTeacher;
    vector<Student *> students;

public:
    Course() {
        cout << "Default constructor of Course is called" << endl;
    }

    ~Course() {
        cout << "Course destructor is called" << endl;
    }

    void setCourseTeacher(string name, int age, int id, string subject) {
        courseTeacher.setName(name);
        courseTeacher.setAge(age);
        courseTeacher.setID(id);
        courseTeacher.setSubject(subject);
    }

    void addStudent(Student *student) {
        students.push_back(student);
    }

    void displayCourse() const {
        cout << "Course Teacher: " << endl;
        courseTeacher.displayTeacher();

        cout << "\nEnrolled Students: " << endl;
        for (auto student: students) {
            cout << "----------------" << endl;
            student->displayStudent();
        }
    }
};

int main() {
    Course oopCourse;
    oopCourse.setCourseTeacher("Dr. Smith", 40, 2001, "Object-Oriented Programming");

    Student *s1 = new Student(1001, "Alice", 20, 3.8);
    Student *s2 = new Student(1002, "Bob", 22, 3.6);
    Student *s3 = new Student(1003, "Charlie", 21, 3.9);

    oopCourse.addStudent(s1);
    oopCourse.addStudent(s2);
    oopCourse.addStudent(s3);

    oopCourse.displayCourse();
    delete s1;
    delete s2;
    delete s3;

    return 0;
}
