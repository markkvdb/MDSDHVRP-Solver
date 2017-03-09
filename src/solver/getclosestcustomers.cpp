//
// Created by Mark van der Broek on 09/03/2017.
//

#include "solver.ih"

vector<int> Solver::getClosestCustomers(int seedCustomer, int q)
{
    vector<int> orderedCustomers(d_env->d_currentSolution.getCustomers().size());
    iota(std::begin(orderedCustomers), std::end(orderedCustomers), 0);

    // Sort customers on distance to seed customer (including seed customer)
    sort(begin(orderedCustomers), end(orderedCustomers),
         [&](int lhs, int rhs)
         {
             return d_env->d_distanceMatrix[seedCustomer][lhs] < d_env->d_distanceMatrix[seedCustomer][rhs];
         });

    return vector<int>{begin(orderedCustomers), begin(orderedCustomers) + q};
}