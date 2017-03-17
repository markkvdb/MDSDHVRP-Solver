//
// Created by Mark van der Broek on 11/03/2017.
//

/**
 * @brief Compute the gain of removing the customer from all its routes.
 *
 * @param [in] solution     Solution to delete the customer from
 * @param [in] customerID   ID of the customer to remove
 *
 * @return Total gain of removing customer
 */

#include "solver.ih"

double Solver::computeRemovalGain(Solution &solution, int customerID)
{
    double sumRemoveGain = 0;
    for (pair<int, int> place: solution.getCustomers()[customerID].getVehicles())
    {
        sumRemoveGain += solution.getDepots()[place.first].getVehicle(place.second).removalGain(customerID);
    }

    return sumRemoveGain;
}