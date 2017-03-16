//
// Created by Mark van der Broek on 10/03/2017.
//

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