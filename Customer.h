#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Company.h"

class Company;

class Customer {
public:
    Customer();


private:
    Company* company;
};

#endif /* CUSTOMER_H */
