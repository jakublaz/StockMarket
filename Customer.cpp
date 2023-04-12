#include "Customer.h"

Customer::Customer(string name, string surname, int phoneNumber, double pocketMoney) {
    this->name = name;
    this->surname = surname;
    this->phoneNumber = phoneNumber;
    this->pocketMoney = pocketMoney;
}

Customer::~Customer() {
    //napisaæ lepiej t¹ funkcje
    //aby usuwa³a z powi¹zanych miejsc te¿
    stockmarkets.clear();
    companies.clear();
    transactions.clear();
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
    this->pocketMoney = amount;
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
    if (Find_Company(company->Get_Name())) {
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

bool Customer::Remove_AllTransactions()
{
    transactions.clear();
    return true;
}

bool Customer::Add_Transaction(Transaction* transaction)
{
    if (transaction==nullptr) {
        return false;
    }
    if (Find_Transaction(transaction->Get_Customer()->Get_Name(), transaction->Get_Company()->Get_Name(), transaction->Get_ID()))  {
        if (transaction->Get_StockMarket() == Find_Transaction(transaction->Get_Customer()->Get_Name(), transaction->Get_Company()->Get_Name(), transaction->Get_ID())->Get_StockMarket()) {
            return false;
        }
    }
    transactions.emplace_back(transaction);
    return false;

}

bool Customer::Add_StockMarket(StockMarket* stockmarket)
{
    if (stockmarket == nullptr) {
        return false;
    }
    if (Find_StockMarket(stockmarket->Get_Name())) {
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

void Customer::Remove_AllCompanies()
{
    companies.clear();
}

void Customer::Remove_AllStockMarkets()
{
    stockmarkets.clear();
}

bool Customer::Remove_Transaction(Transaction* transaction)
{
    if (transaction == nullptr) {
        return false;
    }

    transactions.remove(transaction);
    return true;
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

bool Customer::Add_Shares(string name,int amount)
{
    for (auto it = companies.begin(); it != companies.end(); ++it) {
        if (it->first->Get_Name() == name) {
            it->second += amount;
            return true;
        }
    }
    return false;
}

Company* Customer::Find_Company(string name)
{
    for (auto it = companies.begin(); it != companies.end(); ++it) {
        if (it->first->Get_Name()==name) {
            return it->first;
        }
    }
    return nullptr;
}

Transaction* Customer::Find_Transaction(string nameCustomer, string nameCompany, int ID)
{
    for (auto it = transactions.begin(); it != transactions.end(); ++it) {
        if ((*it)->Get_Company()->Get_Name()==nameCompany && (*it)->Get_Customer()->Get_Name()==nameCustomer && (*it)->Get_ID()==ID) {
            return *it;
        }
    }
    return nullptr;
}

StockMarket* Customer::Find_StockMarket(string name)
{
    for (auto it = stockmarkets.begin(); it != stockmarkets.end(); ++it) {
        if ((*it)->Get_Name() == name) {
            return *it;
        }
    }
    return nullptr;
}

double Customer::All_Money() {
    return investedMoney + pocketMoney;
}