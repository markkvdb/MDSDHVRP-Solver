//
// Created by Mark van der Broek on 13/03/2017.
//

/**
 * Calculate the gain of swapping two customers.
 * @param [in] aIdx Position of the first customer within the route of the vehicle.
 * @param [in] bIdx Position of the second customer within the route of the vehicle.
 * @return Cost of swapping the two customers
 */

#include "vehicle.ih"

double Vehicle::swapGain(int aIdx, int bIdx)
{
    double distanceGain = d_env->distanceMatrix(d_route.getRoute()[aIdx-1], d_route.getRoute()[bIdx]) +
            d_env->distanceMatrix(d_route.getRoute()[bIdx], d_route.getRoute()[aIdx+1]) +
            d_env->distanceMatrix(d_route.getRoute()[bIdx-1], d_route.getRoute()[aIdx]) +
            d_env->distanceMatrix(d_route.getRoute()[aIdx], d_route.getRoute()[bIdx+1]) -
            d_env->distanceMatrix(d_route.getRoute()[aIdx-1], d_route.getRoute()[aIdx]) -
            d_env->distanceMatrix(d_route.getRoute()[aIdx], d_route.getRoute()[aIdx+1]) -
            d_env->distanceMatrix(d_route.getRoute()[bIdx-1], d_route.getRoute()[bIdx]) -
            d_env->distanceMatrix(d_route.getRoute()[bIdx], d_route.getRoute()[bIdx+1]);

    double penaltyGain = 0;
    if (distanceGain < 0)
    {
        penaltyGain = (max(0.0, distanceGain / d_drivingSpeed + getPenaltyTime()) - getPenaltyTime()) * d_env->d_penalty;
    }

    return distanceGain * d_cost + penaltyGain;
}