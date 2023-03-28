#pragma once
#include<string>
#include<list>
#include<iostream>
#include<exception>
#include"Company.h"
#include "Customer.h"
#include "StockMarket.h"
#include "Transactions.h"
class Test
{
	/*
	* Test adding a customer to the stock market
	*/
	void Add_Customer_StockMarket();
	/*
	* Test adding a company to the stock market
	*/
	void Add_Company_StockMarket();
	/*
	* Test adding a transaction to the stock market with invalid customer name
	*/
	void Add_Customer_InvalidNameCustomer();
	/*
	* Test adding a transaction to the stock market with invalid company name
	*/
	void Add_Customer_InvalidNameCompany();
	/*
	* Test removing a customer from the stock market
	*/
	void Remove_Customer_StockMarket();
	/*
	* Test removing a company from the stock market
	*/
	void Remove_Company_StockMarket();
	/*
	* Test getting a customer from the stock market
	*/
	void Get_Customer_StockMarket();
	/*
	* Test getting a company from the stock market
	*/
	void Get_Company_StockMarket();
	/*
	* Test getting a transaction from the stock market
	*/
	void Get_Transaction_StockMarket();
	/*
	* Test if you can establish company having less then 5000 Euro
	*/
	void EstablishCompany_Less5000Euro();
	/*
	* Test if  yoou can buy a company with value per stock less then 2 Euro
	*/
	void ValuePerShare_Less2Euro();
	/*
	* Test if a company is buncrupt, and return to investors
	*/
	void IsBankrupt();
	/*
	* Test size of lists and their change
	*/
	void Transaction_Over10Euro();
	/*
	* Test size of lists and their change
	*/
	void The_SameName();
	/*
	* Test if you are able to buy shares using method in customer
	*/
	void BuyShares();
	/*
	* Test if you are able to sell shares using method in customer
	*/
	void SellShares();

	void SizeOfLists();

	void SameID_OfTransaction();
};