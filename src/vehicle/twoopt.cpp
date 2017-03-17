//
// Created by Mark van der Broek on 12/03/2017.
//

/**
 * Apply two-opt operator to two customers in the route of the vehicle.
 * @param [in] bIdx Position of the first customer to change
 * @param [in] cIdx Position of the second customer to change
 */

#include "vehicle.ih"

void Vehicle::twoOpt(int bIdx, int cIdx)
{
    d_route.twoOpt(bIdx, cIdx);
}