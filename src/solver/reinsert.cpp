//
// Created by Mark van der Broek on 09/03/2017.
//

#include "solver.ih"

void Solver::reinsert(Solution &solution, std::vector<int> &customersToAdd)
{
    while (not customersToAdd.empty())
    {
        // Select customer to add to route
        uniform_int_distribution<int> uni(0, static_cast<int>(customersToAdd.size() - 1));
        int positionCustomer = uni(d_env->d_rng);
        int selectedCustomer = customersToAdd[positionCustomer];

        double minInsertion = numeric_limits<double>::max();
        int depotID = -1;
        int vehicleID = -1;
        int routePos = -1;

        for (Depot &depot: solution.getDepots())
        {
            if (depot.getLeftOverInventory() <= 0)
                continue;

            for (Vehicle const &vehicle: depot.getVehicles())
            {
                if (vehicle.getLeftoverCapacity() <= 0)
                    continue;

                // Find cheapest insertion for this vehicle
                pair<int, double> insertion = vehicle.cheapestInsertion(selectedCustomer);

                //
                if (insertion.second < minInsertion)
                {
                    minInsertion = insertion.second;
                    depotID = depot.getID();
                    vehicleID = vehicle.getID();
                    routePos = insertion.first;
                }
            }
        }
        // DEBUG
        if (depotID == -1)
        {
            cerr << "No insertion possible \n";
        }

        customersToAdd.erase(begin(customersToAdd) + positionCustomer);
        //insertCustomer(solution, selectedCustomer, depotID, vehicleID, routePos, customersToAdd);
    }
}