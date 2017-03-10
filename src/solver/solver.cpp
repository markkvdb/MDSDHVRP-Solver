//
// Created by Mark van der Broek on 03/03/2017.
//

#include "solver.ih"

Solver::Solver(Env *env)
:
    d_env(env)
{
    // Add all local search operators
    d_localSearchOperators.push_back(&Solver::oneInsertionIntraRoute);
}
