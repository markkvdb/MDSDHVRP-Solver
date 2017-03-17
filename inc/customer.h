//
// Created by Mark van der Broek on 27/02/2017.
//

/**
 * Customer class
 *
 * @param d_env             Environment pointer
 * @param d_demand          Total demand of the customer
 * @param d_remainingDemand Total leftover demand of the customer
 * @param d_serviceTime     Service time of the customer
 * @param d_vehicles        Vector of vehicles the customer is positioned in
 */

#ifndef ORACS_CUSTOMER_H
#define ORACS_CUSTOMER_H

#include <vector>
#include <fstream>

class Env;

class Customer {

    Env *                               d_env; /*!< Environment pointer */
    int                                 d_id; /*!< ID of the customer */
    int                                 d_demand; /*!< Total demand of the customer */
    int                                 d_remainingDemand; /*!< Total leftover demand of the customer */
    double                              d_serviceTime; /*!< Service time of the customer */
    std::vector<std::pair<int, int>>    d_vehicles; /*!< Vector of the vehicles the customer is positioned in */

public:
    Customer() = delete;
    Customer(Env *env, int id, int demand, double serviceTime);

    int                                 getId()                      const;
    int                                 getDemand()                  const;
    double                              getServiceTime()             const;
    int                                 getRemainingDemand()         const;
    std::vector<std::pair<int, int>> &  getVehicles();
    void                                deleteVehicle(int depotID, int vehicleID);
    void                                changeDemand(int demand);
    void                                addToVehicle(int depotID, int vehicleID);
    void                                resetRemainingDemand();

    friend std::ostream&                operator<<(std::ostream &os, Customer const &customer);

};

/**
 * Get ID of the customer
 * @return ID of the customer
 */
inline int Customer::getId() const
{
    return d_id;
}

/**
 * Get demand of the customer
 * @return Demand of the customer
 */
inline int Customer::getDemand() const
{
    return d_demand;
}

/**
 * Get service time of the customer
 * @return Service time of the customer
 */
inline double Customer::getServiceTime() const
{
    return d_serviceTime;
}

/**
 * Get remaining demand of the customer
 * @return Remaining demand of the customer
 */
inline int Customer::getRemainingDemand() const
{
    return d_remainingDemand;
}

/**
 * Change the remaining demand of the customer
 * @param demand Amount of demand
 */
inline void Customer::changeDemand(int demand)
{
    d_remainingDemand += demand;
}

/**
 * Add vehicle to the vehicle list
 * @param depotID   ID of the depot
 * @param vehicleID Position of the vehicle within the depot
 */
inline void Customer::addToVehicle(int depotID, int vehicleID)
{
    d_vehicles.push_back(std::make_pair(depotID, vehicleID));
}

/**
 * Get vector of vehicles of the customer.
 * @return Vector of pairs where the first element is the depot ID, and the second element is the position of
 *         vehicle within the route.
 */
inline std::vector<std::pair<int, int>> &Customer::getVehicles()
{
    return d_vehicles;
}


#endif //ORACS_CUSTOMER_H
