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

/**
 * The Solution class holds the actual solution. This consist of the data structure as designed, so a vector of depots
 * and a vector customers.
 */
class Solution {

    Env *                   d_env; /*!< Environment pointer */
    std::vector<Depot>      d_depots; /*!< Vector of depots of the solution */
    std::vector<Customer>   d_customers; /*!< Vector of customers of the solution */
    bool                    d_feasible; /*!< Indicates whether the solution is feasible or not */
    double                  d_penalty; /*!< The total penalty cost of the solution */

public:
    Solution(Env *env);
    Solution(Env *env, std::vector<Depot> depots, std::vector<Customer> customer);

    void                    print();
    double                  ratioSplits();
    double                  totalCost();
    double                  cost();
    bool                    feasible();
    std::vector<Depot> &    getDepots();
    std::vector<Customer> & getCustomers();
    void                    addCustomer(Customer customer);
    void                    addDepot(Depot depot);

private:

};

/**
 * Gets the vector of depots.
 * @return Vector of depots
 */
inline std::vector<Depot> &Solution::getDepots()
{
    return d_depots;
}

/**
 * Get the vector of customers.
 * @return Vector of Customers
 */
inline std::vector<Customer> &Solution::getCustomers()
{
    return d_customers;
}

/**
 * Adds customer to the solution.
 * @param customer Customer to add
 */
inline void Solution::addCustomer(Customer customer)
{
    d_customers.push_back(customer);
}

/**
 * Adds depot to the solution.
 * @param depot Depot to add
 */
inline void Solution::addDepot(Depot depot)
{
    d_depots.push_back(depot);
}



#endif //ORACS_SOLUTION_H
