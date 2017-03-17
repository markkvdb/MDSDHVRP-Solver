//
// Created by Mark van der Broek on 13/03/2017.
//

/**
 * @brief Swap two customers in the route.
 *
 * @param [in] aIdx  Position of the first customer in the route
 * @param [in] bIdx  Position of the second customer in the route
 */

#include "route.ih"

void Route::swap(int aIdx, int bIdx)
{
    int customerA = d_route[aIdx];
    int demandA = d_demandRoute[aIdx];

    d_route[aIdx] = d_route[bIdx];
    d_route[bIdx] = customerA;
    d_demandRoute[aIdx] = d_demandRoute[bIdx];
    d_demandRoute[bIdx] = demandA;

    updateLoad();
    updateDistance();
    updateServiceTime();
}