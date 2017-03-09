//
// Created by Mark van der Broek on 09/03/2017.
//

#include "solver.ih"

void Solver::run()
{
    initialSolution();

    d_env->d_currentSolution.print();
    // Perturbation
    int q = 7;
    perturbation(d_env->d_currentSolution, q);

    d_env->d_currentSolution.print();
}