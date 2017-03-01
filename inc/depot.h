//
// Created by Mark van der Broek on 27/02/2017.
//

#ifndef ORACS_DEPOT_H
#define ORACS_DEPOT_H

#include <vector>
#include "../inc/vehicle.h"

class Depot {
    std::vector<Vehicle> d_vehicles;
    double d_leftOverInventory;

public:
    Depot();
    Depot(double leftOverInventory);
    Depot(std::vector<Vehicle> &vehicles, double leftOverInventory);

    double getLeftOverInventory();
    void addVehicle(Vehicle vehicle);

private:


};

inline double Depot::getLeftOverInventory()
{
    return d_leftOverInventory;
}

inline void Depot::addVehicle(Vehicle vehicle)
{
    d_vehicles.push_back(vehicle);
}

#endif //ORACS_DEPOT_H
