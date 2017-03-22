//
// Created by Mark van der Broek on 13/03/2017.
//

/**
 * Find the cost of insertion of the two customers in a particular place in the route.
 * @param [in] option       Place in the route to consider
 * @param [in] customerID1  ID of the first customer
 * @param [in] customerID2  ID of the second customer
 * @return Cost of insertion
 */

#include "vehicle.ih"

double Vehicle::insertionCost(int option, int customerID1, int customerID2) const
{
    double extraDistance = d_env->distanceMatrix(d_route.getRoute()[option], customerID1) +
                           d_env->distanceMatrix(customerID2, d_route.getRoute()[option + 1]) -
                           d_env->distanceMatrix(d_route.getRoute()[option], d_route.getRoute()[option+1]);

    return extraDistance;
}