//
// Created by Mark van der Broek on 11/03/2017.
//

/**
 * Select q customers to remove from the route. If the number of customers in the route is less than q we delete
 * all customers.
 * @param q Number of customers to remove
 * @return IDs of the customers to remove
 */

#include "vehicle.ih"

vector<int> Vehicle::selectCustomersToRemove(int q)
{
    // Delete latest customers of route
    int customersToDelete = min(q, static_cast<int>(d_route.getRoute().size() - 2));

    return vector<int>{end(d_route.getRoute()) - customersToDelete - 1, end(d_route.getRoute()) - 1};
}