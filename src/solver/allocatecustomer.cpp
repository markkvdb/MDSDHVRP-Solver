//
// Created by Mark van der Broek on 03/03/2017.
//

#include "solver.ih"

pair<vector<vector<int>>, vector<vector<double>>> Solver::allocateCustomers()
{
    // Create Depot-Customer allocation
    vector<vector<int>> depotCustomerAllocation(d_env->d_depots.size());
    vector<vector<double>> depotCustomerDemand(d_env->d_depots.size());

    vector<int> orderedCustomers(d_env->d_customers.size());
    iota(std::begin(orderedCustomers), std::end(orderedCustomers), 0);

    // Sort customers on ascending demand size
    sort(begin(orderedCustomers), end(orderedCustomers),
         [&](int lhs, int rhs)
         {
             return d_env->d_customers[lhs].getDemand() < d_env->d_customers[rhs].getDemand();
         });

    for (int customerNumber: orderedCustomers)
    {
        // Select customer
        Customer &customer = d_env->d_customers[customerNumber];
        double customerDemand = customer.getDemand();

        // Get ordered list of depots based on distance from customer
        vector<int> const &sortedDepots = getClosestDepots(customerNumber);

        // Loop till all demand is fulfilled
        for (int depot: sortedDepots)
        {
            Depot &realDepot = d_env->d_depots[depot];

            // Once all demand is fulfilled stop looking for new depots to allocate to.
            if (customerDemand <= 0)
                break;

            if (realDepot.getLeftOverInventory() > 0)
            {
                double fulfilledDemand = 0;

                if (realDepot.getLeftOverInventory() < customerDemand)
                    fulfilledDemand = realDepot.getLeftOverInventory();
                else
                    fulfilledDemand = customerDemand;

                // Update the inventory of the depot (not of the customer)
                realDepot.changeInventory(-fulfilledDemand);
                customerDemand -= fulfilledDemand;

                depotCustomerAllocation[depot].push_back(customerNumber);
                depotCustomerDemand[depot].push_back(fulfilledDemand);
            }
        }
    }

    return make_pair(depotCustomerAllocation, depotCustomerDemand);
}
