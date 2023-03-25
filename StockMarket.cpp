#include "StockMarket.h"

StockMarket::StockMarket(){
    this->name = "";
    this->ID = 0;
    this->amountOfTransactions = 0;
    this->investedMoney = 0;
}

StockMarket::StockMarket(string name, int ID){
    this->name = name;
    this->ID = ID;
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

void StockMarket::Add_Transaction(Customer* customer, int amountShares, Company* company, string type) {


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

void StockMarket::Set_ID(int ID)
{
    this->ID = ID;
}

int StockMarket::Get_ID()
{
    return ID;
}

string StockMarket::Get_Name()
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
