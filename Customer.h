#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Company.h"
#include "Transactions.h"
#include "StockMarket.h"
#include<list>
#include<string>
#include<algorithm>	//for Find functions
using namespace std;

class Company;
class Transaction;
class StockMarket;

class Customer {
public:
	Customer(string name, string surname, int phoneNumber, double pocketMoney = 0);
	~Customer();
	void Set_Name(string name);
	void SetSurname(string surname);
	void SetPhoneNumber(int phoneNumber);
	void SetInvestedMoney(double amount);
	void SetpocketMoney(double amount);
	double GetInvestedMoney();
	double GetpocketMoney();
	string Get_Name() const;
	string GetSurname() const;
	int GetPhoneNumber();
	bool BuyShares(int amount);
	bool SellShares(int amount);
	void Add_Company(string name, int phoneNumber, int money = 0, int shares = 0);
	bool Remove_Company(string name);
	void Add_Transaction(Customer* customer, int amountShares, Company* company, string type);
	void Add_StockMarket(string name, int ID);
	void Remove_StockMarket(string name, int ID);
private:
	string name;
	string surname;
	int phoneNumber;

	double investedMoney;
	double pocketMoney;
    list<Company*> companies;
	list<Transaction*> transactions;
	list<StockMarket*> stockmarkets;

	//this functions will be used to check if certain objects are not on the lists
	//will return nullptr if not found and pointer to element if found
	Company* Find_Company(string name);
	Transaction* Find_Transaction(string nameCustomer, string nameCompany, int ID);
	StockMarket* Find_StockMarket(string name);
};

#endif /* CUSTOMER_H */
