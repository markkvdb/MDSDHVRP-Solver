//
// Created by Mark van der Broek on 27/02/2017.
//

#ifndef ORACS_VEHICLE_H
#define ORACS_VEHICLE_H

#include <vector>
#include "../inc/route.h"
#include <fstream>
#include <algorithm>


class Env;

class Vehicle {

    Env *               d_env;

    // FIXED
    int                 d_id;
    int                 d_vehicleType;
    int                 d_depotID;
    double              d_drivingSpeed;
    double              d_cost;
    double              d_capacity;
    double              d_serviceTime;

    Route               d_route;

public:
    Vehicle() = delete;
    Vehicle(Env *env, int id, int vehicleType, int depotID, double capacity, double serviceTime, double drivingSpeed, double cost);

    int                     getID()             const;
    int                     getVehicleType()    const;
    int                     getDepotID()        const;
    double                  getDrivingSpeed()   const;
    double                  getDrivingCost()    const;
    double                  getCost()           const;
    double                  getCapacity()       const;
    double                  getServiceTime()    const;
    Route &                 getRoute();
    Route const &           getRoute()          const;
    double                  getTotalCost()      const;
    double                  getDrivingTime()    const;
    double                  getRouteDuration()  const;
    double                  getPenaltyTime()    const;
    double                  getLeftoverCapacity() const;
    bool                    emptyRoute()        const;

    void                    setRoute(Route route);
    double                  removeCustomer(int customerID);
    void                    addCustomer(int customerID, double load, int routePos);
    std::pair<int, double>  cheapestInsertion(int customerID) const;
    double                  removalGain(int customerID);
    std::vector<int>        selectCustomersToRemove(int q);

    friend std::ostream&    operator<<(std::ostream &os, Vehicle const &vehicle);

private:
    double                  insertionCost(int option, int customerID) const;

};

inline int Vehicle::getID() const
{
    return d_id;
}

inline int Vehicle::getVehicleType() const
{
    return d_vehicleType;
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

inline Route const &Vehicle::getRoute() const
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

inline double Vehicle::getPenaltyTime() const
{
    return std::max(0.0, getRouteDuration() - d_serviceTime);
}

inline double Vehicle::getLeftoverCapacity() const
{
    return std::max(0.0, d_capacity - d_route.getLoad());
}

inline double Vehicle::removeCustomer(int customerID)
{
    return d_route.removeCustomer(customerID);
}

inline void Vehicle::addCustomer(int customerID, double load, int routePos)
{
    d_route.addCustomer(customerID, load, routePos);
}

inline bool Vehicle::emptyRoute() const
{
    return (d_route.getRoute().size() == 2);
}

#endif //ORACS_VEHICLE_H
