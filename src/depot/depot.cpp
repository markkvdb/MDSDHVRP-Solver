//
// Created by Mark van der Broek on 27/02/2017.
//

#include "../../inc/depot.h"
#include <iostream>

using namespace std;

Depot::Depot()
{}

Depot::Depot(double leftOverInventory)
:
    d_vehicles(std::vector<Vehicle>{}),
    d_leftOverInventory(leftOverInventory)
{}

Depot::Depot(std::vector<Vehicle> &vehicles, double leftOverInventory)
:
    d_vehicles(vehicles),
    d_leftOverInventory(leftOverInventory)
{}