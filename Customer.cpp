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
    if (market == nullptr) {
        return false;
    }
    market->Add_Transaction(ID,this,amount,company,type);
    return true;
}


bool Customer::SellShares(int ID, int amount, Company* company, StockMarket* market,string type)
{
    //sprawdziæ czy mamy odpowiednio du¿o sharów
    market->Add_Transaction(ID, this, amount, company, type);
    return true;
}

bool Customer::Add_Company(Company* company) {
    if (company == nullptr) {
        return false;
    }
    companies.emplace_back(company, 0);
    return true;
}

bool Customer::Remove_Company(string name)
{
    if (Find_Company(name) == nullptr) {
        return false;
    }
    for (auto it = companies.begin(); it != companies.end(); ++it) {
        if (it->first->Get_Name()==name) {
            companies.erase(it);
            return true; // exit the function after removing the customer
        }
    }
    return false;
}

bool Customer::Add_Transaction(Transaction* transaction)
{
    if (transaction==nullptr) {
        return false;
    }
    transactions.emplace_back(transaction);
    return false;

}

bool Customer::Add_StockMarket(StockMarket* stockmarket)
{
    if (stockmarket == nullptr) {
        return false;
    }
    stockmarkets.emplace_back(stockmarket);
    return true;
}

bool Customer::Remove_StockMarket(string name)
{
    if (Find_StockMarket(name) == nullptr) {
        return false;
    }
    for (auto it = stockmarkets.begin(); it != stockmarkets.end(); ++it) {
        if ((*it)->Get_Name() == name) {
            stockmarkets.erase(it);
            return true; // exit the function after removing the customer
        }
    }
    return false;
}

Company* Customer::Get_Company(string name)
{
    return Find_Company(name);
}

int Customer::Get_SharesCompany(string name)
{
    for (auto it = companies.begin(); it != companies.end(); ++it) {
        if (it->first->Get_Name() == name) {
            return it->second; // exit the function after removing the customer
        }
    }
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

double Customer::All_Money() {
    return investedMoney + pocketMoney;
}