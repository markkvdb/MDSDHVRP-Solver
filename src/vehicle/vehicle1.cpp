//
// Created by Mark van der Broek on 27/02/2017.
//

#include "vehicle.ih"

Vehicle::Vehicle(Env *env, int id, int depotID, double capacity, double travelTime, double drivingSpeed, double cost)
:
    d_env(env),
    d_drivingSpeed(drivingSpeed),
    d_depotID(depotID),
    d_cost(cost),
    d_capacity(capacity),
    d_travelTime(travelTime),
    d_route(Route{env, depotID}),
    d_deliveries(vector<int>{0}),
    d_id(id)
{}

