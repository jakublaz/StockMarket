#include "StockMarket.h"

void StockMarket::Add_Customer(string name, string surname, int phoneNumber, int pocketMoney) {
}

void StockMarket::Remove_Customer(Customer* customer) {
    customers.remove(customer);
}

void StockMarket::Add_Company(string name, int phoneNumber, int money, int shares) {
}

void StockMarket::Remove_Company(Company* company) {
    companies.remove(company);
}

void StockMarket::Add_Transaction(Customer* customer, int amountShares, Company* company, string type) {
}