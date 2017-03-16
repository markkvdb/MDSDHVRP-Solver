//
// Created by Mark van der Broek on 03/03/2017.
//

#include "solver.ih"

void Solver::getClosestCustomer(int seedCustomer, int &pickedCustomer, vector<pair<int, int>> &depotCustomerAllocation)
{
    int minCustomer = pickedCustomer;
    double minDistance = numeric_limits<double>::max();

    for (pair<int, int> customer: depotCustomerAllocation)
    {
        if (customer.first == pickedCustomer)
            continue;

        if (d_env->d_distanceMatrix[seedCustomer][customer.first] < minDistance)
        {
            minCustomer = customer.first;
            minDistance = d_env->d_distanceMatrix[seedCustomer][customer.first];
        }
    }

    pickedCustomer = minCustomer;
}