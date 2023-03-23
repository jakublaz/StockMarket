#include "Company.h"

Company::Company() {}

Company::~Company(){

}

void Company::add_customer(Customer* customer) {
    customers.push_back(customer);
}

void Company::remove_customer(Customer* customer) {
    customers.remove(customer);
}

void Company::add_transaction(Transaction* transaction) {
    transactions.push_back(transaction);
}

void Company::remove_transaction(Transaction* transaction) {
    transactions.remove(transaction);
}
