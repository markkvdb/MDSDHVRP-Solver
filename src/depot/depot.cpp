//
// Created by Mark van der Broek on 27/02/2017.
//

#include "depot.ih"

using namespace std;

Depot::Depot(Env *env, int id, int leftOverInventory)
:
    d_env(env),
    d_id(id),
    d_vehicles(std::vector<Vehicle>{}),
    d_leftOverInventory(leftOverInventory),
    d_inventory(leftOverInventory)
{}

Depot::Depot(Env *env, int id, std::vector<Vehicle> &vehicles, int leftOverInventory)
:
    d_env(env),
    d_id(id),
    d_vehicles(vehicles),
    d_leftOverInventory(leftOverInventory),
    d_inventory(leftOverInventory)
{}