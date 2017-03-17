//
// Created by Mark van der Broek on 13/03/2017.
//

/**
 * Find the customer in the vehicle's route.
 * @param [in] customerID   ID of the customer
 * @return Position of the customer within the route
 */

#include "vehicle.ih"

long Vehicle::findCustomer(int customerID) const
{
    return d_route.findCustomer(customerID);
}