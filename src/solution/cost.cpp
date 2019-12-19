//
// Created by Niels on 18-3-2017.
//

/**
 * @brief Calculates the total cost of the solution (without penalty).
 *
 * @return Total cost of the solution
 */

#include "solution.ih"

double Solution::cost()
{
    double cost = 0;
    for (Depot &depot: d_depots)
        for (Vehicle const &vehicle: depot.getVehicles())
            cost += vehicle.getTotalCost();

    return cost;
}