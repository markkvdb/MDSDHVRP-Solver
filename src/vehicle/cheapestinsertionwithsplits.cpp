//
// Created by Mark van der Broek on 13/03/2017.
//

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