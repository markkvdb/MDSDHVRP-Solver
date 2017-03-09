//
// Created by Mark van der Broek on 09/03/2017.
//

#include "solver.ih"

vector<int> Solver::randomRemoval(Solution &solution, int q)
{
    // Customerlist to be deleted
    vector<int> customersToRemove(q);

    // Select random customer
    uniform_int_distribution<int> uni(0, static_cast<int>(solution.getCustomers().size() - 1));
    int seedCustomer = uni(d_env->d_rng);

    // Get closest customers
    customersToRemove = getClosestCustomers(seedCustomer, q);

    // Delete the customers from their routes
    removeCustomers(solution, customersToRemove);

    return customersToRemove;
}