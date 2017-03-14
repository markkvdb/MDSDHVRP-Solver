//
// Created by Mark van der Broek on 14/03/2017.
//

#include "solver.ih"

double Solver::findSwapStarCost(int customerIdx1, Vehicle &vehicle1, int customerIdx2, Vehicle &vehicle2)
{
    vector<int> &route1 = vehicle1.getRoute().getRoute();
    vector<int> &route2 = vehicle2.getRoute().getRoute();
    double extraDistance1 = d_env->d_distanceMatrix[route1[customerIdx1-1]][route2[customerIdx2]] +
                            d_env->d_distanceMatrix[route2[customerIdx2]][route1[customerIdx1]] -
                            d_env->d_distanceMatrix[route1[customerIdx1-1]][route1[customerIdx1]];

    double extraDistance2 = d_env->d_distanceMatrix[route2[customerIdx2-1]][route1[customerIdx1]] +
                            d_env->d_distanceMatrix[route1[customerIdx1]][route2[customerIdx2+1]] -
                            d_env->d_distanceMatrix[route2[customerIdx2-1]][route2[customerIdx2]] -
                            d_env->d_distanceMatrix[route2[customerIdx2]][route2[customerIdx2+1]];

    double extraPenalty1 = (max(0.0, vehicle1.getPenaltyTime() + extraDistance1 / vehicle1.getDrivingSpeed()) -
            vehicle1.getPenaltyTime()) * d_env->d_penalty;
    double extraPenalty2 = (max(0.0, vehicle2.getPenaltyTime() + extraDistance2 / vehicle2.getDrivingSpeed()) -
            vehicle2.getPenaltyTime()) * d_env->d_penalty;

    return extraDistance1 * vehicle1.getCost() + extraPenalty1 + extraDistance2 * vehicle2.getCost() + extraPenalty2;
}