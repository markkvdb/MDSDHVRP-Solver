//
// Created by Mark van der Broek on 14/03/2017.
//

#include "depot.ih"

int Depot::getLeftOverInventory() const
{
    int totalCapacityVehicles = 0;
    for (Vehicle const &vehicle: d_vehicles)
        totalCapacityVehicles += vehicle.getLeftoverCapacity();

    return min(totalCapacityVehicles, d_leftOverInventory);
}