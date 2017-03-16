//
// Created by Mark van der Broek on 13/03/2017.
//

#include "vehicle.ih"

double Vehicle::insertionCost(int option, int customerID1, int customerID2) const
{
    double extraDistance = d_env->d_distanceMatrix[d_route.getRoute()[option]][customerID1] +
                           d_env->d_distanceMatrix[customerID2][d_route.getRoute()[option + 1]] -
                           d_env->d_distanceMatrix[d_route.getRoute()[option]][d_route.getRoute()[option+1]];

    return extraDistance;
}