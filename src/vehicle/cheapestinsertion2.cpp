//
// Created by Mark van der Broek on 13/03/2017.
//

/**
 * Find cheapest insertion for two consecutive customers within the vehicle's route.
 * @param [in] customerID1  ID of the first customer to be inserted
 * @param [in] customerID2  ID of the second customer to be inserted
 * @return Pair with the first element the position of the best insertion move, and the second element the cost
 *         of this insertion
 */

#include "vehicle.ih"

pair<int, double> Vehicle::cheapestInsertion(int customerID1, int customerID2) const
{
    int position = -1;
    double minInsertionCost = numeric_limits<double>::max();
    for (int insertOption = 0; insertOption != d_route.getRoute().size() - 1; ++insertOption)
    {
        // Extra distance
        double insertionCostie = insertionCost(insertOption, customerID1, customerID2);

        if (insertionCostie < minInsertionCost)
        {
            position = insertOption + 1;
            minInsertionCost = insertionCostie;
        }
    }

    return make_pair(position, minInsertionCost);
}