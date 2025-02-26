#include <iostream>
#include <vector>
#include <string>

class ATM {
private:
    std::string account_holder;
    std::string account_number;
    std::string pin;
    double balance;
    std::vector<std::string> transaction_history;

public:
    ATM(std::string account_holder, std::string account_number, std::string pin)
        : account_holder(account_holder), account_number(account_number), pin(pin), balance(0) {}

    void display_menu() {
        std::cout << "\nWelcome to ATM Banking Application\n";
        std::cout << "1. Check Balance\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "4. Transaction History\n";
        std::cout << "5. Exit\n";
    }

    void check_balance() {
        std::cout << "Your current balance is: " << balance << "\n";
    }

    void deposit_money() {
        double amount;
        std::cout << "\nEnter amount to deposit: ";
        std::cin >> amount;
        if (amount > 0) {
            balance += amount;
            transaction_history.push_back("Deposited: " + std::to_string(amount));
            std::cout << amount << " deposited successfully!\n";
        } else {
            std::cout << "Invalid amount. Please try again.\n";
        }
    }

    void withdraw_money() {
        double amount;
        std::cout << "\nEnter amount to withdraw: ";
        std::cin >> amount;
        if (amount > 0) {
            if (amount <= balance) {
                balance -= amount;
                transaction_history.push_back("Withdrew: " + std::to_string(amount));
                std::cout << amount << " withdrawn successfully!\n";
            } else {
                std::cout << "Insufficient funds.\n";
            }
        } else {
            std::cout << "Invalid amount. Please try again.\n";
        }
    }

    void transaction_history_display() {
        std::cout << "\nTransaction History:\n";
        if (transaction_history.empty()) {
            std::cout << "No transactions yet.\n";
        } else {
            for (const auto& transaction : transaction_history) {
                std::cout << transaction << "\n";
            }
        }
    }
};

int main() {
    std::string account_holder;
    std::string account_number;
    std::string pin;

    std::cout << "Enter account holder's name: ";
    std::cin >> account_holder;
    std::cout << "Enter account number: ";
    std::cin >> account_number;
    std::cout << "Set your PIN: ";
    std::cin >> pin;

    ATM atm(account_holder, account_number, pin);

    while (true) {
        atm.display_menu();
        int choice;
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                atm.check_balance();
                break;
            case 2:
                atm.deposit_money();
                break;
            case 3:
                atm.withdraw_money();
                break;
            case 4:
                atm.transaction_history_display();
                break;
            case 5:
                std::cout << "\nThank you for using the ATM. Have a great day!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please select a valid option.\n";
        }
    }
}
