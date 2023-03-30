#include "Test.h"
//This code tests the ability to establish a company with a value of less than 5000 Euro. 
//It creates a StockMarket object called "market" and adds a customer with the name "John Doe" and a value of 5000. 
//It then adds a company called "ABC Company" with a value of 4000 and 100 shares. 
//Finally, it attempts to add a transaction with the customer and company, and if it fails, it prints an error message. 
void EstablishCompany_Less5000Euro()
{
	StockMarket market("aa");
	market.Add_Customer("John", "Doe", 1234567890, 5000);
	market.Add_Company("ABC Company", 908443122, 4000, 100);
	if (market.Add_Transaction(1, market.Get_Customer("John", "Doe"), 10, market.Get_Company("ABC Company"), "buy") != 0) {
		cerr << "# Test establishing a company with value less than 5000 Euro #" << endl;
	}
}

void Get_Transaction_StockMarket() {
	// Create a StockMarket object and add a company
	StockMarket market("aa");
	market.Add_Company("Company A", 1234567890, 10000, 1000);

	// Create a Customer object
	Customer customer("John", "Doe", 1000);
	Company* company = market.Get_Company("Company A");

	// Buy shares
	// Add a transaction to the stock market and get the transaction
	market.Add_Transaction(1, &customer, 100, company, "buy");
	Transaction* transaction = market.Get_Transaction(1);
	// Check if the transaction is valid
	if (transaction == nullptr || transaction->Get_Type() != "buy" ||
		transaction->Get_Company() != company || transaction->Get_Shares() != 100 ||
		transaction->Get_Customer() != &customer) {
		cerr << "# Test getting a transaction from the stock market failed. #" << endl;
	}

	// Sell shares
	// Add a transaction to the stock market and get the transaction
	market.Add_Transaction(2, &customer, 50, company, "sell");
	transaction = market.Get_Transaction(2);
	// Check if the transaction is valid
	if (transaction == nullptr || transaction->Get_Type() != "sell" ||
		transaction->Get_Company() != company || transaction->Get_Shares() != 50 ||
		transaction->Get_Customer() != &customer) {
		cerr << "# Test getting a transaction from the stock market failed. #" << endl;
	}

	// Invalid ID
	// Get the transaction with an invalid ID
	transaction = market.Get_Transaction(3);
	// Check if the transaction is valid
	if (transaction != nullptr) {
		cerr << "# Test getting a transaction from the stock market failed. #" << endl;
	}
}

void IsBankrupt()
{

}

void SizeOfLists() {

	//Add Stock Market
	StockMarket a("GPW");

	//Add 2 Customers
	a.Add_Customer("Jacek", "Zak", 990889675, 800000);
	//test 2 functions with the same functionality
	a.Add_Customer("Anna", "Maria", 898954637);
	a.Get_Customer("Anna", "Maria")->Set_PocketMoney(90000);
	//Add Company with 2000 shares and 50000 in money
	a.Add_Company("Henkel", 983883001, 2000, 50000);

	//Add trasaction done by Jacek Zak with Helkel on 10 stocks
	a.Add_Transaction(1, a.Get_Customer("Jacek", "Zak"), 10, a.Get_Company("Henkel"), "buy");

	//Add trasaction done by Jacek Zak with Helkel on 100 stocks
	a.Add_Transaction(2, a.Get_Customer("Jacek", "Zak"), 100, a.Get_Company("Henkel"), "buy");

	//Add trasaction done by Anna Maria with Helkel on 56 stocks
	a.Add_Transaction(3, a.Get_Customer("Anna", "Maria"), 56, a.Get_Company("Henkel"), "buy");

	//StockMarket
	if (a.SizeOf_Companies() != 1) {
		cerr << "# Wrong size of list Companies in StockMarket #" << endl;
	}
	if (a.SizeOf_Customers() != 2) {
		cerr << "# Wrong size of list Customers in StockMarket #" << endl;
	}
	if (a.SizeOf_Transactions() != 3) {
		cerr << "# Wrong size of list Transactions in StockMarket #" << endl;
	}

	//Companies
	if (a.Get_Company("Henkel")->Sizeof_Customers() != 2) {
		cerr << "# Wrong size of list Customers in Companies #" << endl;
	}

	if (a.Get_Company("Henkel")->Sizeof_Transactions() != 3) {
		cerr << "# Wrong size of list Customers in Companies #" << endl;
	}

	if (a.Get_Company("Henkel")->Sizeof_StockMarket() != 1) {
		cerr << "# Wrong size of list Customers in Company #" << endl;
	}

	//Customers
	if (a.Get_Customer("Anna", "Maria")->Sizeof_Companies() != 1 && a.Get_Customer("Jacek", "Zak")->Sizeof_Companies() == 1) {
		cerr << "# Wrong size of list of companies in Customer #" << endl;
	}

	if (a.Get_Customer("Anna", "Maria")->Sizeof_Transactions() != 1 && a.Get_Customer("Jacek", "Zak")->Sizeof_Transactions() == 2) {
		cerr << "# Wrong size of list of transactions in Customer #" << endl;
	}

	if (a.Get_Customer("Anna", "Maria")->Sizeof_StockMarkets() != 1 && a.Get_Customer("Jacek", "Zak")->Sizeof_StockMarkets() == 1) {
		cerr << "# Wrong size of list of transactions in Customer #" << endl;
	}

	//Transaction
	if (a.Get_Transaction("Zak", "Henkel", 2)->Get_Customer() != a.Get_Customer("Jacek", "Zak")) {
		cerr << "# Wrong person was assigned in a transaction 2 #" << endl;
	}

	if (a.Get_Transaction("Zak", "Henkel", 2)->Get_Company() != a.Get_Company("Henkel")) {
		cerr << "# Wrong company was assigned in a transaction 2 #" << endl;
	}

	if (a.Get_Transaction("Zak", "Henkel", 2)->Get_StockMarket()->Get_Name() != a.Get_Name()) {
		cerr << "# Wrong stockmarket was assigned in a transaction 2 #" << endl;
	}


}
void LessThen_500Euro()
{
	StockMarket market;
	market.Add_Customer("John", "Doe", 1234567890, 480);
	market.Add_Company("Henkel", 903338291, 5000,1000);
}

void Scenario1()
{
	StockMarket market("GPW");
	market.Add_Customer("John", "Doe", 908115627, 10000);
	market.Print_Customer("John","Doe");
	market.Add_Company("ABC Company", 908116272, 10009, 120);
	market.Print_Company("ABC Company");
	market.Add_Transaction(1, market.Get_Customer("John", "Doe"), 10, market.Get_Company("ABC Company"), "buy");
	market.Print_Transaction(1);
}

