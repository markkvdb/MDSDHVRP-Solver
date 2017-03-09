//
// Created by Mark van der Broek on 09/03/2017.
//

#include "solver.ih"

void Solver::run()
{
    initialSolution();

    // perturbation(d_env->d_currentSolution);

    d_env->d_bestSolution.print();
}