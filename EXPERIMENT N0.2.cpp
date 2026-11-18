
#include <iostream>
using namespace std;

class BankAccount
{
private:
    int accountNumber;

protected:
    float balance;

public:
    void setDetails(int acc, float bal)
    {
        accountNumber = acc;
        balance = bal;
    }

    void display()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount : public BankAccount
{
public:
    void addInterest()
    {
        balance = balance + (balance * 0.05);
    }
};

int main()
{
    SavingsAccount s;

    s.setDetails(101, 5000);
    s.addInterest();

    cout << "Bank Account Details" << endl;
    s.display();

    return 0;
}
