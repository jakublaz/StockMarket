#include "Transactions.h"

Transaction::Transaction()
{
    this->ID = 0;
    this->amount = 0;
    this->shares = 0;
    this->company = nullptr;
    this->customer = nullptr;
    this->stock_market = nullptr;

}

Transaction::Transaction(int ID, double amount, int shares, Customer* customer, Company* company, StockMarket* stock_market) :
    customer(customer), company(company), stock_market(stock_market) {
    this->ID = ID;
    this->amount = amount;
    this->shares = shares;
    this->company = company;
    this->customer = customer;
    this->stock_market = stock_market;
}

int Transaction::Get_ID() {
    return ID;
}

void Transaction::Set_ID(int ID) {
    this->ID = ID;
}

double Transaction::Get_Amount() {
    return amount;
}

int Transaction::Get_Shares() {
    return shares;
}

string Transaction::Get_Type()
{
    return this->type;
}

void Transaction::Set_Type(string type)
{
    this->type = type;
}

void Transaction::Set_Amount(int amount) {
    this->amount = amount;
}

void Transaction::Set_Shares(int shares) {
    this->shares = shares;
}

void Transaction::Print_Transaction()
{
}
