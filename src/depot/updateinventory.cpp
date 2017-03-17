//
// Created by Mark van der Broek on 09/03/2017.
//

/**
 * @brief Update leftover inventory by substracting the total load of all vehicles from the total inventory.
 */

#include "depot.ih"

void Depot::updateInventory()
{
    int totalLoad = 0;
    for (Vehicle const &vehicle: d_vehicles)
    {
        totalLoad += vehicle.getRoute().getLoad();
    }

    d_leftOverInventory = d_inventory - totalLoad;
}