#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include "Customer.h"
#include "Company.h"
#include "StockMarket.h"
#include<string>

using namespace std;

class Customer;
class Company;
class StockMarket;

class Transaction {
public:
    /*Transaction();*/
    Transaction(int ID, int amount, int shares,Customer* customer, Company* company, StockMarket* stock_market);
    int GetID();
    int GetAmount();
    int GetShares();
    void SetID(int ID);
    void SetAmount(int amount);
    void SetShares(int shares);
private:
    int ID;
    int amount;
    int shares;
    string type;
    Customer* customer;
    Company* company;
    StockMarket* stock_market;
};

#endif /* TRANSACTIONS_H */
