#ifndef PAYMENTTYPES_CPP
#define PAYMENTTYPES_CPP

#include <iostream>
#include "09_Payment.cpp"
using namespace std;

class UpiPayment : public Payment {
public:
    bool pay(double amount) override {
        cout << "UPI payment of Rs." << amount << " initiated.\n";
        return confirmPayment();
    }

    const char* methodName() const override { return "UPI"; }

private:
    bool confirmPayment() {
        char choice;
        cout << "Confirm UPI payment? (y/n): ";
        cin >> choice;
        return choice == 'y' || choice == 'Y';
    }
};

class CardPayment : public Payment {
public:
    bool pay(double amount) override {
        cout << "Card payment of Rs." << amount << " initiated.\n";
        return confirmPayment();
    }

    const char* methodName() const override { return "CARD"; }

private:
    bool confirmPayment() {
        char choice;
        cout << "Confirm Card payment? (y/n): ";
        cin >> choice;
        return choice == 'y' || choice == 'Y';
    }
};

class CashPayment : public Payment {
public:
    bool pay(double amount) override {
        cout << "Cash payment of Rs." << amount << " selected.\n";
        return confirmPayment();
    }

    const char* methodName() const override { return "CASH"; }

private:
    bool confirmPayment() {
        char choice;
        cout << "Confirm cash received? (y/n): ";
        cin >> choice;
        return choice == 'y' || choice == 'Y';
    }
};

#endif
