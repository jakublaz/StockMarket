#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include "Customer.h"
#include "Company.h"
#include "StockMarket.h"

class Customer;
class Company;
class StockMarket;

class Transaction {
public:
    Transaction(Customer* customer, Company* company, StockMarket* stock_market);

private:
    Customer* customer;
    Company* company;
    StockMarket* stock_market;
};

#endif /* TRANSACTIONS_H */
