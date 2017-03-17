//
// Created by Mark van der Broek on 09/03/2017.
//

#include "vehicle.ih"

/**
 * Find the cheapest insertion option for the customer within the vehicle's route.
 * @param customerID    ID of the customer to be inserted
 * @param random        Boolean to indicate whether the insertion cost has to be muliplied by a random factor
 * @return Pair with the first element the position of the best insertion move, and the second element the cost
 *         of this insertion
 */

pair<int, double> Vehicle::cheapestInsertion(int customerID, bool random) const
{
    int position = -1;
    double minInsertionCost = numeric_limits<double>::max();
    for (int insertOption = 0; insertOption != d_route.getRoute().size() - 1; ++insertOption)
    {
        // Extra distance with randomness
        double insertionCostie = insertionCost(insertOption, customerID);
        if (random)
        {
            uniform_real_distribution<double> uni(0.8, 1.2);
            insertionCostie *= uni(d_env->d_rng);
        }

        if (insertionCostie < minInsertionCost)
        {
            position = insertOption + 1;
            minInsertionCost = insertionCostie;
        }
    }

    return make_pair(position, minInsertionCost);
}