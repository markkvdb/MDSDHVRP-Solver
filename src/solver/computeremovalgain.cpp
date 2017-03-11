//
// Created by Mark van der Broek on 11/03/2017.
//

#include "solver.ih"

double Solver::computeRemovalGain(Solution &solution, int customerID)
{
    double sumRemoveGain = 0;
    for (pair<int, int> place: solution.getCustomers()[customerID].getVehicles())
    {
        sumRemoveGain += solution.getDepots()[place.first].getVehicle(place.second).removalGain(customerID);
    }
}