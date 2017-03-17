//
// Created by Mark van der Broek on 12/03/2017.
//

/**
 * Calculate the total cost of the route including the (possible) penalty costs.
 * @return Total cost of the route including penalty cost
 */

#include "vehicle.ih"

double Vehicle::getTotalCostPlusPenalty() const
{
    return getTotalCost() + getPenaltyTime() * d_env->d_penalty;
}