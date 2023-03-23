#ifndef STOCKMARKET_H
#define STOCKMARKET_H

#include <list>
#include "Customer.h"
#include "Company.h"
#include "Transactions.h"

using namespace std;

class Customer;
class Company;
class Transaction;


class StockMarket {
public:
    StockMarket();
    ~StockMarket();
    void Add_Customer(string name, string surname, int phoneNumber, int pocketMoney = 0);
    void Remove_Customer(Customer* customer);
    void Add_Company(string name, int phoneNumber, int money = 0, int shares = 0);
    void Remove_Company(Company* company);
    void Add_Transaction(Customer* customer, int amountShares, Company* company, string type);
    bool CheckTransaction(const Customer& customer, const Company& company, const int& ID);
    void PrintTransactions(const string& name);	//from company or from customer
    void PrintAllTransactions();
    void PrintTransaction(const int& ID);
    void SetName(string name);
    void SetID(int ID);
    int GetID();
    string GetName();

private:
    string name;
    int ID;
    int investedMoney;
    int amountOfTransactions;

    list<Customer*> customers;
    list<Company*> companies;
    list<Transaction*> transactions;

    Company* FindCompany(string name);
    Customer* FindCustomer(string surname);
    Transaction* FindTransaction(string nameCustomer, string nameCompany, int ID);
};

#endif /* STOCKMARKET_H */
