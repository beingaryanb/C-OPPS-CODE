#include <iostream>
using namespace std;

class Student {
    int roll;
    string name;

public:

    // 1. Default constructor
    Student() {
        roll = 0;
        name = "Unknown";
    }

    // 2. One parameter
    Student(int r) {
        roll = r;
        name = "Unknown";
    }

    // 3. Two parameters
    Student(int r, string n) {
        roll = r;
        name = n;
    }

    void display() {
        cout << "Roll: " << roll << endl;
        cout << "Name: " << name << endl;
    }
};

int main() {

    Student s1;                  // Default constructor
    Student s2(101);              // One parameter
    Student s3(102, "Rahul");     // Two parameters

    cout << "\nStudent 1:" << endl;
    s1.display();

    cout << "\nStudent 2:" << endl;
    s2.display();

    cout << "\nStudent 3:" << endl;
    s3.display();

    return 0;
}
