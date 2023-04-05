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
            Customer newCustomer("John", "Doe", 1234567890, 5000);
            market.Add_Customer(&newCustomer);
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
            Customer newCustomer("Invalid", "Name", 1234567890, 5000);
            Company newCompany("Henkel", 901883722, 100000, 1210);
            market.Add_Customer(&newCustomer);
            market.Add_Company(&newCompany);
            market.Get_Company("Henkel");
            market.Add_Transaction(1, market.Get_Customer("John", "Doe"), 10, market.Get_Company("Henkel"), "buy");
            
            Assert::AreEqual(0, market.SizeOf_Transactions());
        }

        TEST_METHOD(Add_Company_StockMarket) {
            //Create a StockMarket object with the name "aa"
            StockMarket market("aa");

            //Add a company to the stock market with the name "Company A", a unique ID of 1234567890, 10,000 shares, and a share price of $1,000
            Company newCompany("Company A", 1234567890, 10000, 1000);
            market.Add_Company(&newCompany);

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
            Customer newCustomer("John", "Doe", 1234567890, 5000);
            Company newCompany("Henkel",908774368,12091,12);
            market.Add_Transaction(1, market.Get_Customer("John", "Doe"), 10, market.Get_Company("Invalid"), "buy");

            Assert::AreEqual(0, market.SizeOf_Transactions());
        }

        //This code tests the removal of a customer from a stock market. 
        //It creates a StockMarket object and adds a customer to it. 
        //It then attempts to remove the customer and checks if the customer is still present in the stock market. 
        TEST_METHOD(Remove_Customer_StockMarket) {
            StockMarket market("aa");
            Customer newCustomer("John", "Doe", 1234567890, 5000);
            market.Add_Customer(&newCustomer);

            market.Remove_Customer("John", "Doe");
            Customer* customer = market.Get_Customer("John", "Doe");

            Assert::IsNull(customer);
            
        }

        TEST_METHOD(Remove_Company_StockMarket) {
            StockMarket market("aa");
            Company newCompany("ABC Company", 908443122, 4000, 100);
            market.Add_Company(&newCompany);

            market.Remove_Company("ABC Company");
            Company* company = market.Get_Company("ABC Company");

            Assert::IsNull(company);
        }

        //This code tests the ability to get a customer from the stock market.
        TEST_METHOD(Get_Customer_StockMarket) {
            StockMarket market("aa");
            Customer newCustomer("John", "Doe", 1234567890, 5000);
            market.Add_Customer(&newCustomer);
            Customer* customer = market.Get_Customer("John", "Doe");

            Assert::IsNotNull(customer);
        }

        TEST_METHOD(Get_Company_StockMarket) {
            StockMarket market("aa");
            Company newCompany("ABC Company", 908443122, 4000, 100);
            market.Add_Company(&newCompany);

            Company* company = market.Get_Company("ABC Company");

            Assert::IsNotNull(company);
        }

        TEST_METHOD(ValuePerShare_Less2Euro) {
            StockMarket market("aa");
            Customer newCustomer("John", "Doe", 1234567890, 5000);
            Company newCompany("ABC Company", 908443122, 6000,4000);
            market.Add_Customer(&newCustomer);
            market.Add_Company(&newCompany);

            market.Get_Customer("John", "Doe")->BuyShares(1, 50, market.Get_Company("ABC Company"), market.Get_StockMarket(),"buy");

            Assert::AreEqual(0,market.SizeOf_Transactions());
        }

        TEST_METHOD(Buy_Shares) {
            StockMarket market("aa");
            Customer newCustomer("John", "Doe", 1234567890, 5000);
            Company newCompany("ABC Company", 908443122, 6000, 200);
            market.Add_Customer(&newCustomer);
            market.Add_Company(&newCompany);
            market.Get_Customer("John", "Doe")->BuyShares(1, 50, market.Get_Company("ABC Company"), market.Get_StockMarket(),"buy");

            Assert::AreEqual(market.SizeOf_Transactions(), 1);
        }

        TEST_METHOD(Sell_Shares) {
            StockMarket market("aa");
            Customer newCustomer("John", "Doe", 1234567890, 5000);
            Company newCompany("ABC Company", 908443122, 6000, 200);
            market.Add_Customer(&newCustomer);
            market.Add_Company(&newCompany);
            market.Get_Customer("John", "Doe")->BuyShares(1, 50, market.Get_Company("ABC Company"), market.Get_StockMarket(),"buy");
            market.Get_Customer("John", "Doe")->SellShares(2, 25, market.Get_Company("ABC Company"), market.Get_StockMarket(), "sell");

            Assert::AreEqual(25,market.Get_Customer("John", "Doe")->Get_SharesCompany("ABC Company"));
        }

        TEST_METHOD(Same_IDTransacion) {
            StockMarket market("aa");
            Company newCompany("Company A", 1234567890, 10000, 1000);
            market.Add_Company(&newCompany);

            // Create a Customer object
            Customer newCustomer("John", "Doe", 100092833,100000);
            market.Add_Customer(&newCustomer);


            // Buy shares
            // Add a transaction to the stock market and get the transaction
            market.Add_Transaction(1, market.Get_Customer("John","Doe"), 100, market.Get_Company("Company A"), "buy");
            market.Add_Transaction(1, market.Get_Customer("John", "Doe"), 20, market.Get_Company("Company A"), "buy");

            Assert::AreEqual(market.SizeOf_Transactions(), 1);  //zwraca 0
        }

        TEST_METHOD(BuyingMoreShares_ThenExist) {
            StockMarket market("aa");
            Customer newCustomer("John", "Doe", 1234567890, 5000);
            Company newCompany("ABC Company", 908443122, 6000, 200);
            market.Add_Customer(&newCustomer);
            market.Add_Company(&newCompany);

            // Buy shares
            // Add a transaction to the stock market and get the transaction
            market.Add_Transaction(1, market.Get_Customer("John", "Doe"), 120, market.Get_Company("Company A"), "buy");

            Assert::AreEqual(market.SizeOf_Transactions(), 0);
        }

        TEST_METHOD(Customer_NotEnought_Money) {
            StockMarket market("aa");

            Customer newCustomer("John", "Doe", 1234567890, 5000);
            Company newCompany("ABC Company", 908443122, 6000, 200);
            market.Add_Customer(&newCustomer);
            market.Add_Company(&newCompany);

            // Buy shares
            // Add a transaction to the stock market and get the transaction
            market.Add_Transaction(1, market.Get_Customer("John", "Doe"), 100, market.Get_Company("Company A"), "buy");

            Assert::AreEqual(market.SizeOf_Transactions(), 0);
        }

        TEST_METHOD(SellingShares_NotHavingIT) {
            StockMarket market("aa");
            Customer newCustomer("John", "Doe", 1234567890, 5000);
            Company newCompany("ABC Company", 908443122, 6000, 200);
            market.Add_Customer(&newCustomer);
            market.Add_Company(&newCompany);

            // Buy shares
            // Add a transaction to the stock market and get the transaction
            market.Add_Transaction(1, market.Get_Customer("John", "Doe"), 100, market.Get_Company("Company A"), "sell");

            Assert::AreEqual(market.SizeOf_Transactions(), 0);
        }

        TEST_METHOD(Scenario_1) {
            StockMarket market("GPW");
            Customer newCustomer("John", "Doe", 1234567890, 5000);
            Company newCompany("ABC Company", 908443122, 6000, 200);
            market.Add_Customer(&newCustomer);
            market.Add_Company(&newCompany);

            market.Add_Transaction(1, market.Get_Customer("John", "Doe"), 10, market.Get_Company("ABC Company"), "buy");

            Customer* customer = market.Get_Customer("John", "Doe");
            Company* company = market.Get_Company("ABC Company");
            Transaction* transaction = market.Get_Transaction("Doe", "ABC Company", 1);

            Assert::IsNotNull(customer);
            Assert::AreEqual((string)customer->Get_Name(), (string)"John");
            Assert::AreEqual((string)customer->Get_Surname(), (string)"Doe");
            Assert::AreEqual(customer->Get_PhoneNumber(), 1234567890);
            Assert::AreEqual(customer->Get_PocketMoney(), (double)5000);

            Assert::IsNotNull(company);
            Assert::AreEqual((string)company->Get_Name(),(string)"ABC Company");
            Assert::AreEqual(company->Get_Money(), (double)6000);
            Assert::AreEqual(company->Get_Shares(), 200);

            Assert::IsNotNull(transaction);
            Assert::AreEqual(transaction->Get_ID(), 1);
            Assert::AreEqual(ceil(transaction->Get_Amount()),(double)300);
            Assert::AreEqual(transaction->Get_Shares(), 10);
            Assert::AreEqual((string)transaction->Get_Type(),(string)"buy");
        }

        TEST_METHOD(SizeOfList) {
            StockMarket a("GPW");

            //Add 2 Customers
            Customer customer1("Jacek", "Zak", 990889675, 800000);
            //test 2 functions with the same functionality
            Customer customer2("Anna", "Maria", 898954637, 90000);
            //a.Get_Customer("Anna", "Maria")->Set_PocketMoney(90000);
            //Add Company with 2000 shares and 50000 in money
            Company company1("Henkel", 983883001, 50000, 2000);

            a.Add_Company(&company1);
            a.Add_Customer(&customer1);
            a.Add_Customer(&customer2);

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

        TEST_METHOD(Scenario_2) {
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
            Assert::AreEqual(3, customer1.Sizeof_Transactions());
            Assert::AreEqual(2, customer1.Sizeof_Companies());
            Assert::AreEqual(2, customer1.Sizeof_StockMarkets());
            Assert::AreEqual((double)77700, customer1.Get_PocketMoney());
            Assert::AreEqual((double)2300, customer1.Get_InvestedMoney());

            //stockmarket
            Assert::AreEqual((double)250, b.GetInvestedMoney());
            Assert::AreEqual((double)2050, a.GetInvestedMoney());
        }
	};
}
