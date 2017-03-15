//
// Created by Mark van der Broek on 13/03/2017.
//

#include "solver.ih"

auto Solver::bestSwapStar(Solution &s, int customerIdx, Vehicle &vehicle, set<int> forbiddenVehicles,
                          set<int> forbiddenCustomers)
{
    int customerID = vehicle.getRoute().getRoute()[customerIdx];

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


    for (pair<int, int> vehiclePair: s.getCustomers()[customerID].getVehicles())
    {
        Vehicle &vehicleSelected = s.getDepots()[vehiclePair.first].getVehicle(vehiclePair.second);

        if (forbiddenVehicles.find(vehicleSelected.getID()) != end(forbiddenCustomers))
            continue;

        for (int customerIdx2 = 1; customerIdx2 < vehicleSelected.getRoute().getRoute().size() - 1; ++customerIdx2)
        {
            int customerID1;
            int customerID2 = vehicleSelected.getRoute().getRoute()[customerIdx2];
            if (forbiddenCustomers.find(customerID2) != end(forbiddenCustomers))
                continue;

            int selectedCustomer1 = customerIdx;
            int selectedCustomer2 = customerIdx2;
            Vehicle &selectedVehicle1 = vehicle;
            Vehicle &selectedVehicle2 = vehicleSelected;

            // Switch the order of customers so that customer1 has the higher demand.
            if (vehicle.getRoute().getDemandRoute()[customerIdx] < vehicleSelected.getRoute().getDemandRoute()[customerIdx2])
            {
                selectedCustomer1 = customerIdx2;
                selectedCustomer2 = customerIdx;
                customerID1 = customerID2;
                customerID2 = customerID;
                selectedVehicle1 = vehicleSelected;
                selectedVehicle2 = vehicle;
            }

            pair<int, double> cost = findSwapStarCost(selectedCustomer1, selectedVehicle1, selectedCustomer2, selectedVehicle2);

            if (cost < minCost)
            {
                minCost = cost.second;
                minCustomer1 = customerID1;
                minDepot1 = selectedVehicle1.getDepotID();
                minVehicle1 = selectedVehicle1.getIDPos();
                minDemand1 = selectedVehicle1.getRoute().getDemandRoute()[selectedCustomer1];
                minCustomer2 = customerID2;
                minDepot2 = selectedVehicle2.getDepotID();
                minVehicle2 = selectedVehicle2.getIDPos();
                minDemand2 = selectedVehicle2.getRoute().getDemandRoute()[selectedCustomer2];
                minOption = cost.first;
            }

        }
    }

    return make_tuple(minCost, minCustomer1, minDepot1, minVehicle1, minDemand1, minCustomer2, minDepot2, minVehicle2, minDemand2, minOption);
}