//
// Created by Mark van der Broek on 06/03/2017.
//

#include "vehicle.ih"

ostream& operator<<(ostream &os, Vehicle const &vehicle)
{
    os << vehicle.d_vehicleType << ' ' << vehicle.d_route.getDistance() << ' ' << vehicle.getTotalCost() << ' '
       << vehicle.d_route.getLoad() << ' ' << vehicle.d_route.getServiceTime() << ' ' << vehicle.getDrivingTime()
       << ' ' << vehicle.getRouteDuration() << ' ' << vehicle.d_route;

    return os;
}
