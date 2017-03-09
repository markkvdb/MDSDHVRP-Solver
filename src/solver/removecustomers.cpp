//
// Created by Mark van der Broek on 09/03/2017.
//

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
            double demand = solution.getDepots()[depotID].getVehicle(vehicleID).removeCustomer(customerNumber);
            solution.getDepots()[depotID].changeInventory(demand);
        }
        vehicleList.clear();
        int i = 0;
    }
}