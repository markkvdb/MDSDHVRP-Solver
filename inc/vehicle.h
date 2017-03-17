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

/**
 * Vehicle class
 */
class Vehicle {

    Env *               d_env; /*!< Environment pointer */

    // FIXED
    int                 d_id; /*!< ID of the vehicle */
    int                 d_idPos; /*!< Position of the vehicle in the vehicle list of the corresponding depot */
    int                 d_vehicleType; /*!< Vehicle type */
    int                 d_depotID; /*!< Depot the vehicle belongs to */
    double              d_drivingSpeed; /*!< Driving speed per unit of time */
    double              d_cost; /*!< Cost of driving per unit of time */
    int                 d_capacity; /*!< Total capacity of the vehicle */
    double              d_serviceTime; /*!< Total service time of the vehicle */

    Route               d_route; /*!< Route of the vehicle */

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

/**
 * Get the ID of the vehicle.
 * @return ID of the vehicle
 */
inline int Vehicle::getID() const
{
    return d_id;
}

/**
 * Get the position of the vehicle within its depot.
 * @return Position of the vehicle within its depot
 */
inline int Vehicle::getIDPos() const
{
    return d_idPos;
}

/**
 * Get the vehicle type.
 * @return Vehicle type
 */
inline int Vehicle::getVehicleType() const
{
    return d_vehicleType;
}

/**
 * Get the ID of the depot the vehicle is in.
 * @return ID of the depot the vehicle is in
 */
inline int Vehicle::getDepotID() const
{
    return d_depotID;
}

/**
 * Get the driving speed of the vehicle per unit of time.
 * @return Driving speed
 */
inline double Vehicle::getDrivingSpeed() const
{
    return d_drivingSpeed;
}

/**
 * Get the driving cost per unit of time.
 * @return Driving cost per unit of time
 */
inline double Vehicle::getDrivingCost() const
{
    return d_cost / d_drivingSpeed;
}

/**
 * Get the driving cost per unit of distance
 * @return Driving cost per unit of distance
 */
inline double Vehicle::getCost() const
{
    return d_cost;
}

/**
 * Get the total capacity of the vehicle.
 * @return Total capacity of the vehicle
 */
inline int Vehicle::getCapacity() const
{
    return d_capacity;
}

/**
 * Get the total service time of the vehicle.
 * @return Total service time
 */
inline double Vehicle::getServiceTime() const
{
    return d_serviceTime;
}

/**
 * Get the route of the vehicle
 * @return Route
 */
inline Route &Vehicle::getRoute()
{
    return d_route;
}

/**
 * Get the route of the vehicle as a constant
 * @return Constant Route
 */
inline Route const &Vehicle::getRoute() const
{
    return d_route;
}

/**
 * Get the total cost of the vehicle (excluding penalty costs).
 * @return Cost of the vehicle
 */
inline double Vehicle::getTotalCost() const
{
    return d_route.getDistance() * d_cost;
}

/**
 * Get the total time the vehicle is driving.
 * @return Total time the vehicle is driving
 */
inline double Vehicle::getDrivingTime() const
{
    return d_route.getDistance() / d_drivingSpeed;
}

/**
 * Get the duration of the route. So driving time plus the service times.
 * @return Duration of the route
 */
inline double Vehicle::getRouteDuration() const
{
    return getDrivingTime() + d_route.getServiceTime();
}

/**
 * Get the penalty time of the vehicle.
 * @return Penalty time of the vehicle
 */
inline double Vehicle::getPenaltyTime() const
{
    return std::max(0.0, getRouteDuration() - d_serviceTime);
}

/**
 * Get the leftover capacity of the vehicle.
 * @return Leftover capacity of the vehicle
 */
inline int Vehicle::getLeftoverCapacity() const
{
    return std::max(0, d_capacity - d_route.getLoad());
}

/**
 * Remove customer from the route of the vehicle.
 * @param customerID ID of the customer to be removed
 * @return Demand of the customer who is removed
 */
inline int Vehicle::removeCustomer(int customerID)
{
    return d_route.removeCustomer(customerID);
}

/**
 * Add customer to the route of the vehicle
 * @param customerID    ID of the customer to be added
 * @param load          Load of the customer to be added
 * @param routePos      Position in the route where the customer must be inserted
 */
inline void Vehicle::addCustomer(int customerID, int load, int routePos)
{
    d_route.addCustomer(customerID, load, routePos);
}

/**
 * Indicates whether the route of the vehicle containts customers or not.
 * @return True if the route is empty, and false otherwise
 */
inline bool Vehicle::emptyRoute() const
{
    return (d_route.getRoute().size() == 2);
}

/**
 * Get the list of customers (and depot) of the route of the vehicle.
 * @return List of customers including the depots
 */
inline std::vector<int> Vehicle::getCustomerList() const
{
    return d_route.getRoute();
}

#endif //ORACS_VEHICLE_H
