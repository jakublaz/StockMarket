#ifndef STOCKMARKET_H
#define STOCKMARKET_H

#include <list>
#include "Customer.h"
#include "Company.h"
#include "Transactions.h"

class Customer;
class Company;
class Transaction;


class StockMarket {
public:
    StockMarket();
    ~StockMarket();
    void add_customer(Customer* customer);
    void remove_customer(Customer* customer);
    void add_company(Company* company);
    void remove_company(Company* company);
    void add_transaction(Transaction* transaction);
    void remove_transaction(Transaction* transaction);

private:
    std::list<Customer*> customers;
    std::list<Company*> companies;
    std::list<Transaction*> transactions;
};

#endif /* STOCKMARKET_H */
