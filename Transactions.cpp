#include "Transactions.h"

Transaction::Transaction()
{
}

Transaction::Transaction(int ID, int amount, int shares, Customer* customer, Company* company, StockMarket* stock_market) :
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

int Transaction::GetAmount() {
    return amount;
}

int Transaction::GetShares() {
    return shares;
}

void Transaction::SetAmount(int amount) {
    this->amount = amount;
}

void Transaction::SetShares(int shares) {
    this->shares = shares;
}

void Transaction::Print_Transaction()
{
}
