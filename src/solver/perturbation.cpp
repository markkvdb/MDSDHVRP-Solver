//
// Created by Mark van der Broek on 09/03/2017.
//

#include "solver.ih"

void Solver::perturbation(Solution &solution, int q)
{
    discrete_distribution<int> dist{5, 5, 1};

    vector<int> customersToRemove = d_perturbationOperators[dist(d_env->d_rng)](solution, q);

    reinsert(solution, customersToRemove);

}