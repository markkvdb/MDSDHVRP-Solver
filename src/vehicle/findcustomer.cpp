//
// Created by Mark van der Broek on 13/03/2017.
//

#include "vehicle.ih"

long Vehicle::findCustomer(int customerID) const
{
    return d_route.findCustomer(customerID);
}