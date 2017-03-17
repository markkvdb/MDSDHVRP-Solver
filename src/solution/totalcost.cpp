//
// Created by Mark van der Broek on 08/03/2017.
//

/**
 * @brief Calculates the total cost of the solution.
 *
 * @return Total cost of the solution
 */

#include "solution.ih"

double Solution::totalCost()
{
    double totalCost = 0;
    for (Depot &depot: d_depots)
    {
        for (Vehicle const &vehicle: depot.getVehicles())
        {
            totalCost += vehicle.getTotalCostPlusPenalty();
        }
    }

    return totalCost;
}