#include <iostream>
using namespace std;

class Calculator {
public:

    // 1. Two integer parameters
    int add(int a, int b) {
        return a + b;
    }

    // 2. Three integer parameters
    int add(int a, int b, int c) {
        return a + b + c;
    }

    // 3. Two double parameters
    double add(double a, double b) {
        return a + b;
    }
};

int main() {
    Calculator c;

    cout << "Sum of 2 numbers = " << c.add(10, 20) << endl;

    cout << "Sum of 3 numbers = " << c.add(10, 20, 30) << endl;

    cout << "Sum of decimal numbers = " << c.add(10.5, 20.5) << endl;

    return 0;
}
