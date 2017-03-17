//
// Created by Mark van der Broek on 06/03/2017.
//

/**
 * @brief Update the distance of the route.
 */

#include "route.ih"

void Route::updateDistance()
{
    double sumDistance = 0;

    for (int routeIdx = 0; routeIdx != d_route.size() - 1; ++routeIdx)
    {
        sumDistance += d_env->d_distanceMatrix[d_route[routeIdx]][d_route[routeIdx+1]];
    }
    d_length = sumDistance;
}
