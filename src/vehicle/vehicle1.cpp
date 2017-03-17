//
// Created by Mark van der Broek on 27/02/2017.
//

/**
 * Constructor.
 * @param [in] env          Environment pointer
 * @param [in] idPos        Position of the vehicle within the depot vehicle list
 * @param [in] vehicleType  Type of the vehicle
 * @param [in] depotID      ID of the depot the vehicle is in
 * @param [in] capacity     Total capacity of the vehicle
 * @param [in] serviceTime  Total service time of the vehicle
 * @param [in] drivingSpeed Driving speed of the vehicle per unit of time
 * @param [in] cost         Cost of driving one unit of time
 */

#include "vehicle.ih"

Vehicle::Vehicle(Env *env, int id, int idPos, int vehicleType, int depotID, int capacity, double serviceTime, double drivingSpeed, double cost)
:
    d_env(env),
    d_vehicleType(vehicleType),
    d_drivingSpeed(drivingSpeed),
    d_depotID(depotID),
    d_cost(cost),
    d_capacity(capacity),
    d_serviceTime(serviceTime),
    d_route(Route{env, depotID}),
    d_id(id),
    d_idPos(idPos)
{}

