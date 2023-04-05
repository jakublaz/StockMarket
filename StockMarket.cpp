#include "StockMarket.h"

StockMarket::StockMarket(){
    this->name = "";
    this->investedMoney = 0;
}

StockMarket::StockMarket(string name){
    this->name = name;
    this->investedMoney = 0;
}

StockMarket::~StockMarket(){
    //do napisania czegoœ wiêcej
    customers.clear();
    companies.clear();
    transactions.clear();
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
    if (!Check_Transaction(ID, customer, amountShares, company, type)) {
        return false;
    }
    transactions.emplace_back(ID, amountShares, customer, company, this, type);
    if (type == "buy") {
        Update_InvestedMoney(company->Get_ShareCost()*amountShares);
    }
    else {
        Update_InvestedMoney(company->Get_ShareCost() * amountShares*(-1));
    }
    //add poinetrs
    Add_Pointers(customer, company, this, this->Get_Transaction(ID),amountShares,type);
    return true;
}

void StockMarket::Add_Pointers(Customer* customer, Company* company, StockMarket* market, Transaction* transaction, int shares, string type) {
    //pointers to customer
    customer->Add_Company(company);
    customer->Add_StockMarket(market);
    customer->Add_Transaction(transaction);
    if (type == "buy") {
        customer->Add_Shares(company->Get_Name(), shares);
    }
    else {
        customer->Add_Shares(company->Get_Name(), shares*(-1));
    }

    //pointers to company
    company->Add_Customer(customer);
    company->Add_StockMarket(market);
    company->Add_Transaction(transaction);
}

bool StockMarket::Check_Transaction(int ID, Customer* customer, int amountShares,Company* company, string type)
{
    if (FindTransaction(ID) != nullptr) {   //there is the same id
        return false;
    }
    if (customer == nullptr || FindCustomer(customer->Get_Name(), customer->Get_Surname()) == nullptr) {  // add customer if there is not
        return false;
    }
    if (company == nullptr || FindCompany(company->Get_Name()) == nullptr) {  //add company if there is not
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
    if (customer->All_Money() < 500) {
        return false;
    }
    if (customer->Get_PocketMoney() < company->Get_ShareCost() * amountShares) {
        return false;
    }
    if (type != "buy" && type != "sell") {
        return false;
    }
    return true;
}


void StockMarket::Print_Transactions(const string& name)
{
    for (auto it = transactions.begin(); it != transactions.end(); ++it) {
        if (it->Get_Company()->Get_Name() == name) {
            cout << "ID : " << it->Get_ID() << endl;
            cout << "Customer : " << it->Get_Customer()->Get_Name() << " " << it->Get_Customer()->Get_Surname() << endl;
            cout << "Company : " << it->Get_Company()->Get_Name() << endl;
            cout << "Money : " << it->Get_Amount() << endl;
            cout << "Shares : " << it->Get_Shares() << endl;
            cout << "Price per share : " << (double)it->Get_Amount() / it->Get_Shares() << endl;
            cout << endl << endl;
        }
        if (it->Get_Customer()->Get_Name() == name) {
            cout << "ID : " << it->Get_ID() << endl;
            cout << "Customer : " << it->Get_Customer()->Get_Name() << " " << it->Get_Customer()->Get_Surname() << endl;
            cout << "Company : " << it->Get_Company()->Get_Name() << endl;
            cout << "Money : " << it->Get_Amount() << endl;
            cout << "Shares : " << it->Get_Shares() << endl;
            cout << "Price per share : " << (double)it->Get_Amount() / it->Get_Shares() << endl;
            cout << endl << endl;
        }
    }
}

void StockMarket::PrintAll_Transactions()
{
    for (auto it = transactions.begin(); it != transactions.end(); ++it) {
            cout << "ID : " << it->Get_ID() << endl;
            cout << "Customer : " << it->Get_Customer()->Get_Name() << " " << it->Get_Customer()->Get_Surname() << endl;
            cout << "Company : " << it->Get_Company()->Get_Name() << endl;
            cout << "Money : " << it->Get_Amount() << endl;
            cout << "Shares : " << it->Get_Shares() << endl;
            cout << "Price per share : " << (double)it->Get_Amount() / it->Get_Shares() << endl;
            cout << endl << endl;
    }
}

void StockMarket::Print_Transaction(const int& ID)
{
    for (auto it = transactions.begin(); it != transactions.end(); ++it) {
        if (it->Get_ID() == ID) {
            cout << "ID : " << ID << endl;
            cout << "Customer : " << it->Get_Customer()->Get_Name() << " " << it->Get_Customer()->Get_Surname() << endl;
            cout << "Company : " << it->Get_Company()->Get_Name() << endl;
            cout << "Money : " << it->Get_Amount() << endl;
            cout << "Shares : " << it->Get_Shares() << endl;
            cout << "Price per share : " <<(double) it->Get_Amount() / it->Get_Shares() << endl;
            return;
        }
    }
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
    for (auto& c : customers) {
        cout << "Name : " << c.Get_Name() << endl;
        cout << "Surname : " << c.Get_Surname() << endl;
        cout << "Phone number" << c.Get_PhoneNumber() << endl;
        cout << "Amount of transactions : " << c.Sizeof_Transactions() << endl;
        cout << "Amount of companies" << c.Sizeof_Companies() << endl;
        cout << "Amount of Stockmarkets" << c.Sizeof_StockMarkets() << endl;
        cout << endl << endl;
    }
}

void StockMarket::Update_InvestedMoney(double money)
{
    investedMoney += money;
}

void StockMarket::Show_Companies()
{
    for (auto& c : companies) {
        cout << "Name : " << c.Get_Name() << endl;
        cout << "Phone number : " << c.Get_PhoneNumber() << endl;
        cout << "Money : " << c.Get_Money() << endl;
        cout << "Shares : " << c.Get_Shares() << endl;
        cout << "Price per share : " << c.Get_ShareCost() << endl;
        cout << endl << endl;
    }
}

void StockMarket::Bancrupt_Company()
{
    //
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
