//
// Created by Mark van der Broek on 13/03/2017.
//

/**
 * @brief One insertion inter route operator. Pick a customer to remove and add it another route with the lowest cost.
 *
 * @param [in] s    Solution
 */

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
    double minInsertion = 0;

    for (Depot &depotOut: s.getDepots())
    {
        for (int vehicleIdx = 0; vehicleIdx != depotOut.getVehicles().size(); ++vehicleIdx)
        {
            Vehicle &vehicleOut = depotOut.getVehicle(vehicleIdx);
            int vehicleID = vehicleOut.getID();

            for (int customerIdx = 1; customerIdx != vehicleOut.getRoute().getRoute().size() - 1; ++customerIdx)
            {
                // Select customer to change
                int const customerID = vehicleOut.getRoute().getRoute()[customerIdx];
                int const customerDemand = vehicleOut.getRoute().getDemandRoute()[customerIdx];
                double removalGain = vehicleOut.removalGain(customerID);
                depotOut.changeInventory(-customerDemand);

                for (Depot &depotIn: s.getDepots())
                {
                    if (depotIn.getLeftOverInventory() < customerDemand)
                        continue;

                    for (int vehicleIdx2 = 0; vehicleIdx2 != depotIn.getVehicles().size(); ++vehicleIdx2)
                    {
                        if (depotIn.getVehicle(vehicleIdx2).getID() == vehicleID ||
                                depotIn.getVehicle(vehicleIdx2).getLeftoverCapacity() < customerDemand)
                            continue;

                        auto insert = depotIn.getVehicle(vehicleIdx2).cheapestInsertionWithSplits(customerID);

                        if (insert.second - removalGain < minInsertion)
                        {
                            minCustomer = customerID;
                            minDepotIn = depotIn.getID();
                            minDepotOut = depotOut.getID();
                            minVehicleIn = vehicleIdx2;
                            minVehicleOut = vehicleIdx;
                            minDemand = customerDemand;
                            minPos = insert.first;
                            minInsertion = insert.second - removalGain;
                        }
                    }
                }
                depotOut.changeInventory(customerDemand);
            }
        }
    }

    if (minPos == -1)
        return;

    // Customer update
    s.getCustomers()[minCustomer].deleteVehicle(minDepotOut, minVehicleOut);
    s.getDepots()[minDepotOut].getVehicle(minVehicleOut).removeCustomer(minCustomer);
    // Depot update
    s.getDepots()[minDepotOut].changeInventory(minDemand);
    s.getDepots()[minDepotIn].changeInventory(-minDemand);

    // Split customer so added to
    if (minPos == -2)
    {
        int positionCustomer = s.getDepots()[minDepotIn].getVehicle(minVehicleIn).findCustomer(minCustomer);
        s.getDepots()[minDepotIn].getVehicle(minVehicleIn).getRoute().getDemandRoute()[positionCustomer] += minDemand;
    }
    else
    {
        s.getCustomers()[minCustomer].addToVehicle(minDepotIn, minVehicleIn);

        // Vehicle update
        s.getDepots()[minDepotIn].getVehicle(minVehicleIn).addCustomer(minCustomer, minDemand, minPos);
    }
}