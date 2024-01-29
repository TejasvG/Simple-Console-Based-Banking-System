#include <iostream>
#include <limits> // For numeric_limits
#include <string> // For string class

using namespace std;

class Bank {
private:
    string name;
    string address;
    char accountType;
    double balance;

public:
    void openAccount();
    void depositMoney();
    void withdrawMoney();
    void displayAccount();
};

void Bank::openAccount() {
    cout << "Enter your full name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);

    cout << "Enter your address: ";
    getline(cin, address);

    cout << "What type of account you want to open (Savings: 'S' / Current: 'C'): ";
    cin >> accountType;

    cout << "Enter initial deposit amount: ";
    cin >> balance;

    cout << "Your account has been created.\n";
}

void Bank::depositMoney() {
    double depositAmount;
    cout << "Enter the amount you want to deposit: ";
    cin >> depositAmount;

    if (depositAmount < 0) {
        cout << "Invalid deposit amount. Please enter a positive value.\n";
        return;
    }

    balance += depositAmount;
    cout << "Total amount deposited: " << depositAmount << endl;
}

void Bank::withdrawMoney() {
    double withdrawalAmount;
    cout << "Enter the amount you want to withdraw: ";
    cin >> withdrawalAmount;

    if (withdrawalAmount < 0) {
        cout << "Invalid withdrawal amount. Please enter a positive value.\n";
        return;
    }

    if (withdrawalAmount > balance) {
        cout << "Insufficient balance. Withdrawal not allowed.\n";
        return;
    }

    balance -= withdrawalAmount;
    cout << "Withdrawal successful. Current Balance: " << balance << endl;
}

void Bank::displayAccount() {
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
    cout << "Account Type: " << accountType << endl;
    cout << "Balance: " << balance << endl;
}

int main() {
    int choice;
    char continueOption = 'y';
    Bank account;

    cout << "Welcome!\n";

    do {
        cout << "\n1. Open Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Display Account Information\n";
        cout << "5. Exit\n";
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            account.openAccount();
            break;
        case 2:
            account.depositMoney();
            break;
        case 3:
            account.withdrawMoney();
            break;
        case 4:
            account.displayAccount();
            break;
        case 5:
            cout << "Thank you for choosing us. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid input. Please try again.\n";
            break;
        }

        cout << "\nDo you want to perform another transaction? (y/n): ";
        cin >> continueOption;

    } while (continueOption == 'y' || continueOption == 'Y');

    cout << "Thank you for choosing us. Goodbye!\n";
    return 0;
}
