//
// Created by Mark van der Broek on 01/03/2017.
//

#include "solution.ih"

// TODO Maybe this is unnecessary if splitting doesn't happen often.

vector<int> Solution::getClosestDepots(int customer)
{
    vector<int> orderedDepots(d_depots.size());
    iota(std::begin(orderedDepots), std::end(orderedDepots), 0);

    sort(begin(orderedDepots), end(orderedDepots),
         [&](int lhs, int rhs)
         {
            return d_distanceMatrix[customer][lhs + d_customers.size()] < d_distanceMatrix[customer][lhs + d_customers.size()];
         });

    return orderedDepots;
}
