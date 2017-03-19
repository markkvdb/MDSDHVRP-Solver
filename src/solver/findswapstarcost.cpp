//
// Created by Mark van der Broek on 14/03/2017.
//

/**
 * @brief Find the cost of applying the swapstar operator to customer1 and customer 2.
 *
 * @param [in] s    Solution
 * @param [in] customerIdx1 The position of the first customer in the its vehicle
 * @param [in] vehicle1     The vehicle of the first customer
 * @param [in] customerIdx2 The position of the second customer in the its vehicle
 * @param [in] vehicle2     The vehicle of the second customer
 *
 * @return Pair where the first elements is a dummy where 0 indicates insertion before the first customer, and 1
 *         indicates after the first customer. The second elements indicates the cost of this insertion.
 */

#include "solver.ih"

// Returns option where 0 indicates insertion before, and 1 indicates an insertion after.

pair<int, double> Solver::findSwapStarCost(Solution &s, int customerIdx1, Vehicle &vehicle1, int customerIdx2, Vehicle &vehicle2)
{
    vector<int> &route1 = vehicle1.getRoute().getRoute();
    vector<int> &route2 = vehicle2.getRoute().getRoute();
    Customer &customer1 = s.getCustomers()[route1[customerIdx1]];
    Customer &customer2 = s.getCustomers()[route2[customerIdx2]];
    int option = -1;
    double extraDistance1 = -1;

    // Insert before
    double extraDistance1Option1 = d_env->d_distanceMatrix[route1[customerIdx1-1]][route2[customerIdx2]] +
                                   d_env->d_distanceMatrix[route2[customerIdx2]][route1[customerIdx1]] -
                                   d_env->d_distanceMatrix[route1[customerIdx1-1]][route1[customerIdx1]];

    // Insert after
    double extraDistance1Option2 = d_env->d_distanceMatrix[route1[customerIdx1]][route2[customerIdx2]] +
                                   d_env->d_distanceMatrix[route2[customerIdx2]][route1[customerIdx1+1]] -
                                   d_env->d_distanceMatrix[route1[customerIdx1]][route1[customerIdx1+1]];

    if (extraDistance1Option1 < extraDistance1Option2)
    {
        option = 0;
        extraDistance1 = extraDistance1Option1;
    }
    else
    {
        option = 1;
        extraDistance1 = extraDistance1Option2;
    }

    double extraDistance2 = d_env->d_distanceMatrix[route2[customerIdx2-1]][route1[customerIdx1]] +
                            d_env->d_distanceMatrix[route1[customerIdx1]][route2[customerIdx2+1]] -
                            d_env->d_distanceMatrix[route2[customerIdx2-1]][route2[customerIdx2]] -
                            d_env->d_distanceMatrix[route2[customerIdx2]][route2[customerIdx2+1]];

    double extraPenalty1 = (max(0.0, vehicle1.getPenaltyTime() + extraDistance1 / vehicle1.getDrivingSpeed()
                                     + customer2.getServiceTime()) - vehicle1.getPenaltyTime()) * d_env->d_penalty;
    double extraPenalty2 = (max(0.0, vehicle2.getPenaltyTime() + extraDistance2 / vehicle2.getDrivingSpeed() +
            customer1.getServiceTime() - customer2.getServiceTime()) - vehicle2.getPenaltyTime()) * d_env->d_penalty;
    double insertionCost = extraDistance1 * vehicle1.getCost() + extraPenalty1 + extraDistance2 * vehicle2.getCost() + extraPenalty2;
    return make_pair(option, insertionCost);
}