#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class BankAccount {
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    // Constructor to initialize account
    BankAccount(const string& accNum, const string& holderName) {
        accountNumber = accNum;
        accountHolderName = holderName;
        balance = 0.0;
    }

    // Function to display account details
    void displayAccountDetails() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Current Balance: $" << balance << endl;
    }

    // Function to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << " successfully!" << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Function to withdraw money
    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else if (amount > 0) {
            balance -= amount;
            cout << "Withdrew $" << amount << " successfully!" << endl;
        } else {
            cout << "Invalid withdrawal amount!" << endl;
        }
    }

    // Function to check the current balance
    double getBalance() const {
        return balance;
    }
};

// A simple bank system to handle multiple accounts
class BankSystem {
private:
    unordered_map<string, BankAccount> accounts;

public:
    // Function to create a new account
    void createAccount() {
        string accNum, accHolder;
        cout << "Enter Account Number: ";
        cin >> accNum;
        cout << "Enter Account Holder's Name: ";
        cin.ignore();
        getline(cin, accHolder);

        if (accounts.find(accNum) == accounts.end()) {
            // Using emplace instead of operator[]
            accounts.emplace(accNum, BankAccount(accNum, accHolder));
            cout << "Account created successfully!" << endl;
        } else {
            cout << "Account with this number already exists!" << endl;
        }
    }

    // Function to deposit money into an account
    void deposit() {
        string accNum;
        double amount;
        cout << "Enter Account Number: ";
        cin >> accNum;

        auto it = accounts.find(accNum);
        if (it != accounts.end()) {
            cout << "Enter amount to deposit: $";
            cin >> amount;
            it->second.deposit(amount);
        } else {
            cout << "Account not found!" << endl;
        }
    }

    // Function to withdraw money from an account
    void withdraw() {
        string accNum;
        double amount;
        cout << "Enter Account Number: ";
        cin >> accNum;

        auto it = accounts.find(accNum);
        if (it != accounts.end()) {
            cout << "Enter amount to withdraw: $";
            cin >> amount;
            it->second.withdraw(amount);
        } else {
            cout << "Account not found!" << endl;
        }
    }

    // Function to check the balance of an account
    void checkBalance() {
        string accNum;
        cout << "Enter Account Number: ";
        cin >> accNum;

        auto it = accounts.find(accNum);
        if (it != accounts.end()) {
            it->second.displayAccountDetails();
        } else {
            cout << "Account not found!" << endl;
        }
    }
};

int main() {
    BankSystem bank;
    int choice;

    while (true) {
        cout << "\n===== Simple Bank System =====" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Check Balance" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bank.createAccount();
                break;
            case 2:
                bank.deposit();
                break;
            case 3:
                bank.withdraw();
                break;
            case 4:
                bank.checkBalance();
                break;
            case 5:
                cout << "Exiting system..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
