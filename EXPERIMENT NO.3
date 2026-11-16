
#include <iostream>
using namespace std;

class Demo
{
    int *p;

public:
    // Default Constructor
    Demo()
    {
        p = new int(0);
        cout << "Default Constructor\n";
    }

    // Parameterized Constructor
    Demo(int x)
    {
        p = new int(x);
        cout << "Parameterized Constructor\n";
    }

    // Copy Constructor
    Demo(const Demo &d)
    {
        p = new int(*d.p);
        cout << "Copy Constructor\n";
    }

    // Move Constructor
    Demo(Demo &&d)
    {
        p = d.p;
        d.p = nullptr;
        cout << "Move Constructor\n";
    }

    // Copy Assignment
    Demo& operator=(const Demo &d)
    {
        if (this != &d)
        {
            *p = *d.p;
        }
        return *this;
    }

    // Move Assignment
    Demo& operator=(Demo &&d)
    {
        if (this != &d)
        {
            delete p;
            p = d.p;
            d.p = nullptr;
        }
        return *this;
    }

    // Destructor
    ~Demo()
    {
        delete p;
        cout << "Destructor\n";
    }

    void display()
    {
        if (p != nullptr)
            cout << "Value: " << *p << endl;
    }
};

int main()
{
    Demo d1;
    Demo d2(10);
    Demo d3(d2);
    Demo d4(move(d2));

    d3.display();
    d4.display();

    return 0;
}
