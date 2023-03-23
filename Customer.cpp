#include "Customer.h"

Customer::Customer(string name, string surname, int phoneNumber, double pocketMoney) {
    this->name = name;
    this->surname = surname;
    this->phoneNumber = phoneNumber;
    this->pocketMoney = pocketMoney;
}

Customer::~Customer() {

}

bool Customer::FindCompany(string name) {
    //list<Company*>::iterator it = ListCompanies.begin();
    //// Loop through each element of the ListCompanies list
    //for (list<Company*>::iterator it = ListCompanies.begin(); it != ListCompanies.end(); ++it) {
    //    Company* company = *it;

    //    // Compare the name of the current Company object with the name to find
    //    if (company->GetName() == name) {
    //        // The name was found
    //        cout << "Found company with name " << name << endl;
    //        return true;
    //    }
    //}

    //// If the name was not found
    //cout << "Could not find company with name " << name << endl;
    return false;
}

void Customer::SetName(string name) {
    this->name = name;
}

void Customer::SetSurname(string surname) {
    this->surname = surname;
}

void Customer::SetPhoneNumber(int phoneNumber) {
    this->phoneNumber = phoneNumber;
}

void Customer::SetInvestedMoney(double amount) {
    this->investedMoney = amount;
}

void Customer::SetpocketMoney(double amount) {
    this->investedMoney = amount;
}

string Customer::GetName() {
    return this->name;
}

double Customer::GetInvestedMoney() {
    return investedMoney;
}

double Customer::GetpocketMoney() {
    return pocketMoney;
}

string Customer::GetSurname() {
    return surname;
}

int Customer::GetPhoneNumber() {
    return phoneNumber;
}

bool Customer::BuyShares(int amount) {
    //trzeba coœ tu dodac
    //
    //
    //
    return true;
}
bool Customer::SellShares(int amount) {
    //trzeba coœ tu dodac
    //
    //
    //
    return true;
}