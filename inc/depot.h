//
// Created by Mark van der Broek on 27/02/2017.
//

#ifndef ORACS_DEPOT_H
#define ORACS_DEPOT_H

#include <vector>
#include "../inc/vehicle.h"
#include <fstream>

class Env;

class Depot {

    Env *                   d_env;
    int                     d_id;
    std::vector<Vehicle>    d_vehicles;
    int                     d_inventory;
    int                     d_leftOverInventory;

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

private:


};

inline std::vector<Vehicle> &Depot::getVehicles()
{
    return d_vehicles;
}

inline Vehicle &Depot::getVehicle(int vehicleNumber)
{
    return d_vehicles[vehicleNumber];
}

inline int Depot::getID()
{
    return d_id;
}

inline int Depot::getNumberOfVehicles()
{
    return d_vehicles.size();
}

inline void Depot::changeInventory(int amount)
{
    d_leftOverInventory += amount;
}

inline int Depot::getInventory() const
{
    return d_inventory;
}

inline void Depot::addVehicle(Vehicle vehicle)
{
    d_vehicles.push_back(vehicle);
}

#endif //ORACS_DEPOT_H
