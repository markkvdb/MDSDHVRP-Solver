//
// Created by Mark van der Broek on 09/03/2017.
//

/**
 * @brief Perturbation mechanism. First select a random remove operator to delete q customers and add the q customers
 *        back in the solution using the reinsert operator.
 *
 * @param [in] solution Solution
 * @param [in] q        Number of customers to perturb
 */

#include "solver.ih"

void Solver::perturbation(Solution &solution, int q, bool random, double randomProb, double costProb, double routeProb)
{
    discrete_distribution<int> dist{randomProb, costProb, routeProb};

    vector<int> customersToRemove = d_perturbationOperators[dist(d_env->d_rng)](solution, q);

    reinsert(solution, customersToRemove, random);
}