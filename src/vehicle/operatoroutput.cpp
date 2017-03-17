//
// Created by Mark van der Broek on 06/03/2017.
//

/**
 * @brief Output operator of the vehicle class
 *
 * @param [in] os       The stream to write to
 * @param [in] customer The vehicle to write to the stream
 */


#include "vehicle.ih"

ostream& operator<<(ostream &os, Vehicle const &vehicle)
{
    os << vehicle.d_vehicleType << ' '
       << setprecision(2) << vehicle.d_route.getDistance() << ' '
       << setprecision(2) << vehicle.getTotalCost() << ' '
       << vehicle.d_route.getLoad() << ' '
       << setprecision(2) << vehicle.d_route.getServiceTime() << ' '
       << setprecision(2) << vehicle.getDrivingTime() << ' '
       << setprecision(2) << vehicle.getRouteDuration() << ' '
       << vehicle.d_route;

    return os;
}
