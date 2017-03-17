//
// Created by Mark van der Broek on 03/03/2017.
//

/**
 * @brief Constructor. Adds the perturbation and local search operators to the lists.
 *
 * @param [in] env  Environment pointer
 */

#include "solver.ih"

Solver::Solver(Env *env)
:
    d_env(env)
{
    // Add all perturbation operators
    d_perturbationOperators.push_back(std::bind(&Solver::randomRemoval, this, std::placeholders::_1,
                                                std::placeholders::_2));
    d_perturbationOperators.push_back(std::bind(&Solver::costRemoval, this, std::placeholders::_1,
                                                std::placeholders::_2));
    d_perturbationOperators.push_back(std::bind(&Solver::routeRemoval, this, std::placeholders::_1,
                                                std::placeholders::_2));


    // Add all local search operators
    d_localSearchOperators.push_back(std::bind(&Solver::oneInsertionIntraRoute, this, std::placeholders::_1));
    d_localSearchOperators.push_back(std::bind(&Solver::twoOptIntraRoute, this, std::placeholders::_1));
    d_localSearchOperators.push_back(std::bind(&Solver::swap, this, std::placeholders::_1));
    d_localSearchOperators.push_back(std::bind(&Solver::oneInsertionInterRoute, this, std::placeholders::_1));
    d_localSearchOperators.push_back(std::bind(&Solver::twoInsertionIntraRoute, this, std::placeholders::_1));
    d_localSearchOperators.push_back(std::bind(&Solver::swapStar, this, std::placeholders::_1));
    d_localSearchOperators.push_back(std::bind(&Solver::routeAddition, this, std::placeholders::_1));
}
