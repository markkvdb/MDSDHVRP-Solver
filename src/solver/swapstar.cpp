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
    int minDemand1 = -1;
    int minCustomer2 = -1;
    int minDepot2 = -1;
    int minVehicle2 = -1;
    int minDemand2 = -1;
    int minOption = -1;

    for (Depot &depot: s.getDepots())
    {
        for (Vehicle &vehicle: depot.getVehicles())
        {
            Route &route = vehicle.getRoute();
            for (int customerIdx = 1; customerIdx < route.getRoute().size() - 1; ++customerIdx)
            {
                int customerID = route.getRoute()[customerIdx];
                auto solutionTuple = bestSwapStar(s, customerIdx, vehicle, forbiddenPair.first[customerID], forbiddenPair.second[customerID]);

                if (get<0>(solutionTuple) < minCost)
                {
                    minCost = get<0>(solutionTuple);
                    minCustomer1 = get<1>(solutionTuple);
                    minDepot1 = get<2>(solutionTuple);
                    minVehicle1 = get<3>(solutionTuple);
                    minDemand1 = get<4>(solutionTuple);
                    minCustomer2 = get<5>(solutionTuple);
                    minDepot2 = get<6>(solutionTuple);
                    minVehicle2 = get<7>(solutionTuple);
                    minDemand2 = get<8>(solutionTuple);
                    minOption = get<9>(solutionTuple);
                }
            }
        }
    }

    // No option found
    if (minCustomer1 == -1)
        return;

    if (minDemand1 < minDemand2)
        cerr << "Swapstar failed.\n";

    Customer &customer1 = s.getCustomers()[minCustomer1];
    Customer &customer2 = s.getCustomers()[minCustomer2];

    // Depot inventory does not change, right?
    Depot &depot1 = s.getDepots()[minDepot1];
    Depot &depot2 = s.getDepots()[minDepot2];

    Vehicle &vehicle1 = depot1.getVehicle(minVehicle1);
    Vehicle &vehicle2 = depot2.getVehicle(minVehicle2);

    long positionCustomer1 = vehicle1.findCustomer(minCustomer1);
    long positionCustome2 = vehicle2.findCustomer(minCustomer2);

    int demand1_2 = minDemand1 - minDemand2;

    //Update everything





}