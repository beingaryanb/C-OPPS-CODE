
#include <iostream>
#include <exception>
using namespace std;

class BankingException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Banking Error!";
    }
};

class InsufficientBalance : public BankingException
{
public:
    const char* what() const noexcept override
    {
        return "Insufficient Balance!";
    }
};

int main()
{
    float balance = 5000, amount;

    cout << "Enter withdrawal amount: ";
    cin >> amount;

    try
    {
        if (amount > balance)
            throw InsufficientBalance();

        balance -= amount;
        cout << "Withdrawal Successful!" << endl;
        cout << "Remaining Balance: " << balance;
    }
    catch (BankingException &e)
    {
        cout << e.what();
    }

    return 0;
}
