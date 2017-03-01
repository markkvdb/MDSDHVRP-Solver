//
// Created by Mark van der Broek on 01/03/2017.
//

#include "solution.ih"

vector<vector<int>> Solution::allocateCustomers()
{
    // Create Depot-Customer allocation
    vector<vector<int>> depotCustomerAllocation(d_depots.size());

    vector<int> orderedCustomers(d_customers.size());
    iota(std::begin(orderedCustomers), std::end(orderedCustomers), 0);

    // Sort customers on ascending demand size
    sort(begin(orderedCustomers), end(orderedCustomers),
         [&](int lhs, int rhs)
         {
             return d_customers[lhs].getDemand() < d_customers[rhs].getDemand();
         });

    for (int customerNumber: orderedCustomers)
    {
        // Select customer
        Customer &customer = d_customers[customerNumber];

        // Get ordered list of depots based on distance from customer
        vector<int> const &sortedDepots = getClosestDepots(customerNumber);

        // Loop till all demand is fulfilled
        for (int depot: sortedDepots)
        {
            Depot &realDepot = d_depots[depot];

            if (customer.getRemainingDemand() <= 0)
                break;

            if (realDepot.getLeftOverInventory() > 0)
            {
                double fulfilledDemand = 0;

                if (realDepot.getLeftOverInventory() < customer.getRemainingDemand())
                {
                    fulfilledDemand = -realDepot.getLeftOverInventory();
                } else {
                    fulfilledDemand = -customer.getRemainingDemand();
                }

                realDepot.changeInventory(fulfilledDemand);
                customer.changeDemand(fulfilledDemand);

                depotCustomerAllocation[depot].push_back(customerNumber);
            }
        }
    }

    return depotCustomerAllocation;
}