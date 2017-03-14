//
// Created by Mark van der Broek on 03/03/2017.
//

#include "solver.ih"

void Solver::assignRouteToVehicle(int vehicleNumber, int depotNumber,
                                  std::vector<pair<int, int>> &depotCustomerAllocation)
{
    Depot &depot = d_env->d_currentSolution.getDepots()[depotNumber];
    Vehicle &vehicle = depot.getVehicle(vehicleNumber);


    int remainingCapacity = vehicle.getCapacity();

    // Create customer and drop off list
    std::vector<int> customerList{};
    std::vector<int> customerDropOff{};

    int seedCustomer = 0;
    int pickedCustomer = 0;

    // Check if there are still customers left to assign.
    if (not depotCustomerAllocation.empty()) {

        uniform_int_distribution<int> uni(0, depotCustomerAllocation.size()-1);

        seedCustomer = depotCustomerAllocation[uni(d_env->d_rng)].first;
        pickedCustomer = seedCustomer;
    }

    while (remainingCapacity > 0 && not depotCustomerAllocation.empty()) {
        d_env->d_currentSolution.getCustomers()[pickedCustomer].addToVehicle(depotNumber, vehicleNumber);

        addCustomer(pickedCustomer, remainingCapacity, customerList, customerDropOff, depotCustomerAllocation);

        getClosestCustomer(seedCustomer, pickedCustomer, depotCustomerAllocation);
    }

    pair<vector<int>, vector<int>> route = cheapestInsertion(depotNumber, customerList, customerDropOff);

    Route routeToAdd{d_env, depotNumber, route.first, route.second};
    depot.getVehicle(vehicleNumber).setRoute(routeToAdd);
}
