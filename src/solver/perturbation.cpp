//
// Created by Mark van der Broek on 09/03/2017.
//

#include "solver.ih"

void Solver::perturbation(Solution &solution, int q)
{
    vector<int> customersToRemove = randomRemoval(solution, q);

    reinsert(solution, customersToRemove);
}