//
// Created by Mark van der Broek on 03/03/2017.
//

#ifndef ORACS_ENV_H
#define ORACS_ENV_H

#include <vector>
#include "depot.h"
#include "customer.h"
#include "solution.h"
#include "init.h"
#include <random>
#include <fstream>

/**
 * Env is a class that holds all the global data for the algorithm.
 *
 */
class Env {

    typedef std::vector<std::vector<double>> DoubleMatrix;

public:
    Solution                    d_bestSolution; /*!< The best (infeasible) solution */
    Solution                    d_currentSolution; /*!< The current solution  */
    Solution                    d_newSolution; /*!< The new solution */
    Solution                    d_bestFeasibleSolution; /*!< The best feasible solution */

    std::vector<double>         d_distanceMatrix; /*!< Distance matrix for all instances */
    std::size_t                 d_numberOfEntities;

    std::default_random_engine  d_rng; /*!< Random number engine */
    std::ofstream               d_output; /*!< Output file */
    std::ofstream               d_log; /*!< Log file */
    double                      d_eps; /*!< Rounding error */

    double                      d_delta; /*!< Parameter to multiply the penalty with */
    double                      d_penalty; /*!< Parameter for determining the penalty cost */
    double                      d_penaltyUpper; /*!< Upper bound of the d_penalty parameter */
    double                      d_penaltyLower; /*!< Lower bound of the d_penalty parameter */

    double                      d_temp; /*!< Temperature used for simulated annealing */
    double                      d_r; /*!< Parameter of the simulated annealing */
    double                      d_tempMin; /*!< Minimum temperature of the simulated annealing */

    Env();
    Env(Init &init);

    void updatePenalty(Solution &solution);
    double distanceMatrix(int entity1, int entity2);
};

inline double Env::distanceMatrix(int entity1, int entity2)
{
    return d_distanceMatrix[entity1 * d_numberOfEntities + entity2];
}

#endif //ORACS_ENV_H
