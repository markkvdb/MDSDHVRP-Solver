//
// Created by Mark van der Broek on 13/03/2017.
//

/**
 * @brief Find the best swap move. A swap is defined as a change of position for two customers within the vehicle's
 *        route.
 */

#include "vehicle.ih"

void Vehicle::bestSwap()
{
    int minAIdx = -1;
    int minBIdx = -1;
    double maxGain = numeric_limits<double>::max();

    if (d_route.getRoute().size() < 6)
        return;

    for (int aIdx = 1; aIdx != d_route.getRoute().size() - 4; ++aIdx)
    {
        for (int bIdx = aIdx + 3; bIdx < d_route.getRoute().size() - 1; ++bIdx)
        {
            double gain = swapGain(aIdx, bIdx);

            if (gain < maxGain)
            {
                minAIdx = aIdx;
                minBIdx = bIdx;
                maxGain = gain;
            }
        }
    }

    if (maxGain < 0)
        swap(minAIdx, minBIdx);
}