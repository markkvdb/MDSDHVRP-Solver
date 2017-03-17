//
// Created by Mark van der Broek on 10/03/2017.
//

/**
 * @brief Local search operator which switches two arcs within a route.
 *
 * @param [in] s    Solution
 */

#include "solver.ih"

void Solver::twoOptIntraRoute(Solution &s)
{
    for (Depot &depot: s.getDepots())
    {
        for (Vehicle &vehicle: depot.getVehicles())
        {
            vehicle.bestTwoOpt();
        }
    }
}