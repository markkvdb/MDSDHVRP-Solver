//
// Created by Mark van der Broek on 27/02/2017.
//

#include "vehicle.ih"

Vehicle::Vehicle()
:
        d_drivingSpeed(0),
        d_cost(0),
        d_capacity(0),
        d_travelTime(0),
        d_route(Route{}),
        d_deliveries(vector<int>{0}),
        d_id(noOfVehicles++)
{}
