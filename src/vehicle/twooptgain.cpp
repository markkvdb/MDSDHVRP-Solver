//
// Created by Mark van der Broek on 12/03/2017.
//

/**
 * Calculate the gain of two-opt on two customers.
 * @param [in] bIdx Position of the first customer within the route of the vehicle.
 * @param [in] cIdx Position of the second customer within the route of the vehicle.
 * @return Cost of two-opt on the two customers
 */


#include "vehicle.ih"

double Vehicle::twoOptGain(int bIdx, int cIdx)
{
    double distanceGain = d_env->distanceMatrix(d_route.getRoute()[bIdx-1], d_route.getRoute()[cIdx]) +
            d_env->distanceMatrix(d_route.getRoute()[bIdx], d_route.getRoute()[cIdx+1]) -
            d_env->distanceMatrix(d_route.getRoute()[bIdx-1], d_route.getRoute()[bIdx]) -
            d_env->distanceMatrix(d_route.getRoute()[cIdx], d_route.getRoute()[cIdx+1]);

    double penaltyGain = 0;
    if (distanceGain < 0)
    {
        penaltyGain = (getPenaltyTime() - max(0.0, getPenaltyTime() + distanceGain / d_drivingSpeed)) * d_env->d_penalty;
    }

    return distanceGain * d_cost + penaltyGain;

}