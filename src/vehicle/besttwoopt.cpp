//
// Created by Mark van der Broek on 12/03/2017.
//

/**
 * @brief Find the best two-opt move within the vehicle's route.
 */

#include "vehicle.ih"

void Vehicle::bestTwoOpt()
{
    int minBIdx = -1;
    int minCIdx = -1;
    double maxGain = numeric_limits<double>::max();

    // TODO 4 or more?
    if (d_route.getRoute().size() < 4)
        return;

    for (int bIdx = 1; bIdx != d_route.getRoute().size() - 3; ++bIdx)
    {
        for (int cIdx = bIdx + 1; cIdx < d_route.getRoute().size() - 2; ++cIdx)
        {
            double gain = twoOptGain(bIdx, cIdx);

            if (gain < maxGain)
            {
                minBIdx = bIdx;
                minCIdx = cIdx;
                maxGain = gain;
            }
        }
    }

    if (maxGain < 0)
        twoOpt(minBIdx, minCIdx);
}