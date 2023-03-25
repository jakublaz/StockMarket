#include "Transactions.h"

Transaction::Transaction(int ID, double amount, int shares, Customer* customer, Company* company, StockMarket* stock_market) :
    customer(customer), company(company), stock_market(stock_market) {
    this->ID = ID;
    this->amount = amount;
    this->shares = shares;
    this->company = company;
    this->customer = customer;
    this->stock_market = stock_market;
}

Transaction::~Transaction()
{
    delete company;
    delete customer;
    delete stock_market;
}

int Transaction::Get_ID() {
    return ID;
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

void Transaction::Print_Transaction()
{

}
