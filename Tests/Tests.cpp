#include "pch.h"
#include "CppUnitTest.h"
#include "D:/aa  studia/sem2/EOOP/projekt/StockMarket/StockMarket.h"
#include "D:/aa  studia/sem2/EOOP/projekt/StockMarket/Customer.h"
#include "D:/aa  studia/sem2/EOOP/projekt/StockMarket/Company.h"
#include "D:/aa  studia/sem2/EOOP/projekt/StockMarket/Transactions.h"
#include "D:/aa  studia/sem2/EOOP/projekt/StockMarket/timer.h"
#include "D:/aa  studia/sem2/EOOP/projekt/StockMarket/StockMarket.cpp"
#include "D:/aa  studia/sem2/EOOP/projekt/StockMarket/Customer.cpp"
#include "D:/aa  studia/sem2/EOOP/projekt/StockMarket/Company.cpp"
#include "D:/aa  studia/sem2/EOOP/projekt/StockMarket/Transactions.cpp"
#include "D:/aa  studia/sem2/EOOP/projekt/StockMarket/timer.cpp"

#include<cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Tests
{
	TEST_CLASS(Tests)
	{
	public:
		
		TEST_METHOD(Add_Customer_StockMarket)
		{
            StockMarket market("aa");
            // Add a customer to the stock market with the name "John Doe", ID 1234567890, and a balance of 5000.
            market.Add_Customer("John", "Doe", 1234567890, 5000);
            // Retrieve the customer from the stock market
            Customer* customer = market.Get_Customer("John", "Doe");
            // Check if the customer was added successfully
            Assert::IsNotNull(customer);
            Assert::AreEqual(string("John"), customer->Get_Name());
            Assert::AreEqual(string("Doe"), customer->Get_Surname());
            Assert::AreEqual(1234567890, customer->Get_PhoneNumber());
            Assert::AreEqual((double)5000, customer->Get_PocketMoney());
		}

        TEST_METHOD(Add_Customer_InvalidNameCustomer) {

            StockMarket market("aa");
            market.Add_Customer("Invalid", "Name", 1234567890, 5000);
            market.Get_Company("Henkel");
            market.Add_Transaction(1, market.Get_Customer("John", "Doe"), 10, market.Get_Company("Henkel"), "buy");
            
            Assert::AreEqual(0, market.SizeOf_Transactions());
        }

        TEST_METHOD(Add_Company_StockMarket) {
            //Create a StockMarket object with the name "aa"
            StockMarket market("aa");

            //Add a company to the stock market with the name "Company A", a unique ID of 1234567890, 10,000 shares, and a share price of $1,000
            market.Add_Company("Company A", 1234567890, 10000, 1000);

            //Retrieve the company from the stock market
            Company* company = market.Get_Company("Company A");

            Assert::IsNotNull(company);
            Assert::AreEqual(string("Company A"), company->Get_Name());
            Assert::AreEqual(1234567890, company->Get_PhoneNumber());
            Assert::AreEqual((double)10000, company->Get_Money());
            Assert::AreEqual(1000, company->Get_Shares());
            Assert::AreEqual((double)10, company->Get_ShareCost());
        }

        //This code tests the ability to add a transaction to the stock market with an invalid company name. 
        //It creates a StockMarket object with a valid company name, adds a company to the stock market, 
        //and then attempts to add a transaction with an invalid customer name. 
        TEST_METHOD(Add_Customer_InvalidNameCompany) {
            StockMarket market("aa");
            market.Add_Customer("John", "Doe", 1234567890, 5000);
            market.Get_Company("Henkel");
            market.Add_Transaction(1, market.Get_Customer("John", "Doe"), 10, market.Get_Company("Invalid"), "buy");

            Assert::AreEqual(0, market.SizeOf_Transactions());
        }

        //This code tests the removal of a customer from a stock market. 
        //It creates a StockMarket object and adds a customer to it. 
        //It then attempts to remove the customer and checks if the customer is still present in the stock market. 
        TEST_METHOD(Remove_Customer_StockMarket) {
            StockMarket market("aa");
            market.Add_Customer("John", "Doe", 1234567890, 5000);
            market.Remove_Customer("John", "Doe");
            Customer* customer = market.Get_Customer("John", "Doe");

            Assert::IsNull(customer);
        }

        TEST_METHOD(Remove_Company_StockMarket) {
            StockMarket market("aa");
            market.Add_Company("ABC Company", 908443122, 4000, 100);
            market.Remove_Company("ABC Company");
            Company* company = market.Get_Company("ABC Company");

            Assert::IsNull(company);
        }

        //This code tests the ability to get a customer from the stock market.
        TEST_METHOD(Get_Customer_StockMarket) {
            StockMarket market("aa");
            market.Add_Customer("John", "Doe", 1234567890, 5000);
            Customer* customer = market.Get_Customer("John", "Doe");

            Assert::IsNotNull(customer);
        }

        TEST_METHOD(Get_Company_StockMarket) {
            StockMarket market("aa");
            market.Add_Company("ABC Company", 908443122, 4000, 100);
            Company* company = market.Get_Company("ABC Company");

            Assert::IsNotNull(company);
        }
        
        TEST_METHOD(The_SameName) {
            StockMarket market("aa");
            market.Add_Customer("John", "Doe", 1234567890, 5000);
            market.Add_Company("ABC Company", 908443122, 6000, 200);

            market.Add_Customer("John", "Doe", 1234567890, 5000);
            market.Add_Company("ABC Company", 908443122, 6000, 200);

            Assert::AreEqual(market.SizeOf_Companies(), 1);
            Assert::AreEqual(market.SizeOf_Customers(), 1);
        }

        TEST_METHOD(ValuePerShare_Less2Euro) {
            StockMarket market("aa");
            market.Add_Customer("John", "Doe", 901882716, 7800);
            market.Add_Company("ABC Company", 908443122, 3000, 2000);
            market.Get_Customer("John", "Doe")->BuyShares(1, 50, market.Get_Company("ABC Company"), market.Get_StockMarket());

            Assert::AreEqual(market.SizeOf_Transactions(), 0);
        }

        TEST_METHOD(Buy_Shares) {
            StockMarket market("aa");
            market.Add_Customer("John", "Doe", 901882716, 7800);
            market.Add_Company("ABC Company", 908443122, 6000, 200);
            market.Get_Customer("John", "Doe")->BuyShares(1, 50, market.Get_Company("ABC Company"), market.Get_StockMarket());

            Assert::AreEqual(market.SizeOf_Transactions(), 1);
        }

        TEST_METHOD(Sell_Shares) {
            StockMarket market("aa");
            market.Add_Customer("John", "Doe", 901882716, 7800);
            market.Add_Company("ABC Company", 908443122, 6000, 200);
            market.Get_Customer("John", "Doe")->BuyShares(1, 50, market.Get_Company("ABC Company"), market.Get_StockMarket());
            market.Get_Customer("John", "Doe")->SellShares(2, 25, market.Get_Company("ABC Company"), market.Get_StockMarket());

            Assert::AreEqual(market.Get_Customer("John", "Doe")->Get_SharesCompany("ABC Company"), 25);
        }

        TEST_METHOD(Same_IDTransacion) {
            StockMarket market("aa");
            market.Add_Company("Company A", 1234567890, 10000, 1000);

            // Create a Customer object
            Customer customer("John", "Doe", 1000);
            Company* company = market.Get_Company("Company A");

            // Buy shares
            // Add a transaction to the stock market and get the transaction
            market.Add_Transaction(1, &customer, 100, company, "buy");
            market.Add_Transaction(1, &customer, 20, company, "buy");

            Assert::AreEqual(market.SizeOf_Transactions(), 1);
        }

        TEST_METHOD(BuyingMoreShares_ThenExist) {
            StockMarket market("aa");
            market.Add_Company("Company A", 1234567890, 10000, 100);

            // Create a Customer object
            Customer customer("John", "Doe", 100000);
            Company* company = market.Get_Company("Company A");

            // Buy shares
            // Add a transaction to the stock market and get the transaction
            market.Add_Transaction(1, &customer, 120, company, "buy");

            Assert::AreEqual(market.SizeOf_Transactions(), 0);
        }

        TEST_METHOD(Customer_NotEnought_Money) {
            StockMarket market("aa");
            market.Add_Company("Company A", 1234567890, 10000, 100);

            // Create a Customer object
            Customer customer("John", "Doe", 980);
            Company* company = market.Get_Company("Company A");

            // Buy shares
            // Add a transaction to the stock market and get the transaction
            market.Add_Transaction(1, &customer, 100, company, "buy");

            Assert::AreEqual(market.SizeOf_Transactions(), 0);
        }

        TEST_METHOD(SellingShares_NotHavingIT) {
            StockMarket market("aa");
            market.Add_Company("Company A", 1234567890, 10000, 100);

            // Create a Customer object
            Customer customer("John", "Doe", 450000);
            Company* company = market.Get_Company("Company A");

            // Buy shares
            // Add a transaction to the stock market and get the transaction
            market.Add_Transaction(1, &customer, 100, company, "sell");

            Assert::AreEqual(market.SizeOf_Transactions(), 0);
        }

        TEST_METHOD(Scenario_1) {
            StockMarket market("GPW");
            market.Add_Customer("John", "Doe", 908115627, 10000);
            market.Add_Company("ABC Company", 908116272, 10009, 120);
            market.Add_Transaction(1, market.Get_Customer("John", "Doe"), 10, market.Get_Company("ABC Company"), "buy");

            Customer* customer = market.Get_Customer("John", "Doe");
            Company* company = market.Get_Company("ABC Company");
            Transaction* transaction = market.Get_Transaction("Doe", "ABC Company", 1);

            Assert::IsNotNull(customer);
            Assert::AreEqual((string)customer->Get_Name(), (string)"John");
            Assert::AreEqual((string)customer->Get_Surname(), (string)"Doe");
            Assert::AreEqual(customer->Get_PhoneNumber(), 908115627);
            Assert::AreEqual(customer->Get_PocketMoney(), (double)10000);

            Assert::IsNotNull(company);
            Assert::AreEqual((string)company->Get_Name(),(string)"ABC Company");
            Assert::AreEqual(company->Get_Money(), (double)10009);
            Assert::AreEqual(company->Get_Shares(), 120);

            //narazie nie bêdzie dzia³a³o bo nie jest zdefiniowane dodawanie tranzakcji
            Assert::IsNotNull(transaction);
            Assert::AreEqual(transaction->Get_ID(), 1);
            Assert::AreEqual(ceil(transaction->Get_Amount()),(double)835);
            Assert::AreEqual(transaction->Get_Shares(), 10);
            Assert::AreEqual((string)transaction->Get_Type(),(string)"buy");
        }

        TEST_METHOD(SizeOfList) {
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

            Assert::AreEqual(a.SizeOf_Companies(), 1);
            Assert::AreEqual(a.SizeOf_Customers(), 2);
            Assert::AreEqual(a.SizeOf_Transactions(), 3);   //nie dzia³a nie ustawiona funkcja

            Assert::AreEqual(a.Get_Company("Henkel")->Sizeof_Customers(), 2);
            Assert::AreEqual(a.Get_Company("Henkel")->Sizeof_Transactions(), 3);
            Assert::AreEqual(a.Get_Company("Henkel")->Sizeof_StockMarket(), 1);

            Assert::AreEqual(a.Get_Customer("Anna", "Maria")->Sizeof_Companies(), 1);
            Assert::AreEqual(a.Get_Customer("Anna", "Maria")->Sizeof_Transactions(), 1);
            Assert::AreEqual(a.Get_Customer("Anna", "Maria")->Sizeof_StockMarkets(), 1);

            Assert::AreEqual(a.Get_Customer("Jacek", "Zak")->Sizeof_Companies(), 1);
            Assert::AreEqual(a.Get_Customer("Jacek", "Zak")->Sizeof_Transactions(), 2);
            Assert::AreEqual(a.Get_Customer("Jacek", "Zak")->Sizeof_StockMarkets(), 1);

            Assert::AreEqual(a.Get_Transaction("Zak", "Henkel", 2)->Get_StockMarket()->Get_Name(), a.Get_Name());
            Assert::AreEqual(a.Get_Transaction("Zak", "Henkel", 2)->Get_Customer()->Get_Name(), a.Get_Customer("Jacek", "Zak")->Get_Name());
            Assert::AreEqual(a.Get_Transaction("Zak", "Henkel", 2)->Get_Company()->Get_Name(), a.Get_Company("Henkel")->Get_Name());
        }

        TEST_METHOD(Bancrupt) {
            Assert::AreEqual(1, 0);
        }

        TEST_METHOD(Add2Markets_1Customer) {
            StockMarket market("aaa");
            StockMarket market2("bbb");
            market.Add_Customer("John", "Doe", 908773647, 12000);

            
        }
	};
}
