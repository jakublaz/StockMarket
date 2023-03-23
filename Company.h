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
    void Add_Customer(Customer* customer);
    void Remove_Customer(Customer* customer);
    void Add_Transaction(Transaction* transaction);
    void Remove_Transaction(Transaction* transaction);
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


