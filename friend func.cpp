#include <iostream>
using namespace std;

class Book {
private:
    string title;
    float price;

public:
    Book(string t, float p) {
        title = t;
        price = p;
    }

    friend void display(Book b);
};

// Friend function
void display(Book b) {
    cout << "Book Title: " << b.title << endl;
    cout << "Book Price: " << b.price << endl;
}

int main() {
    Book b("C++ Programming", 500);

    display(b);

    return 0;
}
