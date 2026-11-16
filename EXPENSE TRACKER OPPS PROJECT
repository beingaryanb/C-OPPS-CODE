
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <memory>
#include <sstream>
#include <limits>

using namespace std;

// ==========================================
// BASE CLASS: EXPENSE
// ==========================================

class Expense {
private:
    int id;
    double amount;
    string category;
    string date;

    static int totalCount;

public:
    Expense(int i, double a, string c, string d)
        : id(i), amount(a), category(c), date(d) {
        totalCount++;
    }

    virtual void display() const = 0;

    virtual string getPaymentMethod() const = 0;

    virtual string getExtraDetails() const = 0;

    int getID() const {
        return id;
    }

    double getAmount() const {
        return amount;
    }

    string getCategory() const {
        return category;
    }

    string getDate() const {
        return date;
    }

    static int getTotalCount() {
        return totalCount;
    }

    virtual ~Expense() {
        totalCount--;
    }
};

int Expense::totalCount = 0;


// ==========================================
// DERIVED CLASS: CASH EXPENSE
// ==========================================

class CashExpense : public Expense {
public:

    CashExpense(int id, double amount,
                string category, string date)
        : Expense(id, amount, category, date) {}

    void display() const override {
        cout << left << setw(8) << getID()
             << setw(15) << getCategory()
             << setw(12) << getAmount()
             << setw(15) << "Cash"
             << getDate() << endl;
    }

    string getPaymentMethod() const override {
        return "Cash";
    }

    string getExtraDetails() const override {
        return "";
    }
};


// ==========================================
// DERIVED CLASS: ONLINE EXPENSE
// ==========================================

class OnlineExpense : public Expense {
private:
    string appName;

public:

    OnlineExpense(int id, double amount,
                  string category, string date,
                  string app)
        : Expense(id, amount, category, date),
          appName(app) {}

    void display() const override {
        cout << left << setw(8) << getID()
             << setw(15) << getCategory()
             << setw(12) << getAmount()
             << setw(15) << "Online"
             << getDate() << " (" << appName << ")" << endl;
    }

    string getPaymentMethod() const override {
        return "Online";
    }

    string getExtraDetails() const override {
        return appName;
    }
};


// ==========================================
// EXPENSE MANAGER CLASS
// ==========================================

class ExpenseManager {
private:
    vector<unique_ptr<Expense>> expenses;

    double dailyLimit;
    int nextID;

    const string expenseFile = "expenses.txt";
    const string budgetFile = "budget.txt";

public:

    ExpenseManager() {
        dailyLimit = 500;
        nextID = 101;

        loadBudget();
        loadExpenses();
    }

    // Function overloading - Version 1
    void addExpense(unique_ptr<Expense> e) {
        expenses.push_back(move(e));
    }

    // Function overloading - Version 2
    double calculateTotal() const {
        double total = 0;

        for (const auto& e : expenses) {
            total += e->getAmount();
        }

        return total;
    }

    // Calculate expenses for a particular date
    double calculateTotal(string date) const {
        double total = 0;

        for (const auto& e : expenses) {
            if (e->getDate() == date) {
                total += e->getAmount();
            }
        }

        return total;
    }

    // Save expenses permanently
    void saveExpenses() const {
        ofstream file(expenseFile);

        for (const auto& e : expenses) {
            file << e->getID() << "|"
                 << e->getAmount() << "|"
                 << e->getCategory() << "|"
                 << e->getDate() << "|"
                 << e->getPaymentMethod() << "|"
                 << e->getExtraDetails() << "\n";
        }

        file.close();
    }

    // Load previously saved expenses
    void loadExpenses() {
        ifstream file(expenseFile);

        if (!file.is_open())
            return;

        string line;

        while (getline(file, line)) {
            stringstream ss(line);

            string idText, amountText;
            string category, date;
            string method, extra;

            getline(ss, idText, '|');
            getline(ss, amountText, '|');
            getline(ss, category, '|');
            getline(ss, date, '|');
            getline(ss, method, '|');
            getline(ss, extra, '|');

            try {
                int id = stoi(idText);
                double amount = stod(amountText);

                if (method == "Cash") {
                    addExpense(make_unique<CashExpense>(
                        id, amount, category, date));
                }
                else if (method == "Online") {
                    addExpense(make_unique<OnlineExpense>(
                        id, amount, category, date, extra));
                }

                if (id >= nextID)
                    nextID = id + 1;
            }
            catch (...) {
                // Ignore invalid records
            }
        }

        file.close();
    }

    // Save daily budget
    void saveBudget() const {
        ofstream file(budgetFile);
        file << dailyLimit;
        file.close();
    }

    // Load daily budget
    void loadBudget() {
        ifstream file(budgetFile);

        if (file.is_open()) {
            file >> dailyLimit;
            file.close();
        }
    }

