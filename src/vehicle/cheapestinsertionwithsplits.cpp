//
// Created by Mark van der Broek on 13/03/2017.
//

/**
 * Find the cheapest insertion option for the customer within the vehicle's route where splits are allowed.
 * @param customerID    ID of the customer to be inserted
 * @return Pair with the first element the position of the best insertion move, and the second element the cost
 *         of this insertion
 */

#include "vehicle.ih"

pair<int, double> Vehicle::cheapestInsertionWithSplits(int customerID) const
{
    if (findCustomer(customerID) != d_route.getRoute().size())
    {
        return make_pair(-2, 0.0);
    }

    int position = -1;
    double minInsertionCost = numeric_limits<double>::max();
    for (int insertOption = 0; insertOption != d_route.getRoute().size() - 1; ++insertOption)
    {
        // Extra distance
        double insertionCostie = insertionCost(insertOption, customerID);

        if (insertionCostie < minInsertionCost)
        {
            position = insertOption + 1;
            minInsertionCost = insertionCostie;
        }
    }

    return make_pair(position, minInsertionCost);
}