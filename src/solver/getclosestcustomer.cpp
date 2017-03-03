//
// Created by Mark van der Broek on 03/03/2017.
//

#include "solver.ih"

void Solver::getClosestCustomer(int &pickedCustomer, std::vector<int> &depotCustomerAllocation)
{
    // TODO It can happen that a customer is not completely served, so it will remain in depotCustomerAllocation
    int minCustomer = 0;
    double minDistance = numeric_limits<double>::max();

    for (int customer: depotCustomerAllocation)
    {
        if (customer == pickedCustomer)
            continue;

        if (d_env->d_distanceMatrix[pickedCustomer][customer] < minDistance)
        {
            minCustomer = customer;
            minDistance = d_env->d_distanceMatrix[pickedCustomer][customer];
        }
    }

    pickedCustomer = minCustomer;
}