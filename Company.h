#ifndef COMPANY_H
#define COMPANY_H

#include <list>
#include "Customer.h"
#include "Transactions.h"

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

private:
    std::list<Customer*> customers;
    std::list<Transaction*> transactions;
};

#endif /* COMPANY_H */
