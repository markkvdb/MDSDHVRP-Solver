//
// Created by Mark van der Broek on 08/03/2017.
//

#include "solution.ih"

double Solution::totalCost()
{
    double totalCost = 0;
    for (Depot &depot: d_depots)
    {
        for (Vehicle const &vehicle: depot.getVehicles())
        {
            totalCost += vehicle.getTotalCost();
        }
    }

    return totalCost;
}