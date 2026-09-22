#include <iostream>
using namespace std;

class Student {
public:
    int roll;
    string name;

    void getData() {
        cout << "Enter roll number: ";
        cin >> roll;

        cout << "Enter name: ";
        cin >> name;
    }

    void display() {
        cout << "Roll No: " << roll << endl;
        cout << "Name: " << name << endl;
    }
};

int main() {
    Student s[3];   // Array of 3 objects

    for (int i = 0; i < 3; i++) {
        cout << "\nStudent " << i + 1 << endl;
        s[i].getData();
    }

    cout << "\n--- Student Details ---\n";

    for (int i = 0; i < 3; i++) {
        s[i].display();
    }

    return 0;
}
