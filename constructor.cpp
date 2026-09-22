#include <iostream>
using namespace std;

class Student {
    int roll;
    string name;

public:

    // 1. Default Constructor
    Student() {
        roll = 0;
        name = "Unknown";
        cout << "Default Constructor" << endl;
    }

    // 2. Parameterized Constructor
    Student(int r, string n) {
        roll = r;
        name = n;
        cout << "Parameterized Constructor" << endl;
    }

    // 3. Copy Constructor
    Student(const Student &s) {
        roll = s.roll;
        name = s.name;
        cout << "Copy Constructor" << endl;
    }

    void display() {
        cout << "Roll: " << roll << endl;
        cout << "Name: " << name << endl;
    }
};

int main() {

    // Default constructor
    Student s1;
    s1.display();

    cout << endl;

    // Parameterized constructor
    Student s2(101, "Rahul");
    s2.display();

    cout << endl;

    // Copy constructor
    Student s3(s2);
    s3.display();

    return 0;
}
