#include "Company.h"
using namespace std;

Company::Company() {
	this->name = "";
	this->phoneNumber = 0;
	this->money = 0;
	this->shares = 0;
	this->costShare = 0;
}

Company::Company(string name, int phoneNumber, double money, int shares) {
	this->name = name;
	this->phoneNumber = phoneNumber;
	this->money = money;
	this->shares = shares;
	Update_CostShare();
}

Company::~Company(){
	//napisa� lepiej t� funkcje
	//aby usuwa�a z powi�zanych miejsc te�
	stockmarkets.clear();
	customers.clear();
	transactions.clear();
}

bool Company::Add_Customer(Customer* newCustomer) {
	if (newCustomer == nullptr) {
		return false;
	}
	customers.emplace_back(newCustomer);
	return true;
}

bool Company::Remove_Customer(string name, string surname) {
	for (auto it = customers.begin(); it != customers.end(); ++it) {
		if ((*it)->Get_Name() == name && (*it)->Get_Surname() == surname) {
			customers.erase(it);
			return true;
		}
	}
	return false;
}

bool Company::Add_Transaction(Transaction* transaction) {
	if (transaction == nullptr) {
		return false;
	}
	transactions.emplace_back(transaction);
	return true;
}

bool Company::Add_StockMarket(StockMarket* stockmarket){
	if (stockmarket == nullptr) {
		return false;
	}
	stockmarkets.emplace_back(stockmarket);
	return true;
}

bool Company::Remove_StockMarket(string name){
	for (auto it = stockmarkets.begin(); it != stockmarkets.end(); ++it) {
		if ((*it)->Get_Name()==name) {
			stockmarkets.erase(it);
			return true;
		}
	}
	return false;
}

string Company::Get_Name() {
	return this->name;
}

double Company::Get_Money() {
	return money;
}

int Company::Get_Shares() {
	return shares;
}

int Company::Get_PhoneNumber() {
	return phoneNumber;
}

void Company::Set_Money(double amount) {
	this->money = amount;
}

void Company::Set_Shares(int shares) {
	this->shares = shares;
}

void Company::Set_Name(string name) {
	this->name = name;
}

void Company::Set_PhoneNumber(int number) {
	this->phoneNumber = number;
}

void Company::Update_CostShare()
{
	if (shares == 0) {
		costShare = 0;
		return;
	}
	costShare = money / shares;
}

void Company::Update_Money(int shares, double money, string type)
{
	Ok_Price(shares, money, type);
	double cost = shares * this->costShare;
	double payed = shares * money;
	this->money = this->money - cost + payed;
	Update_CostShare();
}

int Company::Ok_Price(int shares,double money, string type)
{
	double costPerShare = (double)money / shares;
	if (type == "sell" && costPerShare<costShare) {
		return true;
	}
	if (type == "buy" && costPerShare > costShare) {
		return true;
	}
	return false;
}

int Company::Sizeof_Customers()
{
	return (int)customers.size();
}

int Company::Sizeof_Transactions()
{
	return (int)transactions.size();
}

int Company::Sizeof_StockMarket()
{
	return (int)stockmarkets.size();
}

bool Company::IsBancrupt()
{
	return false;
}

Customer* Company::FindCustomer(string surname)	//do sprawdzenia
{
	for (auto& c : customers) {
		if (c->Get_Surname() == surname) {
			return c;
		}
	}
	return nullptr;
}

Transaction* Company::FindTransaction(string nameCustomer, string nameCompany, int ID)
{
	return nullptr;
}

StockMarket* Company::FindStockMarket(string name)
{
	return nullptr;
}

double Company::Get_ShareCost() {
	return costShare;
}
