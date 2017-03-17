//
// Created by Mark van der Broek on 06/03/2017.
//

/**
 * @brief Update the load of the route.
 */

#include "route.ih"

void Route::updateLoad()
{
    d_load = accumulate(begin(d_demandRoute), end(d_demandRoute), 0);
}