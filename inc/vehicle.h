//
// Created by Mark van der Broek on 27/02/2017.
//

#ifndef ORACS_VEHICLE_H
#define ORACS_VEHICLE_H

#include <vector>
#include "../inc/route.h"

class Vehicle {
    int d_id;
    int const d_vehicleType;
    int const d_capacity;
    int const d_travelTime;
    Route d_route;
    // TODO Should the deliveries be stored in the route?
    std::vector<int> d_deliveries;

public:
    static int noOfVehicles;
    Vehicle();
    Vehicle(int vehicleType, int capacity, int travelTime);
    int getId();
    int getVehicleType();
    int getCapacity();
    int getTravelTime();
    Route &getRoute();

private:

};

inline int Vehicle::getId()
{
    return d_id;
}

inline int Vehicle::getVehicleType()
{
    return d_vehicleType;
}

inline int Vehicle::getCapacity()
{
    return d_capacity;
}

inline int Vehicle::getTravelTime()
{
    return d_travelTime;
}

inline Route &Vehicle::getRoute()
{
    return d_route;
}

#endif //ORACS_VEHICLE_H
