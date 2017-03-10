//
// Created by Mark van der Broek on 10/03/2017.
//

#include "solver.ih"

int Solver::selectq()
{
    int minimum = min(5, static_cast<int>(d_env->d_currentSolution.getCustomers().size()));
    return max(minimum, static_cast<int>(floor(0.10 * d_env->d_currentSolution.getCustomers().size())));
}