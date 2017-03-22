//
// Created by Mark van der Broek on 09/03/2017.
//

/**
 * Find the cost of insertion of customer in a particular place in the route.
 * @param [in] option       Place in the route to consider
 * @param [in] customerID  ID of the customer
 * @return Cost of insertion
 */

#include "vehicle.ih"

double Vehicle::insertionCost(int option, int customerID) const
{
    double extraDistance = d_env->distanceMatrix(d_route.getRoute()[option], customerID) +
                           d_env->distanceMatrix(customerID, d_route.getRoute()[option + 1]) -
                           d_env->distanceMatrix(d_route.getRoute()[option], d_route.getRoute()[option + 1]);

    // Add exta time for driving, service time and look if penalty cost is incurred.
    double oldPenaltyTime = getPenaltyTime();
    double newPenaltyTime = max(0.0, (extraDistance / d_drivingSpeed) +
            d_env->d_newSolution.getCustomers()[customerID].getServiceTime() + getRouteDuration() - d_serviceTime);
    double penaltyCost = d_env->d_penalty * (newPenaltyTime - oldPenaltyTime);

    return (extraDistance * d_cost + penaltyCost);
}