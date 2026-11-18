
#include <iostream>
using namespace std;

// Base Class
class Person
{
public:
    string name;

    void getPerson()
    {
        cout << "Enter name: ";
        cin >> name;
    }
};

// Derived Class
class Student : public Person
{
public:
    int rollNo;

    void getStudent()
    {
        cout << "Enter roll number: ";
        cin >> rollNo;
    }
};

// Multilevel Derived Class
class GraduateStudent : public Student
{
public:
    string course;

    void getDetails()
    {
        cout << "Enter course: ";
        cin >> course;
    }

    void display()
    {
        cout << "\nName: " << name;
        cout << "\nRoll Number: " << rollNo;
        cout << "\nCourse: " << course << endl;
    }
};

int main()
{
    GraduateStudent g;

    g.getPerson();
    g.getStudent();
    g.getDetails();

    cout << "\nStudent Details";
    g.display();

    return 0;
}
