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

class Solution {

    std::vector<Depot> d_depots;
    std::vector<Customer> d_customers;
    std::vector<std::vector<double>> d_distanceMatrix;

public:
    Solution();
    Solution(Init &init);

    void addDepot(Depot &depot);
    void addCustomer(Customer &customer);
    void initialSolution();
    void print();

private:
    std::vector<std::vector<int>> allocateCustomers();
    std::vector<int> getClosestDepots(int customer);

};

inline void Solution::addDepot(Depot &depot)
{
    d_depots.push_back(depot);
}

inline void Solution::addCustomer(Customer &customer)
{
    d_customers.push_back(customer);
}

#endif //ORACS_SOLUTION_H