    // Set daily spending limit
    void setDailyLimit() {
        double limit;

        cout << "\nEnter your daily spending limit: Rs. ";
        if (!(cin >> limit) || limit <= 0) {
            cout << "Invalid limit!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        dailyLimit = limit;
        saveBudget();

        cout << "\nDaily limit updated successfully!\n";
    }

    // Warning function
    void checkWarning(string date) const {
        double spent = calculateTotal(date);
        double remaining = dailyLimit - spent;

        cout << "\n----------- BUDGET STATUS -----------\n";

        cout << "Daily Limit : Rs. "
             << dailyLimit << endl;

        cout << "Total Spent : Rs. "
             << spent << endl;

        if (spent > dailyLimit) {
            cout << "\n*** WARNING! ***\n";
            cout << "You have crossed your daily spending limit!\n";

            cout << "Exceeded by: Rs. "
                 << spent - dailyLimit << endl;
        }
        else if (spent == dailyLimit) {
            cout << "\nWARNING: You have reached your daily limit!\n";
        }
        else {
            cout << "Remaining Budget: Rs. "
                 << remaining << endl;
        }

        cout << "-------------------------------------\n";
    }

    // Add new expense
    void addNewExpense() {
        int choice;
        double amount;
        string category, date, app;

        cout << "\nEnter Expense Amount: Rs. ";

        if (!(cin >> amount) || amount <= 0) {
            cout << "Invalid amount! Enter a positive value.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Category (Food/Travel/Shopping etc.): ";
        getline(cin, category);

        if (category.empty() || category.find('|') != string::npos) {
            cout << "Invalid category!\n";
            return;
        }

        cout << "Enter Date (YYYY-MM-DD): ";
        getline(cin, date);

        if (date.empty() || date.find('|') != string::npos) {
            cout << "Invalid date!\n";
            return;
        }

        cout << "\nSelect Payment Method:\n";
        cout << "1. Cash\n";
        cout << "2. Online\n";
        cout << "Enter choice: ";

        if (!(cin >> choice) || (choice != 1 && choice != 2)) {
            cout << "Invalid payment choice!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            addExpense(make_unique<CashExpense>(
                nextID, amount, category, date));
        }
        else {
            cout << "Enter Payment App (Google Pay/PhonePe etc.): ";
            getline(cin, app);

            if (app.empty() || app.find('|') != string::npos) {
                cout << "Invalid app name!\n";
                return;
            }

            addExpense(make_unique<OnlineExpense>(
                nextID, amount, category, date, app));
        }

        cout << "\nExpense added successfully!\n";
        cout << "Your Expense ID is: " << nextID << endl;

        nextID++;

        saveExpenses();

        // Automatically check spending limit
        checkWarning(date);
    }

    // Display all expenses
    void displayAllExpenses() const {
        if (expenses.empty()) {
            cout << "\nNo expenses recorded yet!\n";
            return;
        }

        cout << "\n================ ALL EXPENSES ================\n";

        cout << left << setw(8) << "ID"
             << setw(15) << "Category"
             << setw(12) << "Amount"
             << setw(15) << "Payment"
             << "Date\n";

        cout << "----------------------------------------------------------\n";

        for (const auto& e : expenses) {
            e->display();
        }

        cout << "----------------------------------------------------------\n";
        cout << "Total Expense Records: " << expenses.size() << endl;
        cout << "Total Spending: Rs. " << calculateTotal() << endl;
    }

    // Search expense by ID
    void searchExpense() const {
        int id;

        cout << "\nEnter Expense ID to search: ";

        if (!(cin >> id)) {
            cout << "Invalid ID!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (const auto& e : expenses) {
            if (e->getID() == id) {
                cout << "\nExpense Found!\n";
                e->display();
                return;
            }
        }

        cout << "\nExpense not found!\n";
    }

    // Display daily summary
    void dailySummary() const {
        string date;

        cout << "\nEnter Date (YYYY-MM-DD): ";
        getline(cin, date);

        double total = calculateTotal(date);

        cout << "\n========== DAILY SUMMARY ==========\n";
        cout << "Date: " << date << endl;
        cout << "Total Expenses: Rs. " << total << endl;

        checkWarning(date);
    }

    // Main menu
    void menu() {
        int choice;

        do {
            cout << "\n\n";
            cout << "====================================\n";
            cout << "       SMART EXPENSE TRACKER\n";
            cout << "====================================\n";

            cout << "1. Add New Expense\n";
            cout << "2. View All Expenses\n";
            cout << "3. Search Expense\n";
            cout << "4. Calculate Total Expenses\n";
            cout << "5. Daily Summary & Budget Warning\n";
            cout << "6. Set Daily Spending Limit\n";
            cout << "7. Exit\n";

            cout << "====================================\n";
            cout << "Enter your choice: ";

            if (!(cin >> choice)) {
                cout << "Please enter a valid number!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (choice) {
                case 1:
                    addNewExpense();
                    break;

                case 2:
                    displayAllExpenses();
                    break;

                case 3:
                    searchExpense();
                    break;

                case 4:
                    cout << "\nTotal Spending: Rs. "
                         << calculateTotal() << endl;
                    break;

                case 5:
                    dailySummary();
                    break;

                case 6:
                    setDailyLimit();
                    break;

                case 7:
                    saveExpenses();
                    saveBudget();
                    cout << "\nYour records have been saved.\n";
                    cout << "Thank you for using Smart Expense Tracker!\n";
                    break;

                default:
                    cout << "\nInvalid choice! Try again.\n";
            }

        } while (choice != 7);
    }
};


// ==========================================
// MAIN FUNCTION
// ==========================================

int main() {

    cout << fixed << setprecision(2);

    ExpenseManager manager;

    manager.menu();

    return 0;
}
