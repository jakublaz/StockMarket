#include "Transactions.h"

Transaction::Transaction(Customer* customer, Company* company, StockMarket* stock_market) :
    customer(customer), company(company), stock_market(stock_market) {}
