#include "Customer.h"

Customer::Customer(string name, string surname, int phoneNumber, double pocketMoney) {
    this->name = name;
    this->surname = surname;
    this->phoneNumber = phoneNumber;
    this->pocketMoney = pocketMoney;
}

Customer::~Customer() {

}

void Customer::Set_Name(string name) {
    this->name = name;
}

void Customer::Set_Surname(string surname) {
    this->surname = surname;
}

void Customer::Set_PhoneNumber(int phoneNumber) {
    this->phoneNumber = phoneNumber;
}

void Customer::Set_InvestedMoney(double amount) {
    this->investedMoney = amount;
}

void Customer::Set_PocketMoney(double amount) {
    this->investedMoney = amount;
}

string Customer::Get_Name(){
    return this->name;
}

double Customer::Get_InvestedMoney() {
    return investedMoney;
}

double Customer::Get_PocketMoney() {
    return this->pocketMoney;
}

string Customer::Get_Surname(){
    return this->surname;
}

int Customer::Get_PhoneNumber() {
    return this->phoneNumber;
}

bool Customer::BuyShares(int ID, int amount, Company* company, StockMarket* market, string type)
{
    Transaction transaction(ID, amount, this, company, market, type);
    /*market->Add_Transaction(transaction);*/
    return false;
}


bool Customer::SellShares(int ID, int amount, Company* company, StockMarket* market)
{
    return false;
}

void Customer::Add_Company(string name, int phoneNumber, int money, int shares)
{
}

bool Customer::Remove_Company(string name)
{
    return false;
}

void Customer::Add_Transaction(Customer* customer, int amountShares, Company* company, string type)
{
}

void Customer::Add_StockMarket(string name, int ID)
{
}

void Customer::Remove_StockMarket(string name, int ID)
{
}

Company* Customer::Get_Company(string name)
{
    return Find_Company(name);
}

int Customer::Get_SharesCompany(string name)
{
    return 0;
}

int Customer::Sizeof_Companies()
{
    return (int)companies.size();
}

int Customer::Sizeof_Transactions()
{
    return (int)transactions.size();
}

int Customer::Sizeof_StockMarkets()
{
    return (int)stockmarkets.size();
}

void Customer::Add_Shares(int amount)
{

}

Company* Customer::Find_Company(string name)
{
    return nullptr;
}


//bool Customer::FindCompany(string name) {
//    //list<Company*>::iterator it = ListCompanies.begin();
//    //// Loop through each element of the ListCompanies list
//    //for (list<Company*>::iterator it = ListCompanies.begin(); it != ListCompanies.end(); ++it) {
//    //    Company* company = *it;
//
//    //    // Compare the name of the current Company object with the name to find
//    //    if (company->GetName() == name) {
//    //        // The name was found
//    //        cout << "Found company with name " << name << endl;
//    //        return true;
//    //    }
//    //}
//
//    //// If the name was not found
//    //cout << "Could not find company with name " << name << endl;
//    return false;
//}

Transaction* Customer::Find_Transaction(string nameCustomer, string nameCompany, int ID)
{
    return nullptr;
}

StockMarket* Customer::Find_StockMarket(string name)
{
    return nullptr;
}
