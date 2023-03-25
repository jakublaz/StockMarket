#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Company.h"
#include "Transactions.h"
#include "StockMarket.h"
#include<list>
#include<string>
using namespace std;

class Company;
class Transaction;
class StockMarket;

class Customer {
public:
	Customer(string name, string surname, int phoneNumber, double pocketMoney = 0);
	~Customer();
	bool FindCompany(string name);			//to check if i invested in this company(mo¿e mo¿na optymaliozowaæ)
	void SetName(string name);
	void SetSurname(string surname);
	void SetPhoneNumber(int phoneNumber);
	void SetInvestedMoney(double amount);
	void SetpocketMoney(double amount);
	double GetInvestedMoney();
	double GetpocketMoney();
	string GetName();
	string GetSurname();
	int GetPhoneNumber();
	bool BuyShares(int amount);
	bool SellShares(int amount);

private:
	string name;
	string surname;
	int phoneNumber;

	double investedMoney;
	double pocketMoney;
    list<Company*> companies;
	list<Transaction*> transactions;
	list<StockMarket*> stockmarkets;
};

#endif /* CUSTOMER_H */
