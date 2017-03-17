//
// Created by Mark van der Broek on 13/03/2017.
//

/**
 * @brief Create the list of forbidden vehicles and customers. A forbidden vehicle for a customer is defined as
 *        the list of vehicles where it's in. The forbidden customers are the customers situated in one of these
 *        vehicles.
 *
 * @param [in] s    Solution
 *
 * @return Pair of vectors that consists of sets. Each set is a set of forbidden vehicles and customers.
 */

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
            copy(customersToAdd.begin(), customersToAdd.end(), inserter(forbiddenCustomers[customerIdx],
                                                                        end(forbiddenCustomers[customerIdx])));
            int hoi = 1;
        }
    }

    return make_pair(forbiddenVehicles, forbiddenCustomers);
}