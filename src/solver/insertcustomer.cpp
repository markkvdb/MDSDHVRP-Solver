//
// Created by Mark van der Broek on 09/03/2017.
//

/**
 * @brief Insert customer in the selected route.
 *
 * @param [in] solution         Solution
 * @param [in] selectedCustomer Customer to insert
 * @param [in] positionCustomer Position of the customer in the customersToAdd vector
 * @param [in] depotID          ID of the depot
 * @param [in] vehicleID        ID of the vehicle
 * @param [in] routePos         Position in the route to insert the customer in
 * @param [in] customersToAdd   Vector of customers still to be inserted
 */

#include "solver.ih"

void Solver::insertCustomer(Solution &solution, int selectedCustomer, int positionCustomer, int depotID, int vehicleID,
                            int routePos, vector<int> &customersToAdd)
{
    Depot &depot = solution.getDepots()[depotID];
    Vehicle &vehicle = depot.getVehicle(vehicleID);

    int minConstraint = min(depot.getLeftOverInventory(), vehicle.getLeftoverCapacity());

    Customer &customerToAdd = solution.getCustomers()[selectedCustomer];

    int demand = 0;
    // All demand can be satisfied by vehicle
    if (customerToAdd.getRemainingDemand() <= minConstraint)
    {
        demand = customerToAdd.getRemainingDemand();
        customersToAdd.erase(begin(customersToAdd) + positionCustomer);
    }
    else
    {
        demand = minConstraint;
    }
    vehicle.addCustomer(selectedCustomer, demand, routePos);
    depot.changeInventory(-demand);
    customerToAdd.changeDemand(-demand);
    customerToAdd.addToVehicle(depotID, vehicleID);
}