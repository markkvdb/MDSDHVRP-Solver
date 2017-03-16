//
// Created by Mark van der Broek on 12/03/2017.
//

#include "vehicle.ih"

double Vehicle::getTotalCostPlusPenalty() const
{
    return getTotalCost() + getPenaltyTime() * d_env->d_penalty;
}