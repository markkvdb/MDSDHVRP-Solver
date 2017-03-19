//
// Created by Mark van der Broek on 09/03/2017.
//

/**
 * @brief General algorithm. Select this function to run the algorithm.
 */

#include "solver.ih"

void Solver::run()
{
    size_t maxIter1 = 1000000000;
    size_t maxIter2 = 1000000000;
    double secondsToRun1 = 300;
    double secondsToRun2 = 300;
    double theta = 0.01;
    auto start = chrono::system_clock::now();
    double elapsedSeconds = 0;


    initialSolution();
    d_env->d_bestSolution = d_env->d_currentSolution;
    d_env->d_bestFeasibleSolution = d_env->d_currentSolution;
    d_env->d_temp = 0.01*d_env->d_currentSolution.cost();
    // Set q and the iter counter
    int q = selectq(0.05);

    size_t iter1 = 0;
    size_t iter2 = 0;
    size_t localIter = 0;


    while (iter1 != maxIter1 && elapsedSeconds < secondsToRun1)
    {
        d_env->d_newSolution = d_env->d_currentSolution;
        perturbation(d_env->d_newSolution, q, true, 1, 1, 0);

        if (d_env->d_newSolution.totalCost() < d_env->d_bestSolution.totalCost())
            d_env->d_bestSolution = d_env->d_newSolution;

        if (d_env->d_newSolution.feasible() && d_env->d_newSolution.totalCost() < d_env->d_bestFeasibleSolution.totalCost())
            d_env->d_bestFeasibleSolution = d_env->d_newSolution;



        d_env->d_currentSolution = simulatedAnnealing(d_env->d_newSolution, d_env->d_currentSolution);
        d_env->updatePenalty(d_env->d_currentSolution);
        ++iter1;
        elapsedSeconds = chrono::duration<double>(chrono::system_clock::now() - start).count();
    }



    if (d_env->d_bestFeasibleSolution.feasible())
        d_env->d_bestFeasibleSolution.print();

    q = selectq(0.10);
    start = chrono::system_clock::now();
    elapsedSeconds = 0;

    while (iter2 != maxIter2 && elapsedSeconds < secondsToRun2)
    {
        d_env->d_newSolution = d_env->d_currentSolution;
        perturbation(d_env->d_newSolution, q, true, 3, 2, 1);

        if (d_env->d_newSolution.totalCost() < (1 + theta) * d_env->d_bestSolution.totalCost())
        {
            localSearch(d_env->d_newSolution);
            localIter++;
        }

        if (d_env->d_newSolution.totalCost() < d_env->d_bestSolution.totalCost())
            d_env->d_bestSolution = d_env->d_newSolution;

        if (d_env->d_newSolution.feasible() && d_env->d_newSolution.totalCost() < d_env->d_bestFeasibleSolution.totalCost())
            d_env->d_bestFeasibleSolution = d_env->d_newSolution;

        d_env->d_currentSolution = simulatedAnnealing(d_env->d_newSolution, d_env->d_currentSolution);
        d_env->updatePenalty(d_env->d_currentSolution);
        ++iter2;
        elapsedSeconds = chrono::duration<double>(chrono::system_clock::now() - start).count();
    }

    if (d_env->d_bestFeasibleSolution.feasible())
        d_env->d_bestFeasibleSolution.print();

    cout << "iter1: " << iter1 << " iter2: " << iter2 << " localIter: "<< localIter;
}