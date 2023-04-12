#include "StockMarket.h"
#include<algorithm>

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

bool StockMarket::Add_Customer(Customer* customer) {
    if (customer == nullptr) {
        return false;
    }
    customers.emplace_back(customer);
    return true;
}

bool StockMarket::Remove_Customer(string name, string surname) {
    Customer* todelete = nullptr;
    todelete = FindCustomer(name,surname);

    if (todelete == nullptr) {
        return false;
    }
    //usuwanie wszystkich transakcji
    todelete->Remove_AllTransactions();
    todelete->Remove_AllCompanies();
    todelete->Remove_AllStockMarkets(todelete);


    auto it = transactions.begin();
    transactions.erase(
        remove_if(
            transactions.begin(),
            transactions.end(),
            [todelete](auto t) { return t.Get_Customer() == todelete; }
        ),
        transactions.end()
    );

    for (auto it = customers.begin(); it != customers.end(); ++it) {
        if (*it == todelete) {
            customers.erase(it);
            return true;
        }
    }

    return false;
}

bool StockMarket::Add_Company(Company* company) {
    if (company == nullptr) {
        return false;
    }
    companies.emplace_back(company);
    return true;
}

bool StockMarket::Remove_Company(string name) {
    Company* todelete = nullptr;
    todelete = FindCompany(name);

    if (todelete == nullptr) {
        return false;
    }

    todelete->Remove_AllTransactions();
    todelete->Remove_AllCustomers();
    todelete->Remove_AllStockMarkets(todelete);

    for (auto it = companies.begin(); it != companies.end(); ++it) {
        if ((*it) == todelete) {
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
        customer->Set_InvestedMoney(customer->Get_InvestedMoney() + amountShares * company->Get_ShareCost());
        customer->Set_PocketMoney(customer->Get_PocketMoney() - amountShares * company->Get_ShareCost());
        company->Update_SoldShares(amountShares);
    }
    else {
        Update_InvestedMoney(company->Get_ShareCost() * amountShares*(-1));
        customer->Set_InvestedMoney(customer->Get_InvestedMoney() - amountShares * company->Get_ShareCost());
        customer->Set_PocketMoney(customer->Get_PocketMoney() + amountShares * company->Get_ShareCost());
        company->Update_SoldShares(amountShares*(-1));
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
    //if (company->IsBancrupt()) {    //if the company is bancrupt
    //    Bancrupt_Company(company);
    //    return false;
    //}
    if (FindTransaction(ID) != nullptr && FindTransaction(ID)->Get_StockMarket() == this) {   //there is the same id
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
    if (customer->All_Money() < 500) {  //am i reach enought?
        return false;
    }
    if (customer->Get_PocketMoney() < company->Get_ShareCost() * amountShares) {
        return false;
    }
    if (type != "buy" && type != "sell") {      //proper name?
        return false;
    }
    if (company->Get_FreeShares() < amountShares && type == "buy") {    //enought shares for buying?
        return false;
    }
    if (company->Get_SoldShares() < amountShares && type == "sold") {   //enought shares  for selling?
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
        cout << "Name : " << c->Get_Name() << endl;
        cout << "Surname : " << c->Get_Surname() << endl;
        cout << "Phone number" << c->Get_PhoneNumber() << endl;
        cout << "Amount of transactions : " << c->Sizeof_Transactions() << endl;
        cout << "Amount of companies" << c->Sizeof_Companies() << endl;
        cout << "Amount of Stockmarkets" << c->Sizeof_StockMarkets() << endl;
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
        cout << "Name : " << c->Get_Name() << endl;
        cout << "Phone number : " << c->Get_PhoneNumber() << endl;
        cout << "Money : " << c->Get_Money() << endl;
        cout << "Shares : " << c->Get_Shares() << endl;
        cout << "Price per share : " << c->Get_ShareCost() << endl;
        cout << endl << endl;
    }
}

void StockMarket::Bancrupt_Company(Company* company)
{
    //do nappisania
    return;
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

bool StockMarket::Remove_TransactionCompany(Company* company)
{
    if (company == nullptr) {
        return false;
    }
    auto it = transactions.begin();
    transactions.erase(
        remove_if(
            transactions.begin(),
            transactions.end(),
            [company](auto t) { return t.Get_Company() == company; }
        ),
        transactions.end()
    );

    auto itt = companies.begin();
    companies.erase(
        remove_if(
            companies.begin(),
            companies.end(),
            [company](auto t) { return t == company; }
        ),
        companies.end()
    );
    return true;
}

Company* StockMarket::FindCompany(string name)
{
    for (auto& c : companies) {
        if (c->Get_Name() == name) {
            return c;
        }
    }
    return nullptr;
}

Customer* StockMarket::FindCustomer(string name, string surname)
{
    for (auto& c : customers) {
        if (c->Get_Surname() == surname) {
            return c;
        }
    }
    return nullptr;
}

Transaction* StockMarket::FindTransaction(int ID)
{
    for (auto& c : transactions) {
        if (c.Get_ID() == ID) {
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

bool StockMarket::Remove_TransactionCustomer(Customer* customer)
{
    if (customer == nullptr) {
        return false;
    }

    auto it = transactions.begin();
    transactions.erase(
        remove_if(
            transactions.begin(),
            transactions.end(),
            [customer](auto t) { return t.Get_Customer() == customer; }
        ),
        transactions.end()
    );


    auto itt = customers.begin();
    customers.erase(
        remove_if(
            customers.begin(),
            customers.end(),
            [customer](auto t) { return t == customer; }
        ),
        customers.end()
    );
    return true;
}

void StockMarket::Print_Company(string name)
{
    cout << "Name : " << name << endl;
    cout << "Phone number : " << Get_Company(name)->Get_PhoneNumber() << endl;
    cout << "Money : " << Get_Company(name)->Get_Money();
    cout << "Shares : " << Get_Company(name)->Get_Shares();

}

double StockMarket::GetInvestedMoney()
{
    return investedMoney;
}

bool StockMarket::Remove_Transaction(Transaction* transaction) {

    if (transaction == nullptr) {
        return false;
    }
    transaction->Get_Customer()->Remove_Transaction(transaction);
    transaction->Get_Company()->Remove_Transaction(transaction);
    Update_InvestedMoney(transaction->Get_Amount() * (-1));

    for (auto it = transactions.begin(); it != transactions.end(); ++it) {
        if (&(*it) == transaction) {
            transactions.erase(it);
            return true;
        }
    }
    return false;
}
