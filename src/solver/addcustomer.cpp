//
// Created by Mark van der Broek on 03/03/2017.
//

#include "solver.ih"

void Solver::addCustomer(int pickedCustomer, double &remainingCapacity, vector<int> &customerList,
                         vector<double> &customerDropOff, std::vector<int> &depotCustomerAllocation,
                         vector<double> &depotCustomerDemand)
{

    // Add customer to the customer list of the vehicle
    customerList.push_back(pickedCustomer);

    Customer &customer = d_env->d_currentSolution.getCustomers()[pickedCustomer];

    long positionCustomer = find(begin(depotCustomerAllocation), end(depotCustomerAllocation), pickedCustomer) - begin(depotCustomerAllocation);

    // Check if the whole demand can be satisfied
    if (depotCustomerDemand[positionCustomer] <= remainingCapacity)
    {
        // Add whole demand to the drop off and set customer remaining demand to zero
        customerDropOff.push_back(depotCustomerDemand[positionCustomer]);
        remainingCapacity -= depotCustomerDemand[positionCustomer];
        customer.changeDemand(-depotCustomerDemand[positionCustomer]);

        // Delete customer from the depot customer allocation
        depotCustomerAllocation.erase(begin(depotCustomerAllocation) + positionCustomer);
        depotCustomerDemand.erase(begin(depotCustomerDemand) + positionCustomer);

    }
    else // Not all demand can be fulfilled
    {
        customerDropOff.push_back(remainingCapacity);
        customer.changeDemand(-remainingCapacity);
        depotCustomerDemand[positionCustomer] -= remainingCapacity;
        remainingCapacity = 0;
    }

}
