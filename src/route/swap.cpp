//
// Created by Mark van der Broek on 13/03/2017.
//

#include "route.ih"

void Route::swap(int aIdx, int bIdx)
{
    int customerA = d_route[aIdx];
    double demandA = d_demandRoute[aIdx];

    d_route[aIdx] = d_route[bIdx];
    d_route[bIdx] = customerA;
    d_route[aIdx] = d_demandRoute[bIdx];
    d_route[bIdx] = demandA;

    updateLoad();
    updateDistance();
    updateServiceTime();
}