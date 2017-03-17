//
// Created by Mark van der Broek on 11/03/2017.
//

/**
 * @brief Remove operator of the perturbation mechanism. Randomly select a random route and delete q or if the number
 *        of customers in the list is smaller than q customers from the selected route.
 *
 * @param [in] solution Solution
 * @param [in] q        Number of customers to remove
 */

#include "solver.ih"

vector<int> Solver::routeRemoval(Solution &solution, int q)
{
    vector<pair<int, int>> nonEmptyRoutes = getNonEmptyRoutes(solution);

    uniform_int_distribution<int> uni(0, static_cast<int>(nonEmptyRoutes.size() - 1));

    pair<int, int> removedRoute = nonEmptyRoutes[uni(d_env->d_rng)];
    vector<int> customerToRemove = solution.getDepots()[removedRoute.first].getVehicle(removedRoute.second).selectCustomersToRemove(q);

    removeCustomers(solution, customerToRemove);

    return customerToRemove;
}