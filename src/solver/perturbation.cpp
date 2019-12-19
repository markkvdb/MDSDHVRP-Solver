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
    int operatorIdx = dist(d_env->d_rng);
    auto start = chrono::system_clock::now();
    double oldCost = solution.cost();

    vector<int> customersToRemove = d_perturbationOperators[operatorIdx](solution, q);

    reinsert(solution, customersToRemove, random, true);
    auto end = chrono::system_clock::now();
    d_perturbationTimes[operatorIdx].push_back(chrono::duration_cast<chrono::microseconds>(end - start).count());

    double newCost = solution.cost();

    d_perturbationImprovements[operatorIdx].push_back(oldCost - newCost);
}