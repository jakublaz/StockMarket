#ifndef COMPANY_H
#define COMPANY_H

#include <string>
#include <list>
#include<algorithm>	//for Find functions
#include "Customer.h"
#include "Transactions.h"
#include "StockMarket.h"

using namespace std;

class Customer;
class Transaction;
class StockMarket;

class Company {
public:
	/*
	* Default constructor
	*/
	Company();
	/*
	* Copy constructor, using name, phoneNumber, and not nessesarry money and shares
	*/
	Company(string name, int phoneNumber, double money = 0, int shares = 0);
	/*
	* Default deconstructor, it should delete all lists, to ensure no memory leaks
	*/
	~Company();
	/*
	* Getter for money
	*/
	double Get_Money();
	/*
	* Getter for shares
	*/
	int Get_Shares();
	/*
	* Getter for name
	*/
	string Get_Name();
	/*
	* Getter for phoneNumber
	*/
	int Get_PhoneNumber();
	/*
	* Setter for money
	* It modifies earlier value
	*/
	void Set_Money(double amount);
	/*
	* Setter for shares
	* It modifies earlier value
	*/
	void Set_Shares(int shares);
	/*
	* Setter for name
	* It modifies earlier value
	*/
	void Set_Name(string name);
	/*
	* Setter for phoneNumber
	* It modifies earlier value
	*/
	void Set_PhoneNumber(int number);
	/*
	* Function that calculates how much should share cost, it divides money by shares
	* used in Update_Money();
	*/
	void Update_CostShare();
	/*
	* This function updates the the money this company is worth
	* the price must be higher then the costShare if we buy, lower if we sell
	*/
	void Update_Money(int shares, double money, string type);
	/*
	* Test Function
	* returns size of the list of customers
	*/
	int Sizeof_Customers();
	/*
	* Test Function
	* returns size of the list of transactions
	*/
	int Sizeof_Transactions();
	/*
	* Test Function
	* returns size of the list of stockmarkets
	*/
	int Sizeof_StockMarket();
	/*
	* checks if the companys costPerShare is lover than 0.5
	*/
	bool IsBancrupt();
	/*
	* getter for share cost
	*/
	double Get_ShareCost();
	/*
	* Getter for sold shares
	*/
	int Get_SoldShares();
	/*
	* Setter for sold shares
	*/
	void Set_SoldShares(int amount);
	/*
	* Updates sold shares
	*/
	void Update_SoldShares(int amount);
	/*
	* returns amount of not-bought shares
	*/
	int Get_FreeShares();
private:
	friend class StockMarket;	//friend musi by� zdefiniowany w Company
    /*
    * name of the customer
    */
    string name;
    /*
    * phonenumber of the customer
    */
    int phoneNumber;
    /*
    * amount of money company is worth
    */
    double money;
    /*
    * amount of shares, that are being distributed(all)
    */
    int shares;
	/*
	* To keep track of the shares  that were sold
	*/
	int soldshares;
    /*
    * amount of money you have to pay for 1 share
    */
    double costShare;
    /*
    * list of customers that invested in your company
    */
    list<Customer*> customers;
	/*
	* list of transactions that you took part in
	*/
	list<Transaction*> transactions;
	/*
	* list of stock markets you are in
	*/
    list<StockMarket*> stockmarkets;

	//this functions will be used to check if certain objects are not on the lists
    //will return nullptr if not found and pointer to element if found
	Customer* FindCustomer(string surname);
	Transaction* FindTransaction(string nameCustomer, string nameCompany, int ID);
	StockMarket* FindStockMarket(string name);

	/*
* Function to add customer to list customers
*/
	bool Add_Customer(Customer* newCustomer);
	/*
	* Function to remove customer from list customers
	*/
	bool Remove_Customer(string name, string surname);
	/*
	* Function to remove all transactions in order to delete this company
	*/
	void Remove_AllTransactions();
	/*
	* Function to remove all customers in order to delete this company
	*/
	void Remove_AllCustomers();
	/*
	* Function to remove all stockmarkets and transactions in them with this company in order to delete this company
	*/
	void Remove_StockMarkets(StockMarket* stockmarket);
	/*
	* Function to add transaction to list transactions
	*/
	bool Add_Transaction(Transaction* transaction);
	/*
	* Function to remove transaction
	*/
	bool Remove_Transaction(Transaction* transaction);
	/*
	* Function to add stockmarket to list stockmarkets
	*/
	bool Add_StockMarket(StockMarket* stockmarket);
	/*
	* Function to remove stockmarket from list stockmarkets
	*/
	bool Remove_StockMarket(string name);
	/*
	* test function instead of Remove_StockMarket
	*/
	bool Company_Remove_StockMarket(string name);
};

#endif /* COMPANY_H */



