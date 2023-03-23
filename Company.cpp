#include "Company.h"

Company::Company() {}

Company::~Company(){

}

void Company::add_customer(Customer* customer) {
    customers.push_back(customer);
}

void Company::remove_customer(Customer* customer) {
    customers.remove(customer);
}

void Company::add_transaction(Transaction* transaction) {
    transactions.push_back(transaction);
}

void Company::remove_transaction(Transaction* transaction) {
    transactions.remove(transaction);
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