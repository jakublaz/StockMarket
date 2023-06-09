#include "Transactions.h"

Transaction::Transaction(int ID, int shares, Customer* customer, Company* company, StockMarket* stock_market, string type) :
    customer(customer), company(company), stock_market(stock_market) {
    this->ID = ID;
    this->amount = company->Get_ShareCost() * shares;
    this->shares = shares;
    this->company = company;
    this->customer = customer;
    this->stock_market = stock_market;
    this->type = type;
}

Transaction::~Transaction()
{
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

Customer* Transaction::Get_Customer()
{
    return customer;
}

Company* Transaction::Get_Company()
{
    return company;
}

StockMarket* Transaction::Get_StockMarket()
{
    return stock_market;
}

bool Transaction::HaveEnough_Money()
{
    return false;
}

bool Transaction::HaveEnough_Shares()
{
    return false;
}


