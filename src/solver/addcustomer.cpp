//
// Created by Mark van der Broek on 03/03/2017.
//

#include "solver.ih"

void Solver::addCustomer(int pickedCustomer, int &remainingCapacity, vector<int> &customerList,
                         vector<int> &customerDropOff, vector<pair<int, int>> &depotCustomerAllocation)
{
    // Add customer to the customer list of the vehicle
    customerList.push_back(pickedCustomer);

    Customer &customer = d_env->d_currentSolution.getCustomers()[pickedCustomer];

    long positionCustomer = find_if(begin(depotCustomerAllocation), end(depotCustomerAllocation),
                                    [&](pair<int, int> const & e) { return e.first == pickedCustomer; }) - begin(depotCustomerAllocation);

    if (positionCustomer == depotCustomerAllocation.size())
        cerr << "Mistake\n";
    // Check if the whole demand can be satisfied
    if (depotCustomerAllocation[positionCustomer].second <= remainingCapacity)
    {
        // Add whole demand to the drop off and set customer remaining demand to zero
        customerDropOff.push_back(depotCustomerAllocation[positionCustomer].second);
        remainingCapacity -= depotCustomerAllocation[positionCustomer].second;
        customer.changeDemand(-depotCustomerAllocation[positionCustomer].second);

        // Delete customer from the depot customer allocation
        depotCustomerAllocation.erase(begin(depotCustomerAllocation) + positionCustomer);
    }
    else // Not all demand can be fulfilled
    {
        customerDropOff.push_back(remainingCapacity);
        customer.changeDemand(-remainingCapacity);
        depotCustomerAllocation[positionCustomer].second -= remainingCapacity;
        remainingCapacity = 0;
    }
}
