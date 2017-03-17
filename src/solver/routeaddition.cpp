//
// Created by Mark van der Broek on 16/03/2017.
//

#include "solver.ih"

void Solver::routeAddition(Solution &s)
{
    double minTotalCost = s.totalCost();
    int minCustomerID = -1;
    Solution bestSolution = s;
    for (Customer &customer: s.getCustomers())
    {
        if (customer.getVehicles().size() == 1)
            continue;

        Solution newSolution = s;

        vector<int> customerToDelete = {customer.getId()};
        removeCustomers(newSolution, customerToDelete);
        reinsert(newSolution, customerToDelete, false);

        if (newSolution.totalCost() < minTotalCost)
        {
            minTotalCost = newSolution.totalCost();
            minCustomerID = customer.getId();
            bestSolution = newSolution;
        }
    }
    s = bestSolution;
}