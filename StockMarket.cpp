#include "StockMarket.h"

StockMarket::StockMarket(){
    this->name = "";
    this->amountOfTransactions = 0;
    this->investedMoney = 0;
}

StockMarket::StockMarket(string name){
    this->name = name;
    this->amountOfTransactions = 0;
    this->investedMoney = 0;
}

StockMarket::~StockMarket(){

}

void StockMarket::Add_Customer(string name, string surname, int phoneNumber, int pocketMoney) {
}

void StockMarket::Remove_Customer(string name, string surname) {

}

void StockMarket::Add_Company(string name, int phoneNumber, int money, int shares) {

}

void StockMarket::Remove_Company(string name) {

}

void StockMarket::Add_Transaction(int ID,Customer* customer, int amountShares, Company* company, string type) {


}

bool StockMarket::Check_Transaction(const Customer& customer, const Company& company, const int& ID)
{
    return false;
}

void StockMarket::Print_Transactions(const string& name)
{
}

void StockMarket::PrintAll_Transactions()
{
}

void StockMarket::Print_Transaction(const int& ID)
{
}

void StockMarket::Set_Name(string name)
{
    this->name = name;
}

string StockMarket::Get_Name()
{
    return name;
}

Customer* StockMarket::Get_Customer(string name, string surname)
{
    return FindCustomer(name,surname);
}

Company* StockMarket::Get_Company(string name)
{
    return FindCompany(name);
}

Transaction* StockMarket::Get_Transaction(string surnameCustomer, string nameCompany, int ID)
{
    return FindTransaction(surnameCustomer, nameCompany, ID);
}

void StockMarket::Show_Customers()
{
}

void StockMarket::Update_InvestedMoney()
{
}

void StockMarket::Update_AmountOfTransactions()
{
}

void StockMarket::Show_Compnies()
{
}

int StockMarket::SizeOf_Customers()
{
    return customers.size();
}

int StockMarket::SizeOf_Companies()
{
    return companies.size();
}

int StockMarket::SizeOf_Transactions()
{
    return transactions.size();
}

Transaction* StockMarket::Get_Transaction(int ID)
{
    return nullptr;
}

Company* StockMarket::FindCompany(string name)
{
    return nullptr;
}

Customer* StockMarket::FindCustomer(string name, string surname)
{
    return nullptr;
}

Transaction* StockMarket::FindTransaction(string nameCustomer, string nameCompany, int ID)
{
    return nullptr;
}
