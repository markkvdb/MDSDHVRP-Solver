//
// Created by Mark van der Broek on 12/03/2017.
//

#include "vehicle.ih"

double Vehicle::twoOptGain(int bIdx, int cIdx)
{
    double distanceGain = d_env->d_distanceMatrix[d_route.getRoute()[bIdx-1]][d_route.getRoute()[cIdx]] +
            d_env->d_distanceMatrix[d_route.getRoute()[bIdx]][d_route.getRoute()[cIdx+1]] -
            d_env->d_distanceMatrix[d_route.getRoute()[bIdx-1]][d_route.getRoute()[bIdx]] -
            d_env->d_distanceMatrix[d_route.getRoute()[cIdx]][d_route.getRoute()[cIdx+1]];

    double penaltyGain = 0;
    if (distanceGain < 0)
    {
        penaltyGain = (getPenaltyTime() - max(0.0, getPenaltyTime() + distanceGain / d_drivingSpeed)) * d_env->d_penalty;
    }

    return distanceGain * d_cost + penaltyGain;

}