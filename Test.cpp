#include "Test.h"


void Test::Add_Customer_StockMarket() {
	//Create a stock market object with the symbol "aa" 
	StockMarket market("aa");
	//Add a customer to the stock market with the name "John Doe", ID 1234567890, and a balance of 5000. 
	market.Add_Customer("John", "Doe", 1234567890, 5000);
	//Retrieve the customer from the stock market
	Customer* customer = market.Get_Customer("John", "Doe");
	//If the customer is not found, print an error message
	if (customer != nullptr) {
		cerr << "# Test adding a customer to the stock market failed. #" << endl;
	}
}


void Test::Add_Company_StockMarket() {
	//Create a StockMarket object with the name "aa"
	StockMarket market("aa");

	//Add a company to the stock market with the name "Company A", a unique ID of 1234567890, 10,000 shares, and a share price of $1,000
	market.Add_Company("Company A", 1234567890, 10000, 1000);

	//Retrieve the company from the stock market
	Company* company = market.Get_Company("Company A");

	//Check if the company was added successfully
	if (company == nullptr) {
		cerr << "# Test adding a company to the stock market failed. #" << endl;
	}
}

void Test::Add_Customer_InvalidNameCustomer()
{
	StockMarket market("aa");
	market.Add_Customer("Invalid", "Name", 1234567890, 5000);
	market.Get_Company("Henkel");
	market.Add_Transaction(1, market.Get_Customer("John", "Doe"), 10, market.Get_Company("Henkel"), "buy");
	if (market.SizeOf_Transactions() != 0) {
		cerr << "# Test adding a transaction to the stock market with invalid customer name failed. #" << endl;
	}
}

//This code tests the ability to add a transaction to the stock market with an invalid company name. 
//It creates a StockMarket object with a valid company name, adds a company to the stock market, 
//and then attempts to add a transaction with an invalid customer name. 
//If the size of the transactions is not 0, then the test fails and an error message is printed. 
void Test::Add_Customer_InvalidNameCompany() {
	StockMarket market("aa");
	market.Add_Customer("John", "Doe", 1234567890, 5000);
	market.Get_Company("Henkel");
	market.Add_Transaction(1, market.Get_Customer("John", "Doe"), 10, market.Get_Company("Invalid"), "buy");
	if (market.SizeOf_Transactions() != 0) {
		cerr << "# Test adding a transaction to the stock market with invalid company name failed. #" << endl;
	}
}

//This code tests the removal of a customer from a stock market. 
//It creates a StockMarket object and adds a customer to it. 
//It then attempts to remove the customer and checks if the customer is still present in the stock market. 
//If the customer is still present, an error message is printed. 
void Test::Remove_Customer_StockMarket() {
	StockMarket market("aa");
	market.Add_Customer("John", "Doe", 1234567890, 5000); //Add customer to stock market
	market.Remove_Customer("John", "Doe"); //Attempt to remove customer
	Customer* customer = market.Get_Customer("John", "Doe"); //Check if customer is still present
	if (customer != nullptr) { //If customer is still present, print error message
		cerr << "# Test removing a customer from the stock market failed. #" << endl;
	}
}

void Test::Remove_Company_StockMarket()
{
	StockMarket market("aa");
	market.Add_Company("ABC Company", 908443122, 4000, 100);
	market.Remove_Company("ABC Company");
	if (market.SizeOf_Companies()!=0) {
		cerr << "# Test Removing company from stock market #" << endl;
	}
}

//This code tests the ability to get a customer from the stock market.
void Test::Get_Customer_StockMarket() {
	//Create a StockMarket object with the symbol "aa"
	StockMarket market("aa");

	//Add a customer to the stock market
	market.Add_Customer("John", "Doe", 1234567890, 5000);

	//Get the customer from the stock market
	Customer* customer = market.Get_Customer("John", "Doe");

	//Check if the customer was successfully retrieved
	if (customer == nullptr) {
		cerr << "# Test getting a customer from the stock market failed. #" << endl;
	}
}

void Test::Get_Company_StockMarket()
{
	StockMarket market("aa");
	market.Add_Company("ABC Company", 908443122, 4000, 100);
	if (market.Get_Company("ABC Company")->Get_PhoneNumber() != 908443122) {
		cerr << "# Test Getting company from stock market #" << endl;
	}
}

//This code tests the ability to establish a company with a value of less than 5000 Euro. 
//It creates a StockMarket object called "market" and adds a customer with the name "John Doe" and a value of 5000. 
//It then adds a company called "ABC Company" with a value of 4000 and 100 shares. 
//Finally, it attempts to add a transaction with the customer and company, and if it fails, it prints an error message. 
void Test::EstablishCompany_Less5000Euro()
{
	StockMarket market("aa");
	market.Add_Customer("John", "Doe", 1234567890, 5000);
	market.Add_Company("ABC Company", 908443122, 4000, 100);
	if (market.Add_Transaction(1, market.Get_Customer("John", "Doe"), 10, market.Get_Company("ABC Company"), "buy") != 0) {
		cerr << "# Test establishing a company with value less than 5000 Euro #" << endl;
	}
}

