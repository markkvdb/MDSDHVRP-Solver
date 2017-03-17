//
// Created by Mark van der Broek on 06/03/2017.
//

/**
 * @brief Update the total service time of the route.
 */

#include "route.ih"

void Route::updateServiceTime()
{
    double sumServiceTimes = 0;
    for (int customerIdx = 1; customerIdx != d_route.size() - 1; ++customerIdx)
    {
        sumServiceTimes += d_env->d_currentSolution.getCustomers()[d_route[customerIdx]].getServiceTime();
    }

    d_serviceTime = sumServiceTimes;
}