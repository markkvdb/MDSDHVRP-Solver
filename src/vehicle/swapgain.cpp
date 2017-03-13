//
// Created by Mark van der Broek on 13/03/2017.
//

#include "vehicle.ih"

double Vehicle::swapGain(int aIdx, int bIdx)
{
    double gain = d_env->d_distanceMatrix[d_route.getRoute()[aIdx-1]][d_route.getRoute()[bIdx]] +
            d_env->d_distanceMatrix[d_route.getRoute()[bIdx]][d_route.getRoute()[aIdx+1]] +
            d_env->d_distanceMatrix[d_route.getRoute()[bIdx-1]][d_route.getRoute()[aIdx]] +
            d_env->d_distanceMatrix[d_route.getRoute()[aIdx]][d_route.getRoute()[bIdx+1]] +
            d_env->d_distanceMatrix[d_route.getRoute()[aIdx-1]][d_route.getRoute()[aIdx]] +
            d_env->d_distanceMatrix[d_route.getRoute()[aIdx]][d_route.getRoute()[aIdx+1]] +
            d_env->d_distanceMatrix[d_route.getRoute()[bIdx-1]][d_route.getRoute()[bIdx]] +
            d_env->d_distanceMatrix[d_route.getRoute()[bIdx]][d_route.getRoute()[bIdx+1]];
    if (gain < 0)
    {
        gain -= (getPenaltyTime() - min(0.0, getPenaltyTime() + gain / d_drivingSpeed)) * d_env->d_penalty;
    }

    return gain;
}