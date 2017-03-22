//
// Created by Mark van der Broek on 03/03/2017.
//

/**
 * @brief Find the ordered list of depots based on the distance to the customer.
 *
 * @param [in] customer Customer ID
 *
 * @return Vector of ordered depot IDs based on the distance to the given customer
 */

#include "solver.ih"

// TODO Maybe this is unnecessary if splitting doesn't happen often.

vector<int> Solver::getClosestDepots(int customer)
{
    vector<int> orderedDepots(d_env->d_currentSolution.getDepots().size());
    iota(std::begin(orderedDepots), std::end(orderedDepots), 0);

    sort(begin(orderedDepots), end(orderedDepots),
         [&](int lhs, int rhs)
         {
             return d_env->distanceMatrix(customer, lhs + d_env->d_currentSolution.getCustomers().size())
                    < d_env->distanceMatrix(customer, rhs + d_env->d_currentSolution.getCustomers().size());
         });

    return orderedDepots;
}

