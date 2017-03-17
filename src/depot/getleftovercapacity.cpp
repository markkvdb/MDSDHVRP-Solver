//
// Created by Mark van der Broek on 14/03/2017.
//

/**
 * @brief   Get the total leftover capacity of the depot by taking the minimum of the leftover inventory and
 *          the total leftover capacity of its vehicles.
 *
 * @return The total leftover inventory of the vehicle
 */

#include "depot.ih"

int Depot::getLeftOverInventory() const
{
    int totalCapacityVehicles = 0;
    for (Vehicle const &vehicle: d_vehicles)
        totalCapacityVehicles += vehicle.getLeftoverCapacity();

    return min(totalCapacityVehicles, d_leftOverInventory);
}