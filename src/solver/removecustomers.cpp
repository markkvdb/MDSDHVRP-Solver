//
// Created by Mark van der Broek on 09/03/2017.
//

/**
 * @brief Delete the selected customers from the solution. The customers are deleted from all its routes.
 *
 * @param [in] solution             Solution
 * @param [in] customersToRemove    Vector of customer IDs to remove from the solution
 */

#include "solver.ih"

void Solver::removeCustomers(Solution &solution, std::vector<int> const &customersToRemove)
{
    for (int customerNumber: customersToRemove)
    {
        vector<pair<int, int>> &vehicleList = solution.getCustomers()[customerNumber].getVehicles();
        for (size_t vehicleNumber = 0; vehicleNumber != vehicleList.size(); ++vehicleNumber)
        {
            int depotID = vehicleList[vehicleNumber].first;
            int vehicleID = vehicleList[vehicleNumber].second;

            // Remove customer from vehicle (and route) and depot.
            int demand = solution.getDepots()[depotID].getVehicle(vehicleID).removeCustomer(customerNumber);
            solution.getDepots()[depotID].changeInventory(demand);
        }
        solution.getCustomers()[customerNumber].resetRemainingDemand();
        vehicleList.clear();
        int i = 0;
    }
}