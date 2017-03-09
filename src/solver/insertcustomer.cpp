//
// Created by Mark van der Broek on 09/03/2017.
//

#include "solver.ih"

void Solver::insertCustomer(Solution &solution, int selectedCustomer, int positionCustomer, int depotID, int vehicleID,
                            int routePos, vector<int> &customersToAdd)
{
    Depot &depot = solution.getDepots()[depotID];
    Vehicle &vehicle = depot.getVehicle(vehicleID);

    double minConstraint = min(depot.getLeftOverInventory(), vehicle.getLeftoverCapacity());

    Customer &customerToAdd = solution.getCustomers()[selectedCustomer];

    double demand = 0;
    // All demand can be satisfied by vehicle
    if (customerToAdd.getRemainingDemand() < minConstraint)
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