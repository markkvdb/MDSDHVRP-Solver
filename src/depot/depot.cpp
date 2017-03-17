//
// Created by Mark van der Broek on 27/02/2017.
//

/**
 * @brief Constructor
 *
 * @param [in] env              Environment pointer
 * @param [in] id               ID for the depot
 * @param [in] leftOverCapacity The leftover capacity of the depot
 */

#include "depot.ih"

Depot::Depot(Env *env, int id, int leftOverInventory)
:
    d_env(env),
    d_id(id),
    d_vehicles(std::vector<Vehicle>{}),
    d_leftOverInventory(leftOverInventory),
    d_inventory(leftOverInventory)
{}
