
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    fstream file("student.csv", ios::in | ios::out | ios::trunc);

    // Writing student records
    file << "101,Rahul,85\n";
    file << "102,Amit,90\n";

    cout << "Write Position: " << file.tellp() << endl;

    // Reading student records
    file.seekg(0, ios::beg);

    cout << "\nStudent Records:\n";
    cout << "Read Position: " << file.tellg() << endl;

    string line;
    while (getline(file, line))
        cout << line << endl;

    // Moving write pointer
    file.clear();
    file.seekp(0, ios::end);
    file << "103,Neha,95\n";

    cout << "\nUpdated Write Position: " << file.tellp();

    file.close();

    return 0;
}
