//
// Created by Mark van der Broek on 09/03/2017.
//

/**
 * Setter for the route of the vehicle.
 * @param [in] route    Route to add to the vehicle
 */

#include "vehicle.ih"

void Vehicle::setRoute(Route route)
{
    d_route = route;
}