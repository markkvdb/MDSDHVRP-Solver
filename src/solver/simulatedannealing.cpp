//
// Created by Mark van der Broek on 10/03/2017.
//

#include "solver.ih"

Solution &Solver::simulatedAnnealing(Solution &sPrime, Solution &s)
{
    if (sPrime.totalCost() <= s.totalCost())
    {
        return sPrime;
    }
    else
    {
        double diff = sPrime.totalCost() - s.totalCost();
        uniform_real_distribution<double> uni(0.0, 1.0);

        double U(uni(d_env->d_rng));
        if (U < exp(-diff/d_env->d_temp))
        {
            d_env->d_temp = max(d_env->d_temp * d_env->d_r, d_env->d_tempMin);
            return sPrime;
        }
        else
        {
            return s;
        }
    }
}