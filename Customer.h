#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Company.h"
#include "Transactions.h"
#include "StockMarket.h"
#include<iostream>
#include<list>
#include<string>
#include<algorithm>	//for Find functions
#include <utility>//for pair in list
using namespace std;


//if you want to buy for smaller  amount then sharecost you have to gamble
//the same for selling for higher money

class Company;
class Transaction;
class StockMarket;

class Customer {
public:
	/*
	* Constructor for a customer using setting name, surname, phoneNumber and pocketMoney(not invested)
	*/
	Customer(string name, string surname, int phoneNumber, double pocketMoney = 0);
	/*
	* Default deconstructor, it should delete all lists
	*/
	~Customer();
	/*
	* Setter for name
	*/
	void Set_Name(string name);
	/*
	* Setter for surname
	* It modifies earlier value
	*/
	void Set_Surname(string surname);
	/*
	* Setter for phoneNumber
	* It modifies earlier value
	*/
	void Set_PhoneNumber(int phoneNumber);
	/*
	* Setter for pocketMoney
	* It modifies earlier value
	*/
	void Set_PocketMoney(double amount);
	/*
	* Getter for invested money
	*/
	double Get_InvestedMoney();
	/*
	* Getter for invested money
	*/
	double Get_PocketMoney();
	/*
	a Getter for name
	*
	*/
	string Get_Name();
	/*
	* Getter for surname
	*/
	string Get_Surname();
	/*
	* Getter for phoneNumber
	*/
	int Get_PhoneNumber();
	/*
	* Function enabling you to buy shares, uses amount, as how much shares
	*/
	bool BuyShares(int ID,int shares, Company* company, StockMarket* market, string type);
	/*
	* Function enabling you to sell shares, uses amount, as how much shares
	*/
	bool SellShares(int ID, int shares, Company* company, StockMarket* market, string type);
	/*
	* Function to add company to list companies
	*/
	bool Add_Company(Company* company);
	/*
	* Function to remove company to list companies
	*/
	bool Remove_Company(string name);
	/*
	* Function to add transaction from list transactions
	*/
	bool Add_Transaction(Transaction* transaction);	//check if  the limits are ok
	/*
	* Function to add stockmarket to list stockmarkets
	*/
	bool Add_StockMarket(StockMarket* stockmarket);
	/*
	* Function to remove stockmarket from list stockmarkets
	*/
	bool Remove_StockMarket(string name);
	/*
	* Function returns pointer to company if found
	* if not returns nullptr
	*/
	Company* Get_Company(string name);
	/*
	* Function that goes throught companies list and looks for a company with name==name
	* it returns second part of this pair
	*/
	int Get_SharesCompany(string name);
	/*
	* Test Function
	* returns size of the list of companies
	*/
	int Sizeof_Companies();
	/*
	* Test Function
	* returns size of the list of transactions
	*/
	int Sizeof_Transactions();
	/*
	* Test Function
	* returns size of the list of stockmarkets
	*/
	int Sizeof_StockMarkets();
	/*
	* returns all the money a person have
	*/
	double All_Money();
	/*
	* Function that should help function Add company to manage copmpanies list, adds shares to the second part of it
	* It modifies earlier value
	*/
	bool Add_Shares(string name, int amount);
private:
	/*
	* name of the customer
	*/
	string name;
	/*
	* surname of the customer, must be unique
	*/
	string surname;
	/*
	* phonenumber of the customer
	*/
	int phoneNumber;

	/*
	* amount of money that are invested in a stock market
	* it changes with every change of stock price
	*/
	double investedMoney;
	/*
	* money that are not invested
	*/
	double pocketMoney;
	/*
	* list of companies and amount of stocks, you invested in, uses pair to insert both values as one object
	*/
    list<pair<Company*,int>> companies;
	/*
	* list of transactions that you took part in
	*/
	list<Transaction*> transactions;
	/*
	* list of stock markets you are in
	*/
	list<StockMarket*> stockmarkets;

	/*
	* Setter for investedMoney, it is private because only a function can set invests
	*/
	void Set_InvestedMoney(double amount);

	//this functions will be used to check if certain objects are not on the lists
	//will return nullptr if not found and pointer to element if found
	Company* Find_Company(string name);
	Transaction* Find_Transaction(string nameCustomer, string nameCompany, int ID);
	StockMarket* Find_StockMarket(string name);
};

#endif /* CUSTOMER_H */
