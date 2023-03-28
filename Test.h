#pragma once
#include<string>
#include<list>
#include<iostream>
#include<exception>
#include"Company.h"
#include "Customer.h"
#include "StockMarket.h"
#include "Transactions.h"

//za niska/wysoka cena kupna sprezeda¿y
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
	* posibble
	*/
	void EstablishCompany_Less5000Euro();
	/*
	* Test if you can buy a company with value per stock less then 2 Euro
	* not possible
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
	* Test if you are able to buy shares using method in customer
	* possible
	*/
	void BuyShares();
	/*
	* Test if you are able to sell shares using method in customer
	*/
	void SellShares();
	/*
	* Test if all sizes of the lists in diffrent clases are ok with right values
	*/
	void SizeOfLists();
	/*
	* Checks if a company/customer can have the same name as other company/customer
	*/
	void The_SameName();
	/*
	* Test if after adding 2 transactions with the same id, the 1 one should be added
	* the second one should be ignored
	*/
	void SameID_OfTransaction();
	/*
	* Test buing more shares then max amount there is
	* not posible
	*/
	void BuyingMoreShares_ThenExist();
	/*
	* Test buying for more money then you have
	* not posible
	*/
	void NotEnought_Money();
	/*
	* Test selling shares when you dont have enought shares bouoght
	* not posible
	*/
	void SellingShares_NotHavingIT();
	/*
	* Test adding a transaction when customer don't have 500Euro at least
	* not posible
	*/
	void LessThen_500Euro();
};