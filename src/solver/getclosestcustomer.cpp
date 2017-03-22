//
// Created by Mark van der Broek on 03/03/2017.
//

/**
 * @brief Finds the closest customer to the seed customer in the depot customer allocation list.
 *
 * @param [in] seedCustomer             The seed customer
 * @param [out] pickedCustomer          The closest customer to the seed customer of the remaining customers
 * @param [in] depotCustomerAllocation  The leftover depot customer allocation list
 */

#include "solver.ih"

void Solver::getClosestCustomer(int seedCustomer, int &pickedCustomer, vector<pair<int, int>> &depotCustomerAllocation)
{
    int minCustomer = pickedCustomer;
    double minDistance = numeric_limits<double>::max();

    for (pair<int, int> customer: depotCustomerAllocation)
    {
        if (customer.first == pickedCustomer)
            continue;

        if (d_env->distanceMatrix(seedCustomer, customer.first) < minDistance)
        {
            minCustomer = customer.first;
            minDistance = d_env->distanceMatrix(seedCustomer, customer.first);
        }
    }

    pickedCustomer = minCustomer;
}