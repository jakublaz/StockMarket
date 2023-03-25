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
   Transaction();
    Transaction(int ID, int amount, int shares,Customer* customer, Company* company, StockMarket* stock_market);
    int Get_ID();
    int GetAmount();
    int GetShares();
    void Set_ID(int ID);
    void SetAmount(int amount);
    void SetShares(int shares);
    void Print_Transaction();
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
