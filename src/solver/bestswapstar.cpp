//
// Created by Mark van der Broek on 13/03/2017.
//

#include "solver.ih"

void Solver::bestSwapStar(Solution &s, int customerID, set<int> forbiddenVehicles, set<int> forbiddenCustomers)
{
    for (pair<int, int> vehiclePair: s.getCustomers()[customerID].getVehicles())
    {
        Vehicle &vehicleSelected = s.getDepots()[vehiclePair.first].getVehicle(vehiclePair.second);

        if (forbiddenVehicles.find(vehicleSelected.getID()) != end(forbiddenCustomers))
            continue;

        for (int customerIdx2 = 1; customerIdx2 < vehicleSelected.getRoute().getRoute().size() - 1; ++customerIdx2)
        {
            int customerID2 = vehicleSelected.getRoute().getRoute()[customerIdx2];
            if (forbiddenCustomers.find(customerID2) != end(forbiddenCustomers))
                continue;



        }
    }
}