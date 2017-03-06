//
// Created by Mark van der Broek on 03/03/2017.
//

#include "solver.ih"

void Solver::assignRouteToVehicle(int vehicleNumber, int depotNumber,
                                  std::vector<int> &depotCustomerAllocation, std::vector<double> &depotCustomerDemand)
{
    double remainingCapacity = d_env->d_depots[depotNumber].getVehicle(vehicleNumber).getCapacity();

    // Create customer and drop off list
    std::vector<int> customerList{};
    std::vector<double> customerDropOff{};

    // Uncomment this if you don't want fixed seed value and change rng(1) to rng(rd);
    // random_device rd;
    mt19937 rng(1);
    std::uniform_int_distribution<int> uni(0, depotCustomerAllocation.size());

    int pickedCustomer = depotCustomerAllocation[uni(rng)];

    while (remainingCapacity > 0 && not depotCustomerAllocation.empty())
    {
        // TODO We don't have unique vehicle numbers yet
        d_env->d_customers[pickedCustomer].addToVehicle(vehicleNumber);

        addCustomer(pickedCustomer, remainingCapacity, customerList, customerDropOff,
                    depotCustomerAllocation, depotCustomerDemand);

        getClosestCustomer(pickedCustomer, depotCustomerAllocation);
    }

    // TODO Cheapest insertion
    pair<vector<int>, vector<double>> route = cheapestInsertion(depotNumber, customerList, customerDropOff);

    Route routeToAdd{d_env, depotNumber, route.first, route.second};
    d_env->d_depots[depotNumber].getVehicle(vehicleNumber).setRoute(routeToAdd);
}
