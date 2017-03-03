//
// Created by Mark van der Broek on 03/03/2017.
//

#include "solver.ih"

void Solver::initialSolution()
{
    // Create Depot-Customer allocation (depotCustomerAllocation is a m by something)
    vector<vector<int>> depotCustomerAllocation = allocateCustomers();

    // For each depot
    for (int depotNumber = 0; depotNumber != d_env->d_depots.size(); ++depotNumber)
    {
        // Sorted vehicle list
        vector<int> sortedVehicleList = sortVehicleList(depotNumber);

        for (int vehicleNumber: sortedVehicleList)
        {
            assignRouteToVehicle(vehicleNumber, depotNumber, depotCustomerAllocation[depotNumber]);
        }
    }
    
}
