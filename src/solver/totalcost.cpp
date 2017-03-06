//
// Created by Mark van der Broek on 06/03/2017.
//

#include "solver.ih"

double Solver::totalCost() const
{
    double totalCost = 0;
    for (Depot &depot: d_env->d_depots)
    {
        for (Vehicle const &vehicle: depot.getVehicles())
        {
            totalCost += vehicle.getTotalCost();
        }
    }

    return totalCost;
}