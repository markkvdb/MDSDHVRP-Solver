//
// Created by Mark van der Broek on 03/03/2017.
//

#include "solver.ih"

void Solver::initialSolution()
{
    // Create Depot-Customer allocation (depotCustomerAllocation is a m by something)
    pair<vector<vector<int>>, vector<vector<double>>> depotAllocation = allocateCustomers();
    vector<vector<int>> depotCustomerAllocation = depotAllocation.first;
    vector<vector<double>> depotCustomerDemand = depotAllocation.second;

    // For each depot
    for (int depotNumber = 0; depotNumber != d_env->d_currentSolution.getDepots().size(); ++depotNumber)
    {
        // Sorted vehicle list
        vector<int> sortedVehicleList = sortVehicleList(depotNumber);

        for (int vehicleNumber: sortedVehicleList)
        {
            assignRouteToVehicle(vehicleNumber, depotNumber, depotCustomerAllocation[depotNumber],
                                 depotCustomerDemand[depotNumber]);
        }

        d_env->d_currentSolution.getDepots()[depotNumber].updateInventory();
    }


    d_env->d_bestSolution = d_env->d_currentSolution;
    d_env->d_newSolution = d_env->d_currentSolution;
}
