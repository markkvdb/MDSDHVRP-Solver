//
// Created by Mark van der Broek on 11/03/2017.
//

/**
 * Gain of removing customer from the route of the vehicle.
 * @param [in] customerID   ID of the customer
 * @return Gain of removing the customer of the route
 */

#include "vehicle.ih"

double Vehicle::removalGain(int customerID)
{
    auto const &route = d_route.getRoute();
    Solution &solution = d_env->d_newSolution;
    long positionCustomer = find(begin(route), end(route), customerID) - begin(route);

    double minusDistance = d_env->distanceMatrix(route[positionCustomer-1], customerID) +
                           d_env->distanceMatrix(customerID, route[positionCustomer+1]) -
                           d_env->distanceMatrix(route[positionCustomer - 1], route[positionCustomer + 1]);

    double penaltyReduction = 0;
    if (getPenaltyTime() != 0.0)
    {
        double oldPenalty = getPenaltyTime();
        double newPenalty = max(0.0, oldPenalty - solution.getCustomers()[customerID].getServiceTime() -
                                (minusDistance / d_drivingSpeed));
        penaltyReduction = d_env->d_penalty * (oldPenalty - newPenalty);
    }

    // POSITIVE = GOOD
    return penaltyReduction + minusDistance / d_drivingSpeed;
}