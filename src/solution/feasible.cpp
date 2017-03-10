//
// Created by Mark van der Broek on 08/03/2017.
//

#include "solution.ih"

bool Solution::feasible()
{
    d_feasible = true;

    for (Depot &depot: d_depots)
    {
        for (Vehicle &vehicle: depot.getVehicles())
        {
            if (vehicle.getRoute().getLoad() > vehicle.getCapacity() ||
                    vehicle.getRouteDuration() > vehicle.getServiceTime())
            {
                d_feasible = false;
            }
        }
    }
    return d_feasible;
}