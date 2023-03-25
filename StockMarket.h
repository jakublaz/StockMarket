#ifndef STOCKMARKET_H
#define STOCKMARKET_H

#include <list>
#include<algorithm>	//for Find functions
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
    StockMarket(string name);
    ~StockMarket();
    void Add_Customer(string name, string surname, int phoneNumber, int pocketMoney = 0);
    void Remove_Customer(string name, string surname);
    void Add_Company(string name, int phoneNumber, int money = 0, int shares = 0);
    void Remove_Company(string name);
    void Add_Transaction(Customer* customer, int amountShares, Company* company, string type);  //before adding
    bool Check_Transaction(const Customer& customer, const Company& company, const int& ID);
    void Print_Transactions(const string& name);	//from company or from customer
    void PrintAll_Transactions();
    void Print_Transaction(const int& ID);
    void Set_Name(string name);
    string Get_Name();
    void Show_Info();   //shows basic info
    void Update_InvestedMoney();
    void Update_AmountOfTransactions();

private:
    string name;
    //will be set using Add_Transaction()
    double investedMoney;  
    int amountOfTransactions;

    list<Customer> customers;
    list<Company> companies;
    list<Transaction> transactions;

    Company* FindCompany(string name);
    Customer* FindCustomer(string surname);
    Transaction* FindTransaction(string nameCustomer, string nameCompany, int ID);
};

#endif /* STOCKMARKET_H */
