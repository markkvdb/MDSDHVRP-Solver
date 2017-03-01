//
// Created by Mark van der Broek on 27/02/2017.
//

#ifndef ORACS_DEPOT_H
#define ORACS_DEPOT_H

#include <vector>
#include "../inc/vehicle.h"

class Depot {
    std::vector<Vehicle> d_vehicles;
    int d_leftOverInventory;

public:
    Depot();
    Depot(int leftOverInventory);
    Depot(std::vector<Vehicle> &vehicles, int leftOverInventory);

    int getLeftOverInventory();
    void addVehicle(Vehicle &vehicle);

private:


};

inline int Depot::getLeftOverInventory()
{
    return d_leftOverInventory;
}

inline void Depot::addVehicle(Vehicle &vehicle)
{
    d_vehicles.push_back(vehicle);
}

#endif //ORACS_DEPOT_H
