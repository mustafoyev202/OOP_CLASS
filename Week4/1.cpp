#include <iostream>
#include <string>
using namespace std;

class Course {
private:
    string title;
    string code;
    int credits;

public:
    Course() {
        title = "Unknown";
        code = "0000";
        credits = 0;
    }

    Course(string title, string code, int credits) {
        this->title = title;
        this->code = code;
        this->credits = credits;
    }

    void set_title(string t) { title = t; }
    void set_code(string c) { code = c; }
    void set_credits(int cr) { credits = cr; }

    string get_title() { return title; }
    string get_code() { return code; }
    int get_credits() { return credits; }

    void display() {
        cout << "Course: " << title << endl;
        cout << "Code: " << code << endl;
        cout << "Credits: " << credits << endl;
    }
};

class Student {
private:
    string name;
    int id;
    double gpa;
    string department;
    Course enrolledCourse;

public:
    Student() {
        name = "No name";
        id = 0;
        gpa = 0.0;
        department = "NA";
    }

    Student(string name, int id, double gpa, string department) {
        this->name = name;
        this->id = id;
        this->gpa = gpa;
        this->department = department;
    }

    void set_name(string n) { name = n; }
    void set_id(int i) { id = i; }
    void set_gpa(double g) { gpa = g; }
    void set_department(string d) { department = d; }
    void set_course(Course c) { enrolledCourse = c; }

    string get_name() { return name; }
    int get_id() { return id; }
    double get_gpa() { return gpa; }
    string get_department() { return department; }
    Course get_course() { return enrolledCourse; }

    void display() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "GPA: " << gpa << endl;
        cout << "Department: " << department << endl;
        cout << "Enrolled course:" << endl;
        enrolledCourse.display();
    }
};

int main() {
    Student student1;
    Student student2("Baxtiyor", 23002, 3.8, "Computer Science");

    cout << "=== Part 1: Students ===" << endl;
    student1.display();
    cout << endl;
    student2.display();

    Course course1;
    Course course2("Calculus I", "Math203", 3);

    cout << "\nPart 2: Courses" << endl;
    course1.display();
    cout << endl;
    course2.display();

    Course favoriteCourse("Data Structures", "CS201", 4);
    student2.set_course(favoriteCourse);

    cout << "\nPart 3: Student with Enrolled Course" << endl;
    student2.display();

    student1.set_name("Abror");
    student1.set_id(45678);
    student1.set_gpa(3.5);
    student1.set_department("Mathematics");
    student1.set_course(Course("Linear Algebra", "Math205", 3));

    cout << "\nPart 4: Updated Default Student" << endl;
    cout << "Name: " << student1.get_name() << endl;
    cout << "ID: " << student1.get_id() << endl;
    cout << "GPA: " << student1.get_gpa() << endl;
    cout << "Department: " << student1.get_department() << endl;
    cout << "Enrolled course:" << endl;
    student1.get_course().display();

    return 0;
}