//
// Created by Mark van der Broek on 11/03/2017.
//

#include "solver.ih"

vector<int> Solver::costRemoval(Solution &solution, int q)
{
    // Customerlist to be deleted
    vector<int> orderedCustomers(solution.getCustomers().size());
    iota(begin(orderedCustomers), end(orderedCustomers), 0);

    vector<double> gains(solution.getCustomers().size());

    for (size_t customerIdx = 0; customerIdx != solution.getCustomers().size(); ++customerIdx)
    {
        gains[customerIdx] = computeRemovalGain(solution, customerIdx);
    }

    // Sort customers on descending gains
    sort(begin(orderedCustomers), end(orderedCustomers),
         [&](int lhs, int rhs)
         {
             return gains[lhs] > gains[rhs];
         });

    vector<int> customersToRemove{begin(orderedCustomers), begin(orderedCustomers) + q};
    removeCustomers(solution, customersToRemove);

    return customersToRemove;
}