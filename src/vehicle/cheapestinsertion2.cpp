//
// Created by Mark van der Broek on 13/03/2017.
//

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