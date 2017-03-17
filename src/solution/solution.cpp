//
// Created by Mark van der Broek on 27/02/2017.
//

/**
 * @brief Constructor
 *
 * @param [in] env          Environment pointer
 * @param [in] depots       Vector of depots
 * @param [in] customers    Vector of customers
 */

#include "solution.ih"

Solution::Solution(Env *env, vector<Depot> depots, vector<Customer> customers)
:
    d_env(env),
    d_depots(depots),
    d_customers(customers)
{
    feasible();
}