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
    Transaction(int ID, double amount, int shares,Customer* customer, Company* company, StockMarket* stock_market);
    int Get_ID();
    double Get_Amount();
    int Get_Shares();
    string Get_Type();
    void Set_Type(string type);
    void Set_ID(int ID);
    void Set_Amount(int amount);
    void Set_Shares(int shares);
    void Print_Transaction();
private:

    int ID;
    double amount;
    int shares;
    string type;
    Customer* customer;
    Company* company;
    StockMarket* stock_market;
};

#endif /* TRANSACTIONS_H */
