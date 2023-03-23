#include "StockMarket.h"

void StockMarket::add_customer(Customer* customer) {
    customers.push_back(customer);
}

void StockMarket::remove_customer(Customer* customer) {
    customers.remove(customer);
}

void StockMarket::add_company(Company* company) {
    companies.push_back(company);
}

void StockMarket::remove_company(Company* company) {
    companies.remove(company);
}

void StockMarket::add_transaction(Transaction* transaction) {
    transactions.push_back(transaction);
}

void StockMarket::remove_transaction(Transaction* transaction) {
    transactions.remove(transaction);
}
