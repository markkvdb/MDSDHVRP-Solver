//
// Created by Mark van der Broek on 13/03/2017.
//

#include "vehicle.ih"

void Vehicle::bestSwap()
{
    int minAIdx = -1;
    int minBIdx = -1;
    double maxGain = numeric_limits<double>::max();

    if (d_route.getRoute().size() < 4)
        return;

    for (int aIdx = 1; aIdx != d_route.getRoute().size() - 2; ++aIdx)
    {
        for (int bIdx = bIdx + 1; bIdx < d_route.getRoute().size() - 1; ++bIdx)
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