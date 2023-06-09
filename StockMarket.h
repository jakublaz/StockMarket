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
	bool Add_Customer(Customer* customer);
	/*
	* Function to remove customer from list customers
	*/
	bool Remove_Customer(string name, string surname);
	/*
	* Function to add company to list ccompanies
	*/
	bool Add_Company(Company* company);
	/*
	* Function to remove company from list ccompanies
	*/
	bool Remove_Company(string name);
	/*
	* Function to remove transactions if one of the parts of transactions is removed
	*/
	bool Remove_Transaction(Transaction* transaction);
	/*
	* Function to add transaction to list transactions
	* It has to be checked before adding a transaction(using check transaction)
	* If it can't add the transaction it will return 0
	*/
	bool Add_Transaction(int ID, Customer* customer, int amountShares, Company* company, string type);
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
	* returns pointer to customer if found, uses function FindCustomer(string name, string surname)
	* if not found returns nullptr
	*/
	Customer* Get_Customer(string name, string surname);
	/*
	* returns pointer to company if found, uses function FindCompany(string name)
	* if not found returns nullptr
	*/
	Company* Get_Company(string name);
	/*
	* returns pointer to transaction if found, uses function FindTransaction(string surnameCustomer, string nameCompany, int ID)
	* if not found returns nullptr
	*/
	Transaction* Get_Transaction(string surnameCustomer, string nameCompany, int ID);
	/*
	* Function to show basic info about every customer
	*/
	void Show_Customers();
	/*
	* Function to show basic info about each customer
	*/
	void Show_Companies();
	/*
	* Function that will take actions when function IsBancrupt() returns true, divides the assects of bucrupt company
	*/
	void Bancrupt_Company(Company* company);
	/*
	* Test Function
	* returns size of the list of customers
	*/
	int SizeOf_Customers();
	/*
	* Test Function
	* returns size of the list of companies
	*/
	int SizeOf_Companies();
	/*
	* Test Function
	* returns size of the list of transactions
	*/
	int SizeOf_Transactions();
	/*
	* Removes all transaction with this company, and companies from this stockmarket
	*/
	bool Remove_TransactionCompany(Company* company);
	/*
	*  Removes all transaction with this customer, and customers in this stock market
	*/
	bool Remove_TransactionCustomer(Customer* customer);
	/*
	* Function returning pointer to transaction with specyfic id
	*/
	Transaction* Get_Transaction(int ID);
	/*
	* Returns pointer to itself
	*/
	StockMarket* Get_StockMarket();
	/*
	* Writes to the console info about customer
	*/
	void Print_Customer(string name, string surname);
	/*
	* Writes to the console info about company
	*/
	void Print_Company(string name);
	/*
	* Getter for invested money
	*/
	double GetInvestedMoney();

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
	* list of customers in this market
	*/
	list<Customer*> customers;
	/*
	* list of companies in this market
	*/
	list<Company*> companies;
	/*
	* list of transactions done in this market
	*/
	list<Transaction> transactions;

	/*
	* Function that updates money invested in this stockmarket
	*/
	void Update_InvestedMoney(double money);

	//this functions will be used to check if certain objects are not on the lists
	//will return nullptr if not found and pointer to element if found
	Company* FindCompany(string name);
	Customer* FindCustomer(string name, string surname);
	Transaction* FindTransaction(int ID);

	/*
	* function is used in adding pointers while adding a transaction
	*/
	void Add_Pointers(Customer* customer, Company* company, StockMarket* market, Transaction* transaction, int shares, string type);
	/*
	* Function to check if all limitations are met
	*/
	bool Check_Transaction(int ID, Customer* customer, int amountShares, Company* company, string type);

	/*friend bool Company::Company_Remove_StockMarket(string name);*/
};

#endif /* STOCKMARKET_H */
