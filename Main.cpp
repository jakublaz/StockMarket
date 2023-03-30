#include<iostream>
#include<string>
#include "StockMarket.h"
#include "Customer.h"
#include "Company.h"
#include "Transactions.h"

int main() {
    StockMarket market("GPW");
    market.Add_Customer("John", "Doe", 908115627, 10000);
    market.Add_Company("ABC Company", 908116272, 10009, 120);
    market.Add_Transaction(1, market.Get_Customer("John", "Doe"), 10, market.Get_Company("ABC Company"), "buy");
}