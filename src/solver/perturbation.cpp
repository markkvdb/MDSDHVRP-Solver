//
// Created by Mark van der Broek on 09/03/2017.
//

#include "solver.ih"

void Solver::perturbation(Solution &solution, int q)
{
    uniform_int_distribution<int> uni(0, 2);

    vector<int> customersToRemove = d_perturbationOperators[uni(d_env->d_rng)](solution, q);

    reinsert(solution, customersToRemove);

}