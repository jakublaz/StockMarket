#ifndef COMPANY_H
#define COMPANY_H

#include <string>
#include <list>
#include "Customer.h"
#include "Transactions.h"
using namespace std;

class Customer;
class Transaction;

class Company {
public:
    Company();
    ~Company();
    void add_customer(Customer* customer);
    void remove_customer(Customer* customer);
    void add_transaction(Transaction* transaction);
    void remove_transaction(Transaction* transaction);
    double GetMoney();
    int GetShares();
    string GetName();
    int GetPhoneNumber();
    void SetMoney(double amount);
    void SetShares(int shares);
    void SetName(string name);
    void SetPhoneNumber(int number);

private:
    string name;
    int phoneNumber;
    double money;
    int shares;
    list<Customer*> customers;
    list<Transaction*> transactions;
};

#endif /* COMPANY_H */


