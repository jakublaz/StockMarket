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

bool StockMarket::Add_Customer(Customer &customer) {
    customers.emplace_back(customer);
    return true;
}

bool StockMarket::Remove_Customer(string name, string surname) {
    for (auto it = customers.begin(); it != customers.end(); ++it) {
        if (it->Get_Name() == name && it->Get_Surname() == surname) {
            customers.erase(it);
            return true; // exit the function after removing the customer
        }
    }
    return false;
}

bool StockMarket::Add_Company(Company &company) {
    companies.emplace_back(company);
    return true;
}

bool StockMarket::Remove_Company(string name) {
    for (auto it = companies.begin(); it != companies.end(); ++it) {
        if (it->Get_Name() == name) {
            companies.erase(it);
            return true; // exit the function after removing the customer
        }
    }
    return false;
}

//dzia³a
bool StockMarket::Add_Transaction(int ID,Customer* customer, int amountShares, Company* company, string type) {
    if (FindTransaction(ID) != nullptr) {   //there is the same id
        return false;
    }
    if (company->Get_ShareCost() < 2) { //share lover then 2Euro
        return false;
    }
    if (company->Get_ShareCost() * amountShares < 10) { //transaction is for less then 10 Euro
        return false;
    }
    if (company->Get_Money() < 5000) {  //company does not have enought money to be able to be bought
        return false;
    }
    if (FindCustomer(customer->Get_Name(),customer->Get_Surname())==nullptr) {  // add customer if there is not
        Add_Customer(*customer);
    }
    if (FindCompany(company->Get_Name()) == nullptr) {  //add company if there is not
        Add_Company(*company);
    }
    transactions.emplace_back(ID, amountShares, customer, company, this, type);
    return true;
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
    return FindTransaction(ID);
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

void StockMarket::Show_Companies()
{
}

void StockMarket::Bancrupt_Company()
{
}

int StockMarket::SizeOf_Customers()
{
    return (int)customers.size();
}

int StockMarket::SizeOf_Companies()
{
    return (int)companies.size();
}

int StockMarket::SizeOf_Transactions()
{
    return (int)transactions.size();
}

Transaction* StockMarket::Get_Transaction(int ID)
{
    for (auto& c : transactions) {
        if (c.Get_ID() == ID) {
            Transaction* ptr = &c;
            return ptr;
        }
    }
    return nullptr;
}

StockMarket* StockMarket::Get_StockMarket()
{
    return this;
}

Company* StockMarket::FindCompany(string name)
{
    for (auto& c : companies) {
        if (c.Get_Name() == name) {
            Company* ptr = &c;
            return ptr;
        }
    }
    return nullptr;
}

Customer* StockMarket::FindCustomer(string name, string surname)
{
    for (auto& c : customers) {
        if (c.Get_Surname() == surname) {
            Customer* ptr = &c;
            return ptr;
        }
    }
    return nullptr;
}

Transaction* StockMarket::FindTransaction(int ID)
{
    for (auto& c : transactions) {
        if (c.Get_ID() == ID) {
            Transaction* ptr = &c;
            return &c;
        }
    }
    return nullptr;
}

void StockMarket::Print_Customer(string name,string surname)
{
    cout << "Name : " << name << endl;
    cout << "Surname : " << surname << endl;
    cout << "Phone number : " << Get_Customer(name,surname)->Get_PhoneNumber()<< endl;
    cout << "Pocket money : " << Get_Customer(name, surname)->Get_PocketMoney() << endl;
}

void StockMarket::Print_Company(string name)
{
    cout << "Name : " << name << endl;
    cout << "Phone number : " << Get_Company(name)->Get_PhoneNumber() << endl;
    cout << "Money : " << Get_Company(name)->Get_Money();
    cout << "Shares : " << Get_Company(name)->Get_Shares();

}
