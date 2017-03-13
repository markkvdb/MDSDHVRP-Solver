//
// Created by Mark van der Broek on 13/03/2017.
//

#include "solver.ih"

void Solver::swapStar(Solution &s)
{
    auto forbiddenPair = createForbiddenVehiclesAndCustomers(s);

    for (Depot &depot: s.getDepots())
    {
        for (Vehicle &vehicle: depot.getVehicles())
        {
            Route &route = vehicle.getRoute();
            for (int customerIdx = 1; customerIdx < route.getRoute().size() - 1; ++customerIdx)
            {
                int customerID = route.getRoute()[customerIdx];
                bestSwapStar(s, customerID, forbiddenPair.first[customerID], forbiddenPair.second[customerID]);
            }
        }
    }
}