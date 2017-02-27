//
// Created by Mark van der Broek on 27/02/2017.
//

#ifndef ORACS_DEPOT_H
#define ORACS_DEPOT_H

#include <vector>
#include "../vehicle/vehicle.h"

class Depot {
    std::vector<Vehicle> d_vehicles;
    int d_inventory;

public:
    Depot();
    Depot(std::vector<Vehicle> &vehicles);
    int getInventory();

private:


};

inline int Depot::getInventory()
{
    return d_inventory;
}

#endif //ORACS_DEPOT_H
