//
// Created by Mark van der Broek on 13/03/2017.
//

#include "solver.ih"

void Solver::oneInsertionInterRoute(Solution &s)
{
    int minCustomer = -1;
    int minDepotIn = -1;
    int minDepotOut = -1;
    int minVehicleIn = -1;
    int minVehicleOut = -1;
    int minDemand = -1;
    int minPos = -1;
    double minInsertion = numeric_limits<double>::max();

    for (Depot &depot: s.getDepots())
    {
        for (size_t vehicleIdx = 0; vehicleIdx != depot.getVehicles().size(); ++vehicleIdx)
        {
            Vehicle &vehicle = depot.getVehicle(vehicleIdx);
            int vehicleID = vehicle.getID();

            for (int customerIdx = 1; customerIdx != vehicle.getRoute().getRoute().size() - 1; ++customerIdx)
            {
                int const customerID = vehicle.getRoute().getRoute()[customerIdx];
                int const customerDemand = vehicle.getRoute().getDemandRoute()[customerIdx];
                depot.changeInventory(-customerDemand);

                for (Depot &depot2: s.getDepots())
                {
                    if (depot2.getLeftOverInventory() < customerDemand)
                        continue;

                    for (int vehicleIdx2 = 0; vehicleIdx2 != depot2.getVehicles().size(); ++vehicleIdx2)
                    {
                        if (depot2.getVehicle(vehicleIdx2).getID() == vehicleID ||
                                depot2.getVehicle(vehicleIdx2).getLeftoverCapacity() < customerDemand)
                            continue;

                        auto insert = depot2.getVehicle(vehicleIdx2).cheapestInsertionWithSplits(customerID);

                        if (insert.second < minInsertion)
                        {
                            minCustomer = customerID;
                            minDepotIn = depot2.getID();
                            minDepotOut = depot.getID();
                            minVehicleIn = vehicleIdx2;
                            minVehicleOut = vehicleIdx;
                            minDemand = vehicle.getRoute().getDemandRoute()[customerIdx];
                            minPos = insert.first;
                            minInsertion = insert.second;
                        }
                    }

                }
                depot.changeInventory(customerDemand);
            }
        }
    }

    if (minPos == -1)
        return;

    // Vehicle update
    if (minPos == -2)
    {
        int positionCustomer = s.getDepots()[minDepotIn].getVehicle(minVehicleIn).findCustomer(minCustomer);
        s.getDepots()[minDepotIn].getVehicle(minVehicleIn).getRoute().getDemandRoute()[positionCustomer] += minDemand;
    }
    else
    {
        // Customer update
        s.getCustomers()[minCustomer].deleteVehicle(minDepotOut, minVehicleOut);
        s.getCustomers()[minCustomer].addToVehicle(minDepotIn, minVehicleIn);

        // Depot update
        s.getDepots()[minDepotOut].changeInventory(minDemand);
        s.getDepots()[minDepotIn].changeInventory(-minDemand);

        // Vehicle update
        s.getDepots()[minDepotOut].getVehicle(minVehicleOut).removeCustomer(minCustomer);
        s.getDepots()[minDepotIn].getVehicle(minVehicleIn).addCustomer(minCustomer, minDemand, minPos);
    }
}