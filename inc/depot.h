//
// Created by Mark van der Broek on 27/02/2017.
//

#ifndef ORACS_DEPOT_H
#define ORACS_DEPOT_H

#include <vector>
#include "../inc/vehicle.h"

class Env;

class Depot {

    Env *                   d_env;
    int                     d_id;
    std::vector<Vehicle>    d_vehicles;
    double                  d_leftOverInventory;

public:
    Depot() = delete;
    Depot(Env *env, int id, double leftOverInventory);
    Depot(Env *env, int id, std::vector<Vehicle> &vehicles, double leftOverInventory);

    std::vector<Vehicle> &  getVehicles();
    Vehicle &               getVehicle(int vehicleNumber);
    size_t                  getNumberOfVehicles();
    double                  getLeftOverInventory();
    void                    changeInventory(double amount);
    void                    addVehicle(Vehicle vehicle);

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

inline size_t Depot::getNumberOfVehicles()
{
    return d_vehicles.size();
}

inline void Depot::changeInventory(double amount)
{
    d_leftOverInventory += amount;
}

inline double Depot::getLeftOverInventory()
{
    return d_leftOverInventory;
}

inline void Depot::addVehicle(Vehicle vehicle)
{
    d_vehicles.push_back(vehicle);
}

#endif //ORACS_DEPOT_H
