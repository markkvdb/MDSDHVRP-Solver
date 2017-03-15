//
// Created by Mark van der Broek on 03/03/2017.
//

#include "solver.ih"

Solver::Solver(Env *env)
:
    d_env(env)
{
    // Add all local search operators
    d_localSearchOperators.push_back(std::bind(&Solver::oneInsertionIntraRoute, this, std::placeholders::_1));
    d_localSearchOperators.push_back(std::bind(&Solver::twoOptIntraRoute, this, std::placeholders::_1));
    d_localSearchOperators.push_back(std::bind(&Solver::swap, this, std::placeholders::_1));
    d_localSearchOperators.push_back(std::bind(&Solver::oneInsertionInterRoute, this, std::placeholders::_1));
    d_localSearchOperators.push_back(std::bind(&Solver::twoInsertionIntraRoute, this, std::placeholders::_1));
    d_localSearchOperators.push_back(std::bind(&Solver::swapStar, this, std::placeholders::_1));
}
