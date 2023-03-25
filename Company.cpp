#include "Company.h"

Company::Company() {
	this->name = "";
	this->phoneNumber = 0;
	this->money = 0;
	this->shares = 0;
}

Company::Company(string name, int phoneNumber, double money, int shares) {
	this->name = name;
	this->phoneNumber = phoneNumber;
	this->money = money;
	this->shares = shares;
}

Company::~Company(){

}

void Company::Add_Customer(Customer* customer) {
    customers.push_back(customer);
}

void Company::Remove_Customer(Customer* customer) {
    customers.remove(customer);
}

void Company::Add_Transaction(Transaction* transaction) {
    transactions.push_back(transaction);
}

void Company::Remove_Transaction(Transaction* transaction) {
    transactions.remove(transaction);
}

void Company::Add_StockMarket(StockMarket* market)
{
}

void Company::Delete_StockMarket(StockMarket* stockmarket)
{
}

string Company::GetName() {
	return this->name;
}

double Company::GetMoney() {
	return money;
}

int Company::GetShares() {
	return shares;
}

int Company::GetPhoneNumber() {
	return phoneNumber;
}

void Company::SetMoney(double amount) {
	this->money = amount;
}

void Company::SetShares(int shares) {
	this->shares = shares;
}

void Company::SetName(string name) {
	this->name = name;
}

void Company::SetPhoneNumber(int number) {
	this->phoneNumber = number;
}