//
// Created by Mark van der Broek on 03/03/2017.
//

#include "solver.ih"

vector<vector<pair<int, int>>> Solver::allocateCustomers()
{
    // Create Depot-Customer allocation
    vector<vector<pair<int, int>>> depotCustomerAllocations(d_env->d_currentSolution.getDepots().size());
    vector<int> totalVehicleCapacity(d_env->d_currentSolution.getDepots().size());

    vector<int> orderedCustomers(d_env->d_currentSolution.getCustomers().size());
    iota(begin(orderedCustomers), end(orderedCustomers), 0);

    for (Depot &depot: d_env->d_currentSolution.getDepots())
    {
        for (Vehicle &vehicle: depot.getVehicles())
        {
            totalVehicleCapacity[depot.getID()] += vehicle.getCapacity();
        }
    }

    // Sort customers on ascending demand size
     sort(begin(orderedCustomers), end(orderedCustomers),
         [&](int lhs, int rhs)
         {
             return d_env->d_currentSolution.getCustomers()[lhs].getDemand() <
                     d_env->d_currentSolution.getCustomers()[rhs].getDemand();
         });

    for (int customerNumber: orderedCustomers)
    {
        // Select customer
        Customer &customer = d_env->d_currentSolution.getCustomers()[customerNumber];
        int customerDemand = customer.getDemand();

        // Get ordered list of depots based on distance from customer
        vector<int> const &sortedDepots = getClosestDepots(customerNumber);

        // Loop till all demand is fulfilled
        for (int depot: sortedDepots)
        {
            Depot &realDepot = d_env->d_currentSolution.getDepots()[depot];

            // Once all demand is fulfilled stop looking for new depots to allocate to.
            if (customerDemand <= 0)
                break;

            int minConstraints = min(realDepot.getLeftOverInventory(), totalVehicleCapacity[depot]);

            if (minConstraints > 0)
            {
                int fulfilledDemand = 0;

                if (minConstraints < customerDemand)
                    fulfilledDemand = minConstraints;
                else
                    fulfilledDemand = customerDemand;

                // Update the inventory of the depot (not of the customer)
                realDepot.changeInventory(-fulfilledDemand);
                totalVehicleCapacity[depot] -= fulfilledDemand;
                customerDemand -= fulfilledDemand;

                depotCustomerAllocations[depot].push_back(make_pair(customerNumber, fulfilledDemand));
            }
        }
        if (customerDemand > 0)
            cerr << "Not all demand satisfied\n";
    }

    return depotCustomerAllocations;
}
