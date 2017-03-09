//
// Created by Mark van der Broek on 27/02/2017.
//

#ifndef ORACS_SOLUTION_H
#define ORACS_SOLUTION_H

#include <vector>
#include <iostream>
#include "depot.h"
#include "customer.h"
#include "init.h"

class Env;

class Solution {

    Env *                   d_env;
    std::vector<Depot>      d_depots;
    std::vector<Customer>   d_customers;
    bool                    d_feasible;
    double                  d_penalty;

public:
    Solution(Env *env);
    Solution(Env *env, std::vector<Depot> depots, std::vector<Customer> customer);

    void                    print();
    double                  totalCost();
    bool                    feasible();
    std::vector<Depot> &    getDepots();
    std::vector<Customer> & getCustomers();
    void                    addCustomer(Customer customer);
    void                    addDepot(Depot depot);

private:

};

inline std::vector<Depot> &Solution::getDepots()
{
    return d_depots;
}

inline std::vector<Customer> &Solution::getCustomers()
{
    return d_customers;
}

inline void Solution::addCustomer(Customer customer)
{
    d_customers.push_back(customer);
}

inline void Solution::addDepot(Depot depot)
{
    d_depots.push_back(depot);
}


#endif //ORACS_SOLUTION_H
