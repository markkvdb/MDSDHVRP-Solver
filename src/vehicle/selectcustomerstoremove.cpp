//
// Created by Mark van der Broek on 11/03/2017.
//

#include "vehicle.ih"

vector<int> Vehicle::selectCustomersToRemove(int q)
{
    // Delete latest customers of route
    int customersToDelete = min(q, static_cast<int>(d_route.getRoute().size() - 2));

    return vector<int>{end(d_route.getRoute()) - customersToDelete, end(d_route.getRoute())};
}