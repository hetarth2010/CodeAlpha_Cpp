# Banking System in C++

## Project Overview

The Banking System is a console-based application developed in C++ using Object-Oriented Programming (OOP) principles. The application simulates basic banking operations such as customer creation, account management, deposits, withdrawals, fund transfers, and transaction history tracking.

The project is designed to demonstrate practical implementation of OOP concepts, data encapsulation, and the use of Standard Template Library (STL) containers in C++.

---

## Features

* Create and manage bank customers
* Open Savings or Current accounts
* Perform deposits and withdrawals
* Transfer funds between accounts
* Maintain transaction history for each account
* View recent transactions
* Display account details including balance and owner information
* Menu-driven interface for user interaction

---

## System Architecture

The system is implemented using four main classes.

### Customer Class

Represents a bank customer and stores personal information.

Attributes:

* Customer ID
* Name
* Address
* Contact Information
* List of owned accounts

Responsibilities:

* Store customer information
* Maintain records of accounts owned by the customer

---

### Account Class

Represents a bank account associated with a customer.

Attributes:

* Account Number
* Account Type (Savings or Current)
* Balance
* Owner reference
* Transaction history

Responsibilities:

* Handle deposit and withdrawal operations
* Store and manage transaction records
* Display account information

---

### Transaction Class

Represents a financial transaction performed on an account.

Attributes:

* Transaction ID
* Transaction Type (Deposit, Withdrawal, Transfer)
* Transaction Amount
* Timestamp
* Destination Account (for transfers)

Responsibilities:

* Store detailed records of financial operations

---

### Bank Class

Acts as the central system that manages customers and accounts.

Responsibilities:

* Create and manage customers
* Open and link accounts to customers
* Handle deposit, withdrawal, and transfer operations
* Maintain data using STL containers such as map and vector

---

## Technologies Used

Language:
C++

Programming Paradigm:
Object-Oriented Programming (OOP)

Libraries and Containers:

* Standard Template Library (STL)
* vector for transaction history
* map for managing accounts and customers

Compiler Standard:
C++11 or later

## Project Structure

```
Banking-System
│
├── main.cpp
└── README.md
```

## Compilation and Execution

Using GCC Compiler:

```
g++ main.cpp -o bank
./bank
```

Using an IDE:

1. Create a C++ console project
2. Copy the source code into main.cpp
3. Build and run the project

Supported IDEs include CodeBlocks, Visual Studio, Dev-C++, and CLion.

## Application Menu

The program provides the following menu options:

```
1. Create Customer
2. Open Account
3. Deposit
4. Withdraw
5. Transfer Funds
6. Display Account Information
7. View Recent Transactions
0. Exit
```

## Learning Objectives

This project demonstrates the following concepts:

* Implementation of Object-Oriented Programming in C++
* Designing modular software using classes and objects
* Data encapsulation and abstraction
* Usage of Standard Template Library containers
* Implementation of menu-driven console applications

## Future Enhancements

Possible improvements for the system include:

* Implement file handling to store data permanently
* Add user authentication and security features
* Develop a graphical user interface
* Implement interest calculation for savings accounts
* Add advanced transaction search and reporting features

## Author

Hetarth Bhavsar
