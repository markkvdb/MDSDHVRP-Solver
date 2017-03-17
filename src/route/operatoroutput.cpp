//
// Created by Mark van der Broek on 06/03/2017.
//

/**
 * @brief Output operator of the route class
 *
 * @param [in] os       The stream to write to
 * @param [in] customer The route to write to the stream
 */

#include "route.ih"

ostream &operator<<(ostream &os, Route const &route)
{
    for (int routeIdx = 1; routeIdx != route.d_route.size() - 1; ++routeIdx)
    {
        os << route.d_route[routeIdx] << ' ' << route.d_demandRoute[routeIdx] << ' ';
    }

    return os;
}
