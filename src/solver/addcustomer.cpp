//
// Created by Mark van der Broek on 03/03/2017.
//

#include "solver.ih"

void Solver::addCustomer(int pickedCustomer, double &remainingCapacity, std::vector<int> &customerList,
                           std::vector<double> &customerDropOff, std::vector<int> &depotCustomerAllocation)
{

    // Add customer to the customer list of the vehicle
    customerList.push_back(pickedCustomer);

    Customer &customer = d_env->d_customers[pickedCustomer];

    // Check if the whole demand can be satisfied
    if (customer.getRemainingDemand() <= remainingCapacity)
    {
        // Add whole demand to the drop off and set customer remaining demand to zero
        customerDropOff.push_back(customer.getRemainingDemand());
        remainingCapacity -= customer.getRemainingDemand();
        customer.changeDemand(-customer.getRemainingDemand());


        // Delete customer from the depot customer allocation
        depotCustomerAllocation.erase(remove(begin(depotCustomerAllocation), end(depotCustomerAllocation), pickedCustomer),
                                      end(depotCustomerAllocation));

    }
    else // Not all demand can be fullfilled
    {
        customerDropOff.push_back(remainingCapacity);
        customer.changeDemand(-remainingCapacity);
        remainingCapacity = 0;
    }
}
