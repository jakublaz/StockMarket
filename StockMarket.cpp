#include "StockMarket.h"

StockMarket::StockMarket()
{
}

StockMarket::~StockMarket()
{
}

void StockMarket::Add_Customer(string name, string surname, int phoneNumber, int pocketMoney) {
}

void StockMarket::Remove_Customer(Customer* customer) {
    customers.remove(customer);
}

void StockMarket::Add_Company(string name, int phoneNumber, int money, int shares) {

}

void StockMarket::Remove_Company(Company* company) {
    companies.remove(company);
}

void StockMarket::Add_Transaction(Customer* customer, int amountShares, Company* company, string type) {


}

bool StockMarket::CheckTransaction(const Customer& customer, const Company& company, const int& ID)
{
    return false;
}

void StockMarket::PrintTransactions(const string& name)
{
}

void StockMarket::PrintAllTransactions()
{
}

void StockMarket::PrintTransaction(const int& ID)
{
}

void StockMarket::SetName(string name)
{
    this->name = name;
}

void StockMarket::SetID(int ID)
{
    this->ID = ID;
}

int StockMarket::GetID()
{
    return ID;
}

string StockMarket::GetName()
{
    return name;
}

Company* StockMarket::FindCompany(string name)
{
    return nullptr;
}

Customer* StockMarket::FindCustomer(string surname)
{
    return nullptr;
}

Transaction* StockMarket::FindTransaction(string nameCustomer, string nameCompany, int ID)
{
    return nullptr;
}
