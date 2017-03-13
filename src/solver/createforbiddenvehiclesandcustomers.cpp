//
// Created by Mark van der Broek on 13/03/2017.
//

#include "solver.ih"

pair<vector<set<int>>, vector<set<int>>> Solver::createForbiddenVehiclesAndCustomers(Solution &s)
{
    vector<set<int>> forbiddenVehicles(s.getCustomers().size());
    vector<set<int>> forbiddenCustomers(s.getCustomers().size());
    for (size_t customerIdx = 0; customerIdx != s.getCustomers().size(); ++customerIdx)
    {
        for (pair<int, int> vehiclePair: s.getCustomers()[customerIdx].getVehicles())
        {
            Vehicle const &vehicle = s.getDepots()[vehiclePair.first].getVehicle(vehiclePair.second);
            forbiddenVehicles[customerIdx].insert(vehicle.getID());
            vector<int> customersToAdd = vehicle.getCustomerList();
            copy(customersToAdd.begin(), customersToAdd.end(), std::inserter(forbiddenCustomers[customerIdx],
                                                                             end(forbiddenCustomers[customerIdx])));
        }
    }

    return make_pair(forbiddenVehicles, forbiddenCustomers);
}