void Test::The_SameName() {
	// Initialize a variable to store the number of exceptions thrown
	int a = 0;

	// Create a StockMarket object
	StockMarket market("aa");

	// Add a customer to the market
	market.Add_Customer("John", "Doe", 1234567890, 5000);

	// Add a company to the market
	market.Add_Company("ABC Company", 908443122, 6000, 200);

	// Try to add the same customer again
	try {
		market.Add_Customer("John", "Doe", 1234567890, 5000);
	}
	// Catch any exceptions thrown
	catch (exception ex) {
		// Increment the exception counter
		a += 1;
	}

	// Try to add the same company again
	try {
		market.Add_Company("ABC Company", 908443122, 6000, 200);
	}
	// Catch any exceptions thrown
	catch (exception ex) {
		// Increment the exception counter
		a += 1;
	}

	// If both attempts to add the same customer and company failed, print an error message
	if (a != 2) {
		cerr << "# Test with the Same Names failed #" << endl;
	}

}

void Test::Get_Transaction_StockMarket() {
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

void Test::ValuePerShare_Less2Euro()
{
	StockMarket market("aa");
	market.Add_Customer("John", "Doe", 901882716, 7800);
	market.Add_Company("ABC Company", 908443122, 6000, 200);
	market.Get_Customer("John", "Doe")->BuyShares(1, 50, market.Get_Company("ABC Company"), market.Get_StockMarket());

	if (market.SizeOf_Transactions() != 1) {
		cerr << "# Test buying shares using Customer class #" << endl;
	}
}

void Test::IsBankrupt()
{

}

void Test::BuyShares() {
	StockMarket market("aa");
	market.Add_Customer("John", "Doe", 901882716, 7800);
	market.Add_Company("ABC Company", 908443122, 6000, 200);
	market.Get_Customer("John", "Doe")->BuyShares(1, 50, market.Get_Company("ABC Company"),market.Get_StockMarket());

	if (market.SizeOf_Transactions() != 1) {
		cerr << "# Test buying shares using Customer class #" << endl;
	}

}

void Test::SellShares() {
	StockMarket market("aa");
	market.Add_Customer("John", "Doe", 901882716, 7800);
	market.Add_Company("ABC Company", 908443122, 6000, 200);
	market.Get_Customer("John", "Doe")->BuyShares(1, 50, market.Get_Company("ABC Company"), market.Get_StockMarket());
	market.Get_Customer("John", "Doe")->SellShares(2, 25, market.Get_Company("ABC Company"), market.Get_StockMarket());

	if (market.Get_Customer("John", "Doe")->Get_SharesCompany("ABC Company") != 25) {
		cerr << "# Test selling shares using Customer class #" << endl;
	}
}

void Test::SizeOfLists() {

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

void Test::SameID_OfTransaction()
{
	StockMarket market("aa");
	market.Add_Company("Company A", 1234567890, 10000, 1000);

	// Create a Customer object
	Customer customer("John", "Doe", 1000);
	Company* company = market.Get_Company("Company A");

	// Buy shares
	// Add a transaction to the stock market and get the transaction
	market.Add_Transaction(1, &customer, 100, company, "buy");
	market.Add_Transaction(1, &customer, 20, company, "buy");

	if (market.SizeOf_Transactions() != 1) {
		cerr << "# Test same ID transaction #" << endl;
	}
}

void Test::BuyingMoreShares_ThenExist()
{
	StockMarket market("aa");
	market.Add_Company("Company A", 1234567890, 10000, 100);

	// Create a Customer object
	Customer customer("John", "Doe", 100000);
	Company* company = market.Get_Company("Company A");

	// Buy shares
	// Add a transaction to the stock market and get the transaction
	market.Add_Transaction(1, &customer, 120, company, "buy");

	if (market.SizeOf_Transactions() != 0) {
		cerr << "# Test Buing more shares then there exist #" << endl;
	}

}

void Test::NotEnought_Money()
{
	StockMarket market("aa");
	market.Add_Company("Company A", 1234567890, 10000, 100);

	// Create a Customer object
	Customer customer("John", "Doe", 980);
	Company* company = market.Get_Company("Company A");

	// Buy shares
	// Add a transaction to the stock market and get the transaction
	market.Add_Transaction(1, &customer, 100, company, "buy");

	if (market.SizeOf_Transactions() != 0) {
		cerr << "# Test Not having enough money #" << endl;
	}
}

void Test::SellingShares_NotHavingIT()
{
	StockMarket market("aa");
	market.Add_Company("Company A", 1234567890, 10000, 100);

	// Create a Customer object
	Customer customer("John", "Doe", 450000);
	Company* company = market.Get_Company("Company A");

	// Buy shares
	// Add a transaction to the stock market and get the transaction
	market.Add_Transaction(1, &customer, 100, company, "sell");

	if (market.SizeOf_Transactions() != 0) {
		cerr << "# Test Not having enough shares #" << endl;
	}
}

void Test::LessThen_500Euro()
{
	StockMarket market;
	market.Add_Customer("John", "Doe", 1234567890, 480);
	market.Add_Company("Henkel", 903338291, 5000,1000);
}

void Test::Scenario1()
{
	StockMarket market("GPW");
	market.Add_Customer("John", "Doe", 908115627, 10000);
	market.Print_Customer("John","Doe");
}

