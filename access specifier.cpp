#include <iostream>
using namespace std;

class Parent {
private:
    int privateData = 10;

protected:
    int protectedData = 20;

public:
    int publicData = 30;

    void showParent() {
        // All three can be accessed inside the class
        cout << "Private: " << privateData << endl;
        cout << "Protected: " << protectedData << endl;
        cout << "Public: " << publicData << endl;
    }
};

class Child : public Parent {
public:
    void showChild() {
        // privateData cannot be accessed here
        // cout << privateData;  // ERROR

        // Protected can be accessed in derived class
        cout << "Protected: " << protectedData << endl;

        // Public can be accessed in derived class
        cout << "Public: " << publicData << endl;
    }
};

int main() {
    Parent p;

    // Private cannot be accessed outside the class
    // cout << p.privateData;     // ERROR

    // Protected cannot be accessed outside the class
    // cout << p.protectedData;   // ERROR

    // Public can be accessed outside the class
    cout << "Public: " << p.publicData << endl;

    cout << "\nInside Parent class:" << endl;
    p.showParent();

    Child c;

    cout << "\nInside Child class:" << endl;
    c.showChild();

    return 0;
}
