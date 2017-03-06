//
// Created by Mark van der Broek on 03/03/2017.
//

#include "solver.ih"

// TODO Maybe this is unnecessary if splitting doesn't happen often.

vector<int> Solver::getClosestDepots(int customer)
{
    vector<int> orderedDepots(d_env->d_depots.size());
    iota(std::begin(orderedDepots), std::end(orderedDepots), 0);

    sort(begin(orderedDepots), end(orderedDepots),
         [&](int lhs, int rhs)
         {
             return d_env->d_distanceMatrix[customer][lhs + d_env->d_customers.size()]
                    < d_env->d_distanceMatrix[customer][rhs + d_env->d_customers.size()];
         });

    return orderedDepots;
}

