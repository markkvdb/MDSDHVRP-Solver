//
// Created by Mark van der Broek on 27/02/2017.
//

#ifndef ORACS_DEPOT_H
#define ORACS_DEPOT_H

#include <vector>
#include "../inc/vehicle.h"
#include <fstream>

class Env;

/**
 * Depot is a class which holds a vehicle list and has a limited inventory.
 */
class Depot {

    Env *                   d_env; /*!< Environment pointer */
    int                     d_id; /*!< ID of the depot */
    std::vector<Vehicle>    d_vehicles; /*!< Vector of vehicles of the depot */
    int                     d_inventory; /*!< Total inventoryof the depot */
    int                     d_leftOverInventory; /*!< Leftover inventory of the depot */

public:
    Depot() = delete;
    Depot(Env *env, int id, int leftOverInventory);
    Depot(Env *env, int id, std::vector<Vehicle> &vehicles, int leftOverInventory);

    std::vector<Vehicle> &  getVehicles();
    Vehicle &               getVehicle(int vehicleNumber);
    int                     getID();
    int                     getNumberOfVehicles();
    int                     getLeftOverInventory()          const;
    int                     getInventory()                  const;
    void                    changeInventory(int amount);
    void                    updateInventory();
    void                    addVehicle(Vehicle vehicle);

    friend std::ostream& operator<<(std::ostream &os, Depot const &depot);
};

/**
 * Get the list of vehicles.
 * @return Vector of vehicles
 */
inline std::vector<Vehicle> &Depot::getVehicles()
{
    return d_vehicles;
}

/**
 * Get the vehicle with position vehicleNumber.
 * @param vehicleNumber Position of the vehicle within the vehicle vector
 * @return Vehicle to be selected
 */
inline Vehicle &Depot::getVehicle(int vehicleNumber)
{
    return d_vehicles[vehicleNumber];
}

/**
 * Get ID of the depot.
 * @return ID of the depot
 */
inline int Depot::getID()
{
    return d_id;
}

/**
 * Get number of vehicles within the depot.
 * @return Number of vehicles within the depot
 */
inline int Depot::getNumberOfVehicles()
{
    return d_vehicles.size();
}

/**
 * Change the left over inventory of the depot.
 * @param amount Amount the change the inventory with
 */
inline void Depot::changeInventory(int amount)
{
    d_leftOverInventory += amount;
}

/**
 * Get the total inventory of the depot.
 * @return Total inventory of the depot
 */
inline int Depot::getInventory() const
{
    return d_inventory;
}

/**
 * Add vehicle to the depot.
 * @param vehicle Vehicle to be added
 */
inline void Depot::addVehicle(Vehicle vehicle)
{
    d_vehicles.push_back(vehicle);
}

#endif //ORACS_DEPOT_H
