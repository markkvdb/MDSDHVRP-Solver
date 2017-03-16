//
// Created by Mark van der Broek on 13/03/2017.
//

#include "solver.ih"

void Solver::swap(Solution &s)
{
    for (Depot &depot: s.getDepots())
    {
        for (Vehicle &vehicle: depot.getVehicles())
        {
            vehicle.bestSwap();
        }
    }
}