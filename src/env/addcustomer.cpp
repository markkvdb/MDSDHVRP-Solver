//
// Created by Mark van der Broek on 03/03/2017.
//

#include "env.ih"

void Env::addCustomer(Customer &customer)
{
    d_customers.push_back(customer);
}
