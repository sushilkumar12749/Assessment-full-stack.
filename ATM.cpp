#include<iostream>
using namespace std;

class ATM {
private:
    int pin;
    double balance;
public:
    ATM() : pin(12345), balance(20000) {} // Constructor initializing PIN and balance
    
    void displayWelcome();
    bool validatePIN(int enteredPin);
    void showMenu();
    void deposit(double amount);
    void withdraw(double amount);
    void checkBalance();
};

void ATM::displayWelcome() {
    time_t now = time(0);
    char* dt = ctime(&now);
    cout << "\n========== Welcome to ATM ==========" << endl;
    cout << "Current Date and Time: " << dt << endl;
    cout << "1. Enter ATM PIN" << endl;
    cout << "2. Help" << endl;
    cout << "3. Exit" << endl;
}

bool ATM::validatePIN(int enteredPin) {
    return enteredPin == pin;
}

void ATM::showMenu() {
    int choice;
    do {
        cout << "\n===== ATM Menu =====" << endl;
        cout << "1. Deposit Money" << endl;
        cout << "2. Withdraw Money" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                double amount;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                deposit(amount);
                break;
            }
            case 2: {
                double amount;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                withdraw(amount);
                break;
            }
            case 3:
                checkBalance();
                break;
            case 4:
                cout << "Exiting... Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 4);
}

void ATM::deposit(double amount) {
    balance += amount;
    cout << "Amount Deposited Successfully! New Balance: Rs. " << balance << endl;
}

void ATM::withdraw(double amount) {
    if (amount > balance) {
        cout << "Insufficient Balance!" << endl;
    } else {
        balance -= amount;
        cout << "Withdrawal Successful! Remaining Balance: Rs. " << balance << endl;
    }
}

void ATM::checkBalance() {
    cout << "Current Account Balance: Rs. " << balance << endl;
}

int main() {
    ATM atm;
    atm.displayWelcome();
    int choice, enteredPin;
    cout << "Enter your choice: ";
    cin >> choice;
    if (choice == 1) {
        cout << "Enter ATM PIN: ";
        cin >> enteredPin;
        if (atm.validatePIN(enteredPin)) {
            atm.showMenu();
        } else {
            cout << "Incorrect PIN! Exiting..." << endl;
        }
    } else if (choice == 2) {
        cout << "Help: Enter PIN 12345 to access the ATM services." << endl;
    } else {
        cout << "Exiting..." << endl;
    }
    return 0;
}
