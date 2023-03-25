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

string StockMarket::Get_Name()
{
    return name;
}

void StockMarket::Show_Info()
{
}

void StockMarket::Update_InvestedMoney()
{
}

void StockMarket::Update_AmountOfTransactions()
{
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
