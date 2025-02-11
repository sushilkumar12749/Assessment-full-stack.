// Create a Project to demonstrate an ATM Banking Application which will help to get to
// know the bank information.. The Project should contain all the necessary
// requirements i.e A Program should use the concept of OOP.(compulsory :
// Constructor),Make use of scope resolution operator, Loops, ConditionalStatements,
// Whichever is required.

#include <iostream>
#include <string>
using namespace std;

// Class definition for ATM Banking Application
class ATM
{
private:
    string name;
    int pin;
    double balance;

public:
    // Constructor to initialize the ATM application
    ATM(string userName, int userPin, double initialBalance)
    {
        name = userName;
        pin = userPin;
        balance = initialBalance;
    }

    // Function to check the pin and allow access
    bool authenticate(int inputPin)
    {
        if (inputPin == pin)
        {
            return true;
        }
        else
        {
            cout << "Incorrect PIN. Please try again." << endl;
            return false;
        }
    }

    // Function to check account balance
    void checkBalance()
    {
        cout << "Current balance: $" << balance << endl;
    }

    // Function to deposit money
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "$" << amount << " deposited successfully!" << endl;
        }
        else
        {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Function to withdraw money
    void withdraw(double amount)
    {
        if (amount <= balance && amount > 0)
        {
            balance -= amount;
            cout << "$" << amount << " withdrawn successfully!" << endl;
        }
        else if (amount > balance)
        {
            cout << "Insufficient funds!" << endl;
        }
        else
        {
            cout << "Invalid withdrawal amount!" << endl;
        }
    }

    // Function to display user options
    void showMenu()
    {
        int choice;
        double amount;

        do
        {
            cout << "\n********** ATM Menu **********" << endl;
            cout << "1. Check Balance" << endl;
            cout << "2. Deposit Money" << endl;
            cout << "3. Withdraw Money" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                checkBalance();
                break;
            case 2:
                cout << "Enter amount to deposit: $";
                cin >> amount;
                deposit(amount);
                break;
            case 3:
                cout << "Enter amount to withdraw: $";
                cin >> amount;
                withdraw(amount);
                break;
            case 4:
                cout << "Thank you for using ATM!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again!" << endl;
            }
        } while (choice != 4);
    }
};

int main()
{
    string userName;
    int userPin;
    double initialBalance;

    // User input for ATM account creation
    cout << "Enter your name: ";
    cin >> userName;
    cout << "Enter a 4-digit PIN: ";
    cin >> userPin;
    cout << "Enter initial balance: $";
    cin >> initialBalance;

    // Create ATM object
    ATM userATM(userName, userPin, initialBalance);

    // Prompt for pin to authenticate user
    int inputPin;
    cout << "\nEnter your PIN to access your account: ";
    cin >> inputPin;

    if (userATM.authenticate(inputPin))
    {
        cout << "Access granted. Welcome " << userName << "!" << endl;
        userATM.showMenu();
    }
    else
    {
        cout << "Access denied." << endl;
    }

    return 0;
}
