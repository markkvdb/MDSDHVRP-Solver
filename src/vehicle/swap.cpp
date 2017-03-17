//
// Created by Mark van der Broek on 13/03/2017.
//

/**
 * Swap two customers in in the route of the vehicle
 * @param [in] aIdx     Position of the first customer to swap
 * @param [in] bIdx     Position of the second customer to swap
 */

#include "vehicle.ih"

void Vehicle::swap(int aIdx, int bIdx)
{
    d_route.swap(aIdx, bIdx);
}