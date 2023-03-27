#include "Test.h"


void Test::Add_Customer_StockMarket() {
	StockMarket market("aa");
	market.Add_Customer("John", "Doe", 1234567890, 5000);
	Customer* customer = market.Get_Customer("John", "Doe");
	if (customer != nullptr) {
		cerr << "Test adding a customer to the stock market failed." << endl;
	}
}

void Test::Add_Company_StockMarket() {
	StockMarket market("aa");
	market.Add_Company("Company A", 1234567890, 10000, 1000);
	Company* company = market.Get_Company("Company A");
	if (company == nullptr) {
		cerr << "Test adding a company to the stock market failed." << endl;
	}
}

void Test::Add_Customer_InvalidNameCustomer() {
	StockMarket market("aa");
	market.Add_Company("Company A", 1234567890, 10000, 1000);
	market.Add_Transaction(1, market.Get_Customer("Invalid", "Name"), 10, market.Get_Company("Company A"), "buy");
	if (market.SizeOf_Transactions() != 0) {
		cerr << "Test adding a transaction to the stock market with invalid customer name failed." << endl;
	}
}

void Test::Add_Customer_InvalidNameCompany(){
	StockMarket market("aa");
	market.Add_Customer("John", "Doe", 1234567890, 5000);
	market.Add_Transaction(1, market.Get_Customer("John", "Doe"), 10, market.Get_Company("Invalid"), "buy");
	if (market.SizeOf_Transactions() != 0) {
		cerr << "Test adding a transaction to the stock market with invalid company name failed." << endl;
	}
}

void Test::Remove_Customer_StockMarket() {
	StockMarket market("aa");
	market.Add_Customer("John", "Doe", 1234567890, 5000);
	market.Remove_Customer("John", "Doe");
	Customer* customer = market.Get_Customer("John", "Doe");
	if (customer != nullptr) {
		cerr << "Test removing a customer from the stock market failed." << endl;
	}
}

void Test::Remove_Company_StockMarket() {
	StockMarket market("aa");
	market.Add_Company("Company A", 1234567890, 10000, 1000);
	market.Remove_Company("Company A");
	Company* company = market.Get_Company("Company A");
	if (company != nullptr) {
		cerr << "Test removing a company from the stock market failed." << endl;
	}
}

void Test::Get_Customer_StockMarket() {
	StockMarket market("aa");
	market.Add_Customer("John", "Doe", 1234567890, 5000);
	Customer* customer = market.Get_Customer("John", "Doe");
	if (customer == nullptr) {
		cerr << "Test getting a customer from the stock market failed." << endl;
	}
}

void Test::Get_Company_StockMarket() {
	StockMarket market("aa");
	market.Add_Company("Company A", 1234567890, 10000, 1000);
	Company* company = market.Get_Company("Company A");
	if (company == nullptr) {
		cerr << "Test getting a company from the stock market failed." << endl;
	}
}

void Test::Get_Transaction_StockMarket() {
	StockMarket market("aa");
	market.Add_Company("Company A", 1234567890, 10000, 1000);

	Customer customer("John", "Doe", 1000);
	Company* company = market.Get_Company("Company A");

	// Buy shares
	market.Add_Transaction(1, &customer, 100, company, "buy");
	Transaction* transaction = market.Get_Transaction(1);
	if (transaction == nullptr || transaction->Get_Type() != "buy" ||
		transaction->Get_Company() != company || transaction->Get_Shares() != 100 ||
		transaction->Get_Customer() != &customer) {
		cerr << "Test getting a transaction from the stock market failed." << endl;
	}

	// Sell shares
	market.Add_Transaction(2, &customer, 50, company, "sell");
	transaction = market.Get_Transaction(2);
	if (transaction == nullptr || transaction->Get_Type() != "sell" ||
		transaction->Get_Company() != company || transaction->Get_Shares() != 50 ||
		transaction->Get_Customer() != &customer) {
		cerr << "Test getting a transaction from the stock market failed." << endl;
	}

	// Invalid ID
	transaction = market.Get_Transaction(3);
	if (transaction != nullptr) {
		cerr << "Test getting a transaction from the stock market failed." << endl;
	}
}






