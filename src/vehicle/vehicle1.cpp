//
// Created by Mark van der Broek on 27/02/2017.
//

#include "vehicle.ih"

Vehicle::Vehicle(double capacity, double travelTime, double drivingSpeed, double cost)
:
    d_drivingSpeed(drivingSpeed),
    d_cost(cost),
    d_capacity(capacity),
    d_travelTime(travelTime),
    d_route(Route{}),
    d_deliveries(vector<int>{0}),
    d_id(noOfVehicles++)
{}

