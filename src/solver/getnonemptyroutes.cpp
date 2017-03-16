//
// Created by Mark van der Broek on 11/03/2017.
//

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