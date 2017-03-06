//
// Created by Mark van der Broek on 27/02/2017.
//

#ifndef ORACS_VEHICLE_H
#define ORACS_VEHICLE_H

#include <vector>
#include "../inc/route.h"
#include <fstream>

class Env;

class Vehicle {

    Env *               d_env;
    int                 d_id;
    int                 d_depotID;
    double const        d_drivingSpeed;
    double const        d_cost;
    double const        d_capacity;
    double const        d_serviceTime;
    Route               d_route;

public:
    Vehicle() = delete;
    Vehicle(Env *env, int id, int depotID, double capacity, double serviceTime, double drivingSpeed, double cost);

    int     getId()             const;
    int     getDepotID()        const;
    double  getDrivingSpeed()   const;
    double  getDrivingCost()    const;
    double  getCost()           const;
    double  getCapacity()       const;
    double  getServiceTime()    const;
    Route   &getRoute();
    double  getTotalCost()      const;
    double  getDrivingTime()    const;
    double  getRouteDuration()  const;

    void    setRoute(Route route);

    friend std::ostream& operator<<(std::ostream &os, Vehicle const &vehicle);

private:

};

inline int Vehicle::getId() const
{
    return d_id;
}

inline int Vehicle::getDepotID() const
{
    return d_depotID;
}

inline double Vehicle::getDrivingSpeed() const
{
    return d_drivingSpeed;
}

inline double Vehicle::getDrivingCost() const
{
    return d_cost / d_drivingSpeed;
}

inline double Vehicle::getCost() const
{
    return d_cost;
}

inline double Vehicle::getCapacity() const
{
    return d_capacity;
}

inline double Vehicle::getServiceTime() const
{
    return d_serviceTime;
}

inline Route &Vehicle::getRoute()
{
    return d_route;
}

inline double Vehicle::getTotalCost() const
{
    return d_route.getDistance() * d_cost;
}

inline double Vehicle::getDrivingTime() const
{
    return d_route.getDistance() / d_drivingSpeed;
}

inline double Vehicle::getRouteDuration() const
{
    return getDrivingTime() + d_route.getServiceTime();
}

inline void Vehicle::setRoute(Route route)
{
    d_route = route;
}

#endif //ORACS_VEHICLE_H
