//
// Created by Mark van der Broek on 27/02/2017.
//

#include "vehicle.ih"

Vehicle::Vehicle(Env *env, int id, int vehicleType, int depotID, int capacity, double serviceTime, double drivingSpeed, double cost)
:
    d_env(env),
    d_vehicleType(vehicleType),
    d_drivingSpeed(drivingSpeed),
    d_depotID(depotID),
    d_cost(cost),
    d_capacity(capacity),
    d_serviceTime(serviceTime),
    d_route(Route{env, depotID}),
    d_id(id)
{}

