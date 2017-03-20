//
// Created by Mark van der Broek on 20/03/2017.
//

/**
 * @brief Find the number of splits in the solution and divide it by the total number of customers.
 *
 * @return Number of splits divided by number of customers
 */

#include "solution.ih"

double Solution::ratioSplits()
{
    double numberOfSplits = 0.0;
    for (Customer &customer: d_customers)
    {
        numberOfSplits += (customer.getVehicles().size() - 1);
    }
    return numberOfSplits / d_customers.size();
}