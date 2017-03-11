//
// Created by Mark van der Broek on 09/03/2017.
//

#include "solver.ih"

void Solver::run()
{
    size_t maxIter  = 10000;
    double theta    = 0.3;
    // TODO add time restrictions on runtime

    initialSolution();
    d_env->d_bestSolution = d_env->d_currentSolution;

    // Set q and the iter counter
    int q = selectq();
    size_t iter = 0;

    if (d_env->d_currentSolution.feasible())
        d_env->d_bestFeasibleSolution = d_env->d_currentSolution;

    while (iter != maxIter)
    {
        d_env->d_newSolution = d_env->d_currentSolution;
        perturbation(d_env->d_newSolution, q);

        if (d_env->d_newSolution.totalCost() < (1 + theta) * d_env->d_bestSolution.totalCost())
            localSearch(d_env->d_newSolution);

        if (d_env->d_newSolution.totalCost() < d_env->d_bestSolution.totalCost())
        {
            d_env->d_bestSolution = d_env->d_newSolution;

            if (d_env->d_newSolution.feasible())
                d_env->d_bestFeasibleSolution = d_env->d_newSolution;
        }

        d_env->d_newSolution = simulatedAnnealing(d_env->d_newSolution, d_env->d_currentSolution);
        d_env->updatePenalty(d_env->d_currentSolution);
        ++iter;
    }

    d_env->d_bestFeasibleSolution.print();
}