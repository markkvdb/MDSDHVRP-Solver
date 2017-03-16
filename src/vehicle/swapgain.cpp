//
// Created by Mark van der Broek on 13/03/2017.
//

#include "vehicle.ih"

double Vehicle::swapGain(int aIdx, int bIdx)
{
    double distanceGain = d_env->d_distanceMatrix[d_route.getRoute()[aIdx-1]][d_route.getRoute()[bIdx]] +
            d_env->d_distanceMatrix[d_route.getRoute()[bIdx]][d_route.getRoute()[aIdx+1]] +
            d_env->d_distanceMatrix[d_route.getRoute()[bIdx-1]][d_route.getRoute()[aIdx]] +
            d_env->d_distanceMatrix[d_route.getRoute()[aIdx]][d_route.getRoute()[bIdx+1]] -
            d_env->d_distanceMatrix[d_route.getRoute()[aIdx-1]][d_route.getRoute()[aIdx]] -
            d_env->d_distanceMatrix[d_route.getRoute()[aIdx]][d_route.getRoute()[aIdx+1]] -
            d_env->d_distanceMatrix[d_route.getRoute()[bIdx-1]][d_route.getRoute()[bIdx]] -
            d_env->d_distanceMatrix[d_route.getRoute()[bIdx]][d_route.getRoute()[bIdx+1]];

    double penaltyGain = 0;
    if (distanceGain < 0)
    {
        penaltyGain = (max(0.0, distanceGain / d_drivingSpeed + getPenaltyTime()) - getPenaltyTime()) * d_env->d_penalty;
    }

    return distanceGain * d_cost + penaltyGain;
}