//
// Created by Mark van der Broek on 11/03/2017.
//

/**
 * @brief Find the list of non empty routes.
 *
 * @param [in] solution Solution
 *
 * @return Vector of pairs with non empty routes where the first element corresponds to depot ID of the corresponding
 *         route, and the second element corresponds to the vehicle ID of the route.
 */

#include "solver.ih"

vector<pair<int, int>> Solver::getNonEmptyRoutes(Solution &solution)
{
    vector<pair<int, int>> nonEmptyRoutes;
    for (Depot &depot: solution.getDepots())
    {
        for (Vehicle const &vehicle: depot.getVehicles())
        {
            if (not vehicle.emptyRoute())
                nonEmptyRoutes.push_back(make_pair(depot.getID(), vehicle.getIDPos()));
        }
    }
    return nonEmptyRoutes;
}