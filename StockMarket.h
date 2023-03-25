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
    /*
    * Default constructor
    */
    StockMarket();
    /*
    * Copy constructor setting name
    */
    StockMarket(string name);
    /*
    * Default deconstructor, it should delete all lists
    */
    ~StockMarket();
    /*
    * Function to add customer to list customers
    */
    void Add_Customer(string name, string surname, int phoneNumber, int pocketMoney = 0);
    /*
    * Function to remove customer from list customers
    */
    void Remove_Customer(string name, string surname);
    /*
    * Function to add company to list ccompanies
    */
    void Add_Company(string name, int phoneNumber, int money = 0, int shares = 0);
    /*
    * Function to remove company from list ccompanies
    */
    void Remove_Company(string name);
    /*
    * Function to add transaction to list transactions
    * It has to be checked before adding a transaction
    */
    void Add_Transaction(Customer* customer, int amountShares, Company* company, string type);
    /*
    * Function to check if all limitations are met
    */
    bool Check_Transaction(const Customer& customer, const Company& company, const int& ID);
    /*
    * Prints all transactions where name equals company or customer
    */
    void Print_Transactions(const string& name);	
    /*
    * Prints all transactions
    */
    void PrintAll_Transactions();
    /*
    * Prints transaction where ID is eqaual to id of a transaction
    */
    void Print_Transaction(const int& ID);
    /*
    * Setter for name
    */
    void Set_Name(string name);
    /*
    * Getter for name
    */
    string Get_Name();
    /*
    * Function to show basic info about every customer
    */
    void Show_Customers();
    /*
    * Function to show basic info about each customer
    */
    void Show_Compnies();

private:
    /*
    * name of the stock market
    */
    string name;
    /*
    * amount of money that are invested in this market 
    */
    double investedMoney;  
    /*
    * amount of transactions in this market
    */
    int amountOfTransactions;
    /*
    * list of customers in this market
    */
    list<Customer> customers;
    /*
    * list of companies in this market
    */
    list<Company> companies;
    /*
    * list of transactions done in this market
    */
    list<Transaction> transactions;

    /*
    * Function that updates money invested in this stockmarket
    */
    void Update_InvestedMoney();
    /*
    * Function that updates amount of operations in this stockmarket
    */
    void Update_AmountOfTransactions();

    //this functions will be used to check if certain objects are not on the lists
    //will return nullptr if not found and pointer to element if found
    Company* FindCompany(string name);
    Customer* FindCustomer(string surname);
    Transaction* FindTransaction(string nameCustomer, string nameCompany, int ID);
};

#endif /* STOCKMARKET_H */
