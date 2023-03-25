#ifndef COMPANY_H
#define COMPANY_H

#include <string>
#include <list>
#include "Customer.h"
#include "Transactions.h"
#include "StockMarket.h"
using namespace std;

class Customer;
class Transaction;
class StockMarket;

class Company {
public:
    Company();
    Company(string name, int phoneNumber, double money = 0, int shares = 0);
    ~Company();
    void Add_Customer(Customer* customer);
    void Remove_Customer(Customer* customer);
    void Add_Transaction(Transaction* transaction);
    void Remove_Transaction(Transaction* transaction);
    void Add_StockMarket(StockMarket* market);
    void Delete_StockMarket(StockMarket* stockmarket);
    double Get_Money();
    int Get_Shares();
    string Get_Name();
    int Get_PhoneNumber();
    void Set_Money(double amount);
    void Set_Shares(int shares);
    void Set_Name(string name);
    void Set_PhoneNumber(int number);
    void Update_CostShare();        //used in Update_Money();
    void Update_Money(int shares, double money, string type);    //the price must be higher then the costShare if we buy, lower if we sell
    bool Ok_Price(int shares,double money,string type); //used in Update_Money();

private:
    string name;
    int phoneNumber;
    double money;
    int shares;
    double costShare;

    list<Customer*> customers;
    list<Transaction*> transactions;
    list<StockMarket*> stockmarkets;

    //this functions will be used to check if certain objects are not on the lists
    //will return nullptr if not found and pointer to element if found
    Customer* FindCustomer(string surname);
    Transaction* FindTransaction(string nameCustomer, string nameCompany, int ID);
    StockMarket* FindStockMarket(string name);
};

#endif /* COMPANY_H */


