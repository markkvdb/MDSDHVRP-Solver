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

    Env *                               d_env;
    std::vector<Depot>                  d_depots;
    std::vector<Customer>               d_customers;

public:
    Solution() = delete;
    Solution(Env *env, std::vector<Depot> depots, std::vector<Customer> customer);

    void                    print();
    std::vector<Depot> &    getDepots();
    std::vector<Customer> & getCustomers();

private:
    double totalCost();

};

inline std::vector<Depot> &Solution::getDepots()
{
    return d_depots;
}

inline std::vector<Customer> &Solution::getCustomers()
{
    return d_customers;
}
#endif //ORACS_SOLUTION_H
