#include <iostream>
using namespace std;

int main() {
    int a, b, temp;
    int *ptr1, *ptr2;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    ptr1 = &a;
    ptr2 = &b;

    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;

    cout << "After swapping:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}
