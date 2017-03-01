//
// Created by Mark van der Broek on 27/02/2017.
//

#include "../../inc/depot.h"
#include <iostream>

using namespace std;

Depot::Depot()
{}

Depot::Depot(int leftOverInventory)
:
    d_vehicles(std::vector<Vehicle>{}),
    d_leftOverInventory(leftOverInventory)
{
    cout << "Created depot\n";
}

Depot::Depot(std::vector<Vehicle> &vehicles, int leftOverInventory)
:
    d_vehicles(vehicles),
    d_leftOverInventory(leftOverInventory)
{}