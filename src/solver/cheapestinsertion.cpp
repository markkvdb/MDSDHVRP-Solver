//
// Created by Mark van der Broek on 06/03/2017.
//

#include "solver.ih"

pair<vector<int>, vector<double>> Solver::cheapestInsertion(int depotNumber, vector<int> &customerList, vector<double> &customerDropOff)
{
    int const depotIdx = d_env->d_currentSolution.getCustomers().size() + depotNumber;
    vector<int> route = {depotIdx, depotIdx};
    vector<double> routeDropOff = {0, 0};

    while (not customerList.empty())
    {
        int minimumCustomerIdx = -1;
        int minimumCustomer = -1;
        int minimumPlace = -1;
        double minimumDistance = numeric_limits<double>::max();

        for (int customerIdx = 0; customerIdx != customerList.size(); ++customerIdx)
        {
            int customer = customerList[customerIdx];
            for (int idx = 0; idx != route.size() - 1; ++idx)
            {
                double totalDistance = d_env->d_distanceMatrix[route[idx]][customer] +
                                       d_env->d_distanceMatrix[customer][route[idx+1]]-
                                       d_env->d_distanceMatrix[route[idx]][route[idx+1]];

                if (totalDistance < minimumDistance)
                {
                    minimumCustomerIdx = customerIdx;
                    minimumCustomer = customer;
                    minimumPlace = idx + 1;
                    minimumDistance = totalDistance;
                }
            }
        }


        customerList.erase(begin(customerList) + minimumCustomerIdx);
        route.insert(begin(route) + minimumPlace, minimumCustomer);
        routeDropOff.insert(begin(routeDropOff) + minimumPlace, customerDropOff[minimumCustomerIdx]);
        customerDropOff.erase(begin(customerDropOff) + minimumCustomerIdx);
    }

    return make_pair(route, routeDropOff);
}