//void Test::SizeOfLists() {
//
//	//in this Scenario we add a Stock Market
//	//then we add 2 customers 1 company and do 3 trasactions
//	//all should be valid
//	//we check(using cerr) if the trasaction list has 3 structures transactions inside, 
//	//if each customer points only once to the company and has right amount of trasactions
//	//if company has a list with 2 customers
//	//if every list in every class has exact amount of objects as it should have
//
//
//	//Add Stock Market
//	StockMarket a("GPW");
//
//	//Add 2 Customers
//	a.Add_Customer("Jacek", "Zak", 990889675, 800000);
//	//test 2 functions with the same functionality
//	a.Add_Customer("Anna", "Maria", 898954637);
//	a.Get_Customer("Anna", "Maria")->Set_PocketMoney(90000);
//	//Add Company with 2000 shares and 50000 in money
//	a.Add_Company("Henkel", 983883001, 2000, 50000);
//
//	//Add trasaction done by Jacek Zak with Helkel on 10 stocks
//	a.Add_Transaction(1,a.Get_Customer("Jacek","Zak"),10,a.Get_Company("Henkel"),"buy");
//
//	//Add trasaction done by Jacek Zak with Helkel on 100 stocks
//	a.Add_Transaction(2,a.Get_Customer("Jacek", "Zak"), 100, a.Get_Company("Henkel"),"buy");
//
//	//Add trasaction done by Anna Maria with Helkel on 56 stocks
//	a.Add_Transaction(3,a.Get_Customer("Anna", "Maria"), 56, a.Get_Company("Henkel"),"buy");
//
//	//StockMarket
//	if (a.SizeOf_Companies() != 1) {
//		cerr << "# Wrong size of list Companies in StockMarket #" << endl;
//	}
//	if (a.SizeOf_Customers() != 2) {
//		cerr << "# Wrong size of list Customers in StockMarket #" << endl;
//	}
//	if (a.SizeOf_Transactions() != 3) {
//		cerr << "# Wrong size of list Transactions in StockMarket #" << endl;
//	}
//
//	//Companies
//	if (a.Get_Company("Henkel")->Sizeof_Customers() != 2) {
//		cerr << "# Wrong size of list Customers in Companies #" << endl;
//	}
//
//	if (a.Get_Company("Henkel")->Sizeof_Transactions() != 3) {
//		cerr << "# Wrong size of list Customers in Companies #" << endl;
//	}
//
//	if (a.Get_Company("Henkel")->Sizeof_StockMarket() != 1) {
//		cerr << "# Wrong size of list Customers in Company #" << endl;
//	}
//
//	//Customers
//	if (a.Get_Customer("Anna", "Maria")->Sizeof_Companies() != 1 && a.Get_Customer("Jacek", "Zak")->Sizeof_Companies() == 1) {
//		cerr << "# Wrong size of list of companies in Customer #" << endl;
//	}
//
//	if (a.Get_Customer("Anna", "Maria")->Sizeof_Transactions() != 1 && a.Get_Customer("Jacek", "Zak")->Sizeof_Transactions() == 2) {
//		cerr << "# Wrong size of list of transactions in Customer #" << endl;
//	}
//
//	if (a.Get_Customer("Anna", "Maria")->Sizeof_StockMarkets() != 1 && a.Get_Customer("Jacek", "Zak")->Sizeof_StockMarkets() == 1) {
//		cerr << "# Wrong size of list of transactions in Customer #" << endl;
//	}
//
//	//Transaction
//	if (a.Get_Transaction("Zak", "Henkel", 2)->Get_Customer() != a.Get_Customer("Jacek", "Zak")) {
//		cerr << "# Wrong person was assigned in a transaction 2 #" << endl;
//	}
//
//	if (a.Get_Transaction("Zak", "Henkel", 2)->Get_Company() != a.Get_Company("Henkel")) {
//		cerr << "# Wrong company was assigned in a transaction 2 #" << endl;
//	}
//
//	if (a.Get_Transaction("Zak", "Henkel", 2)->Get_StockMarket()->Get_Name() != a.Get_Name()) {
//		cerr << "# Wrong stockmarket was assigned in a transaction 2 #" << endl;
//	}
//
//
//}
