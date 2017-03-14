//
// Created by Mark van der Broek on 13/03/2017.
//

#include "solver.ih"

void Solver::swapStar(Solution &s)
{
    auto forbiddenPair = createForbiddenVehiclesAndCustomers(s);

    double minCost = numeric_limits<double>::max();
    int minCustomer1 = -1;
    int minDepot1 = -1;
    int minVehicle1 = -1;
    int minCustomer2 = -1;
    int minDepot2 = -1;
    int minVehicle2 = -1;

    for (Depot &depot: s.getDepots())
    {
        for (Vehicle &vehicle: depot.getVehicles())
        {
            Route &route = vehicle.getRoute();
            for (int customerIdx = 1; customerIdx < route.getRoute().size() - 1; ++customerIdx)
            {
                int customerID = route.getRoute()[customerIdx];
//                auto solutionTuple = bestSwapStar(s, customerIdx, vehicle, forbiddenPair.first[customerID], forbiddenPair.second[customerID]);
//
//                if (get<0>(solutionTuple) < minCost)
//                {
//                    minCost = get<0>(solutionTuple);
//                    minCustomer1 = get<1>(solutionTuple);
//                    minDepot1 = get<2>(solutionTuple);
//                    minVehicle1 = get<3>(solutionTuple);
//                    minCustomer2 = get<4>(solutionTuple);
//                    minDepot2 = get<5>(solutionTuple);
//                    minVehicle2 = get<6>(solutionTuple);
//                }
            }
        }
    }
}