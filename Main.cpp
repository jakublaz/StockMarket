#include <iostream>
#include <string>
#include "StockMarket.h"
#include "Customer.h"
#include "Company.h"
#include "Transactions.h"

int main() {
	//usuwanie pointerów gdy coœ sie usuwa


    //1 customer in 2 diffrent stock markets, with 2 diffrent companies
    StockMarket a("GPW");
    StockMarket b("PWG");

    //Add 2 Customers
    Customer customer1("Jacek", "Zak", 990889675, 80000);
    //test 2 functions with the same functionality
    Company company2("ABC Company", 898954637, 90000, 1000);
    //a.Get_Customer("Anna", "Maria")->Set_PocketMoney(90000);
    //Add Company with 2000 shares and 50000 in money
    Company company1("Henkel", 983883001, 50000, 2000);

    a.Add_Company(&company1);
    a.Add_Company(&company2);
    a.Add_Customer(&customer1);
    b.Add_Customer(&customer1);
    b.Add_Company(&company2);
    b.Add_Company(&company1);

    a.Add_Transaction(1, &customer1, 10, &company1, "buy");
    a.Add_Transaction(2, &customer1, 20, &company2, "buy");
    b.Add_Transaction(1, &customer1, 10, &company1, "buy");

    //customer

    //stockmarket

    //usuwanie z list
    a.Remove_Customer(customer1.Get_Name(), customer1.Get_Surname());
    a.Remove_Company("Henkel");

    cout<<a.SizeOf_Transactions();
    cout<<b.SizeOf_Transactions();
    cout<<b.SizeOf_Customers();
}