//
// Created by Mark van der Broek on 09/03/2017.
//

/**
 * @brief General algorithm. Select this function to run the algorithm.
 */

#include "solver.ih"

void Solver::run()
{
    auto start = chrono::system_clock::now();
    d_elapsedSeconds1 = 0;
    double gamma = 0.05;


    initialSolution();
    d_env->d_bestSolution = d_env->d_currentSolution;
    d_env->d_bestFeasibleSolution = d_env->d_currentSolution;
    d_env->d_temp = 0.005 * d_env->d_currentSolution.cost();
    d_ratioSplitsAfterInitial = d_env->d_bestFeasibleSolution.ratioSplits();

    // Set q and the iter counter
    int q = selectq(0.05);
    d_iter1 = 0;
    d_iter2 = 0;
    d_localIter = 0;


    while (d_iter1 != d_maxIter1 && d_elapsedSeconds1 < d_maxSeconds1)
    {
        d_env->d_newSolution = d_env->d_currentSolution;
        perturbation(d_env->d_newSolution, q, true, 3, 2, 1);

        if (d_env->d_newSolution.totalCost() < d_env->d_bestSolution.totalCost())
            d_env->d_bestSolution = d_env->d_newSolution;

        if (d_env->d_newSolution.feasible() && d_env->d_newSolution.totalCost() < d_env->d_bestFeasibleSolution.totalCost())
            d_env->d_bestFeasibleSolution = d_env->d_newSolution;

        d_env->d_currentSolution = simulatedAnnealing(d_env->d_newSolution, d_env->d_currentSolution);
        d_env->updatePenalty(d_env->d_currentSolution);

        if (d_env->d_currentSolution.totalCost() > (1 + gamma) * d_env->d_bestFeasibleSolution.totalCost())
            d_env->d_currentSolution = d_env->d_bestFeasibleSolution;

        ++d_iter1;
        d_elapsedSeconds1 = chrono::duration<double>(chrono::system_clock::now() - start).count();
    }
    d_objectiveAfterFirst = d_env->d_bestFeasibleSolution.totalCost();
    d_ratioSplitsAfterFirst = d_env->d_bestFeasibleSolution.ratioSplits();

    q = selectq(0.10);
    start = chrono::system_clock::now();
    d_elapsedSeconds2 = 0;

    while (d_iter2 != d_maxIter2 && d_elapsedSeconds2 < d_maxSeconds2)
    {
        d_env->d_newSolution = d_env->d_currentSolution;
        perturbation(d_env->d_newSolution, q, true, 3, 2, 1);

        if (d_env->d_newSolution.totalCost() < (1 + d_theta) * d_env->d_bestSolution.totalCost())
        {
            localSearch(d_env->d_newSolution);
            d_localIter++;
        }

        if (d_env->d_newSolution.totalCost() < d_env->d_bestSolution.totalCost())
            d_env->d_bestSolution = d_env->d_newSolution;

        if (d_env->d_newSolution.feasible() && d_env->d_newSolution.cost() < d_env->d_bestFeasibleSolution.cost())
            d_env->d_bestFeasibleSolution = d_env->d_newSolution;

        d_env->d_currentSolution = simulatedAnnealing(d_env->d_newSolution, d_env->d_currentSolution);
        d_env->updatePenalty(d_env->d_currentSolution);

        if (d_env->d_currentSolution.totalCost() > (1 + gamma) * d_env->d_bestFeasibleSolution.totalCost())
            d_env->d_currentSolution = d_env->d_bestFeasibleSolution;

        ++d_iter2;
        d_elapsedSeconds2 = chrono::duration<double>(chrono::system_clock::now() - start).count();
    }
    d_ratioSplitsAfterSecond = d_env->d_bestFeasibleSolution.ratioSplits();

    if (d_env->d_bestFeasibleSolution.feasible())
        d_env->d_bestFeasibleSolution.print();
}