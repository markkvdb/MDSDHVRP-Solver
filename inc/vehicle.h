//
// Created by Mark van der Broek on 27/02/2017.
//

#ifndef ORACS_VEHICLE_H
#define ORACS_VEHICLE_H

#include <vector>
#include "../inc/route.h"

class Env;

class Vehicle {

    Env *               d_env;
    int                 d_id;
    int                 d_depotID;
    double const        d_drivingSpeed;
    double const        d_cost;
    double const        d_capacity;
    double const        d_travelTime;
    Route               d_route;
    // TODO Should the deliveries be stored in the route?
    std::vector<int>    d_deliveries;

public:
    Vehicle() = delete;
    Vehicle(Env *env, int id, int depotID, double capacity, double travelTime, double drivingSpeed, double cost);

    int     getId();
    int     getDepotID();
    double  getDrivingSpeed();
    double  getCost();
    double  getCapacity();
    double  getTravelTime();
    Route   &getRoute();
    double  getDrivingCost();

private:

};

inline int Vehicle::getId()
{
    return d_id;
}

inline int Vehicle::getDepotID()
{
    return d_depotID;
}

inline double Vehicle::getDrivingSpeed()
{
    return d_drivingSpeed;
}

inline double Vehicle::getCost()
{
    return d_cost;
}

inline double Vehicle::getCapacity()
{
    return d_capacity;
}

inline double Vehicle::getTravelTime()
{
    return d_travelTime;
}

inline Route &Vehicle::getRoute()
{
    return d_route;
}

inline double Vehicle::getDrivingCost()
{
    return (d_cost / d_drivingSpeed);
}

#endif //ORACS_VEHICLE_H
