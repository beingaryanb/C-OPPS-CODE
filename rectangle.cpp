#include <iostream>
using namespace std;

class Rectangle {
private:
    float length;
    float width;

public:
    void getData() {
        cout << "Enter length: ";
        cin >> length;

        cout << "Enter width: ";
        cin >> width;
    }

    float calculateArea() {
        return length * width;
    }
};

int main() {
    Rectangle r;

    r.getData();

    cout << "Area of Rectangle = " << r.calculateArea() << endl;

    return 0;
}
