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
    int                 d_idPos;
    int                 d_vehicleType;
    int                 d_depotID;
    double              d_drivingSpeed;
    double              d_cost;
    int                 d_capacity;
    double              d_serviceTime;

    Route               d_route;

public:
    Vehicle() = delete;
    Vehicle(Env *env, int id, int idPos, int vehicleType, int depotID, int capacity, double serviceTime, double drivingSpeed, double cost);

    int                     getID()             const;
    int                     getIDPos()          const;
    int                     getVehicleType()    const;
    int                     getDepotID()        const;
    double                  getDrivingSpeed()   const;
    double                  getDrivingCost()    const;
    double                  getCost()           const;
    int                     getCapacity()       const;
    double                  getServiceTime()    const;
    Route &                 getRoute();
    Route const &           getRoute()          const;
    double                  getTotalCost()      const;
    double                  getTotalCostPlusPenalty() const;
    double                  getDrivingTime()    const;
    double                  getRouteDuration()  const;
    double                  getPenaltyTime()    const;
    int                     getLeftoverCapacity() const;
    bool                    emptyRoute()        const;
    std::vector<int>        getCustomerList()   const;

    void                    setRoute(Route route);
    int                     removeCustomer(int customerID);
    void                    addCustomer(int customerID, int load, int routePos);
    long                    findCustomer(int customerID) const;

    std::pair<int, double>  cheapestInsertion(int customerID, bool random) const;
    std::pair<int, double>  cheapestInsertion(int customerID1, int customerID2) const;
    std::pair<int, double>  cheapestInsertionWithSplits(int customerID) const;
    double                  removalGain(int customerID);

    std::vector<int>        selectCustomersToRemove(int q);


    double                  twoOptGain(int bIdx, int cIdx);
    void                    twoOpt(int bIdx, int cIdx);
    void                    bestTwoOpt();
    double                  swapGain(int aIdx, int bIdx);
    void                    swap(int aIdx, int bIdx);
    void                    bestSwap();


    friend std::ostream&    operator<<(std::ostream &os, Vehicle const &vehicle);

private:
    double                  insertionCost(int option, int customerID) const;
    double                  insertionCost(int option, int customerID1, int customerID2) const;

};

inline int Vehicle::getID() const
{
    return d_id;
}

inline int Vehicle::getIDPos() const
{
    return d_idPos;
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

inline int Vehicle::getCapacity() const
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

inline int Vehicle::getLeftoverCapacity() const
{
    return std::max(0, d_capacity - d_route.getLoad());
}

inline int Vehicle::removeCustomer(int customerID)
{
    return d_route.removeCustomer(customerID);
}

inline void Vehicle::addCustomer(int customerID, int load, int routePos)
{
    d_route.addCustomer(customerID, load, routePos);
}

inline bool Vehicle::emptyRoute() const
{
    return (d_route.getRoute().size() == 2);
}

inline std::vector<int> Vehicle::getCustomerList() const
{
    return d_route.getRoute();
}

#endif //ORACS_VEHICLE_H
