//
// Created by Mark van der Broek on 09/03/2017.
//

#include "vehicle.ih"

double Vehicle::insertionCost(int option, int customerID) const
{
    double extraDistance = d_env->d_distanceMatrix[d_route.getRoute()[option]][customerID] +
                           d_env->d_distanceMatrix[customerID][d_route.getRoute()[option + 1]] -
                           d_env->d_distanceMatrix[d_route.getRoute()[option]][d_route.getRoute()[option + 1]];

    // Add exta time for driving, service time and look if penalty cost is incurred.
    double oldPenaltyTime = max(0.0, getPenaltyTime());
    double newPenaltyTime = max(0.0, (extraDistance / d_drivingSpeed) +
            d_env->d_currentSolution.getCustomers()[customerID].getServiceTime() + getRouteDuration() - d_serviceTime);
    double penaltyCost = d_env->d_penalty * (newPenaltyTime - oldPenaltyTime);

    return extraDistance * d_cost + penaltyCost;
}