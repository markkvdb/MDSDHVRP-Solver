//
// Created by Mark van der Broek on 27/02/2017.
//

#include "solution.ih"

Solution::Solution(Env *env, vector<Depot> depots, vector<Customer> customers)
:
    d_env(env),
    d_depots(depots),
    d_customers(customers)
{
    feasible();
}