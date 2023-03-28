#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include "Customer.h"
#include "Company.h"
#include "StockMarket.h"
#include<string>
//check if money is over 10 Euros for a transaction
//buing more shares then there exists
//buying for more moeny then you have

using namespace std;

class Customer;
class Company;
class StockMarket;

class Transaction {
    //In this class there are no setters, because once  defined operation can't  be modified
public:

    /*
    * Constructor for this class, it sets id, amount, shares and pointers to customer, company, strock market
    */
    Transaction(int ID, int shares,Customer* customer, Company* company, StockMarket* stock_market);
    /*
    *Default Deconstructor
    */
    ~Transaction();
    /*
    * It is a getter for Id
    */
    int Get_ID();
    /*
    * It is a getter for amount
    * if the amount is under or  over the limit we have to use random
    */
    double Get_Amount();    
    /*
    * It is a getter for shares
    */
    int Get_Shares();
    /*
    * It is a getter for type of transaction
    */
    string Get_Type();
    /*
    * It is a function that will print all nessesary information about this transaction, amount, shares, Id, and parts involved
    */
    void Print_Transaction();
    /*
    * It is a getter for customer
    */
    Customer* Get_Customer();
    /*
    * It is a getter for company
    */
    Company* Get_Company();
    /*
    * It is a getter for stock_market
    */
    StockMarket* Get_StockMarket();
    /*
    * 
    */
    bool HaveEnough_Money();


    bool HaveEnough_Shares();
private:
    /*
    * Id of this transaction
    */
    int ID;
    /*
    * Amount of money that will be used in this transaction
    */
    double amount;
    /*
     * Amount of shares that will be bought/sold int this transaction
     */
    int shares;
    /*
    * Type of the transaction
    */
    string type;
    /*
    * Pointer to customer buying or selling
    * can be buy/sell
    */
    Customer* customer;
    /*
    * Pointer to company being sold or bought
    */
    Company* company;
    /*
    * Pointer to stockmarket where this is being done
    */
    StockMarket* stock_market;
    
};

#endif /* TRANSACTIONS_H */
