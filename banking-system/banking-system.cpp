#include <iostream>
#include <vector>
#include <map>
#include <ctime>

using namespace std;

// ---------------- TRANSACTION CLASS ----------------
class Transaction {
private:
    int transactionID;
    string type;
    double amount;
    string timestamp;
    int destinationAccount;

public:
    Transaction(int id, string t, double amt, int dest = -1) {
        transactionID = id;
        type = t;
        amount = amt;
        destinationAccount = dest;

        time_t now = time(0);
        timestamp = ctime(&now);
    }

    void display() {
        cout << "Transaction ID: " << transactionID << endl;
        cout << "Type: " << type << endl;
        cout << "Amount: " << amount << endl;
        cout << "Time: " << timestamp;
        if (destinationAccount != -1)
            cout << "Destination Account: " << destinationAccount << endl;
        cout << "---------------------------\n";
    }
};

// ---------------- CUSTOMER CLASS ----------------
class Customer {
private:
    int customerID;
    string name;
    string address;
    string contact;
    vector<int> accounts;

public:
    Customer() {}

    Customer(int id, string n, string a, string c) {
        customerID = id;
        name = n;
        address = a;
        contact = c;
    }

    int getID() { return customerID; }

    string getName() { return name; }

    void addAccount(int accNo) {
        accounts.push_back(accNo);
    }

    void displayCustomer() {
        cout << "Customer ID: " << customerID << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Contact: " << contact << endl;
    }
};

// ---------------- ACCOUNT CLASS ----------------
class Account {
private:
    int accountNumber;
    double balance;
    string accountType;
    Customer* owner;
    vector<Transaction> transactions;

public:
    Account() {}

    Account(int accNo, string type, Customer* cust) {
        accountNumber = accNo;
        accountType = type;
        owner = cust;
        balance = 0;
    }

    int getAccountNumber() { return accountNumber; }

    double getBalance() { return balance; }

    Customer* getOwner() { return owner; }

    void deposit(double amount, int &tid) {
        balance += amount;
        transactions.push_back(Transaction(tid++, "Deposit", amount));
    }

    bool withdraw(double amount, int &tid) {
        if (balance >= amount) {
            balance -= amount;
            transactions.push_back(Transaction(tid++, "Withdrawal", amount));
            return true;
        }
        return false;
    }

    void addTransfer(double amount, int dest, int &tid) {
        transactions.push_back(Transaction(tid++, "Transfer", amount, dest));
    }

    void viewRecentTransactions(int n) {
        int start = max(0, (int)transactions.size() - n);

        for (int i = start; i < transactions.size(); i++) {
            transactions[i].display();
        }
    }

    void displayAccountInfo() {
        cout << "\nAccount Number: " << accountNumber << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: " << balance << endl;
        cout << "Owner: " << owner->getName() << endl;
    }
};

// ---------------- BANK CLASS ----------------
class Bank {
private:
    map<int, Customer> customers;
    map<int, Account> accounts;
    int nextCustomerID = 1;
    int nextAccountNumber = 1001;
    int nextTransactionID = 1;

public:

    void createCustomer() {
        string name, address, contact;

        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Address: ";
        getline(cin, address);

        cout << "Enter Contact: ";
        getline(cin, contact);

        Customer c(nextCustomerID, name, address, contact);
        customers[nextCustomerID] = c;

        cout << "Customer Created with ID: " << nextCustomerID << endl;
        nextCustomerID++;
    }

    void openAccount() {
        int cid;
        string type;

        cout << "Enter Customer ID: ";
        cin >> cid;

        if (customers.find(cid) == customers.end()) {
            cout << "Customer not found!\n";
            return;
        }

        cout << "Enter Account Type (Savings/Current): ";
        cin >> type;

        Account acc(nextAccountNumber, type, &customers[cid]);

        accounts[nextAccountNumber] = acc;
        customers[cid].addAccount(nextAccountNumber);

        cout << "Account Created with Number: " << nextAccountNumber << endl;

        nextAccountNumber++;
    }

    void deposit() {
        int acc;
        double amount;

        cout << "Enter Account Number: ";
        cin >> acc;

        if (accounts.find(acc) == accounts.end()) {
            cout << "Account not found!\n";
            return;
        }

        cout << "Enter Amount: ";
        cin >> amount;

        accounts[acc].deposit(amount, nextTransactionID);
        cout << "Deposit Successful\n";
    }

    void withdraw() {
        int acc;
        double amount;

        cout << "Enter Account Number: ";
        cin >> acc;

        if (accounts.find(acc) == accounts.end()) {
            cout << "Account not found!\n";
            return;
        }

        cout << "Enter Amount: ";
        cin >> amount;

        if (accounts[acc].withdraw(amount, nextTransactionID))
            cout << "Withdrawal Successful\n";
        else
            cout << "Insufficient Balance\n";
    }

    void transfer() {
        int from, to;
        double amount;

        cout << "From Account: ";
        cin >> from;

        cout << "To Account: ";
        cin >> to;

        if (accounts.find(from) == accounts.end() || accounts.find(to) == accounts.end()) {
            cout << "Invalid account!\n";
            return;
        }

        cout << "Amount: ";
        cin >> amount;

        if (accounts[from].withdraw(amount, nextTransactionID)) {
            accounts[to].deposit(amount, nextTransactionID);

            accounts[from].addTransfer(amount, to, nextTransactionID);
            cout << "Transfer Successful\n";
        } else {
            cout << "Insufficient Balance\n";
        }
    }

    void showAccountInfo() {
        int acc;
        cout << "Enter Account Number: ";
        cin >> acc;

        if (accounts.find(acc) != accounts.end())
            accounts[acc].displayAccountInfo();
        else
            cout << "Account not found!\n";
    }

    void showTransactions() {
        int acc, n;

        cout << "Enter Account Number: ";
        cin >> acc;

        cout << "How many recent transactions: ";
        cin >> n;

        if (accounts.find(acc) != accounts.end())
            accounts[acc].viewRecentTransactions(n);
        else
            cout << "Account not found!\n";
    }
};

// ---------------- MAIN FUNCTION ----------------
int main() {

    Bank bank;
    int choice;

    do {
        cout << "\n====== BANKING SYSTEM ======\n";
        cout << "1. Create Customer\n";
        cout << "2. Open Account\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "5. Transfer Funds\n";
        cout << "6. Display Account Info\n";
        cout << "7. View Recent Transactions\n";
        cout << "0. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            bank.createCustomer();
            break;
        case 2:
            bank.openAccount();
            break;
        case 3:
            bank.deposit();
            break;
        case 4:
            bank.withdraw();
            break;
        case 5:
            bank.transfer();
            break;
        case 6:
            bank.showAccountInfo();
            break;
        case 7:
            bank.showTransactions();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid Choice\n";
        }

    } while (choice != 0);

    return 0;
}