//
// Created by Mark van der Broek on 17/03/2017.
//

/**
 * @brief Constructor
 *
 * @param [in] env              Environment pointer
 * @param [in] id               ID for the depot
 * @param [in] vehicles         Vector of all vehicles to add to the depot
 * @param [in] leftOverCapacity The leftover capacity of the depot
 */

#include "depot.ih"

Depot::Depot(Env *env, int id, std::vector<Vehicle> &vehicles, int leftOverInventory)
        :
        d_env(env),
        d_id(id),
        d_vehicles(vehicles),
        d_leftOverInventory(leftOverInventory),
        d_inventory(leftOverInventory)
{}