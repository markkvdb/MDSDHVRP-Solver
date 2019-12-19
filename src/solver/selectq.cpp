//
// Created by Mark van der Broek on 10/03/2017.
//

/**
 * @brief Select the number of customers to be perturbed in the perturbation phase.
 *
 * @return Number of customers to be perturbed
 */

#include "solver.ih"

int Solver::selectq(double perc)
{
    int minimum = min(15, static_cast<int>(d_env->d_currentSolution.getCustomers().size()));
    return max(minimum, static_cast<int>(floor(perc * d_env->d_currentSolution.getCustomers().size())));
}