//
// Created by Mark van der Broek on 27/02/2017.
//

#include "vehicle.ih"

Vehicle::Vehicle(int vehicleType, int capacity, int travelTime)
:
    d_vehicleType(vehicleType),
    d_capacity(capacity),
    d_travelTime(travelTime),
    d_route(Route{}),
    d_deliveries(vector<int>{0})
{
    ++noOfVehicles;
    d_id = noOfVehicles;
}

