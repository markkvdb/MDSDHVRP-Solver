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

class Env {

    typedef std::vector<std::vector<double>> DoubleMatrix;

public:
    Solution                    d_bestSolution;
    Solution                    d_currentSolution;
    Solution                    d_newSolution;
    Solution                    d_bestFeasibleSolution;

    DoubleMatrix                d_distanceMatrix;

    std::default_random_engine  d_rng;

    double                      d_delta;
    double                      d_penalty;
    double                      d_penaltyUpper;
    double                      d_penaltyLower;

    double                      d_temp;
    double                      d_r;
    double                      d_tempMin;

    Env();
    Env(Init &init);

    void updatePenalty(Solution &solution);
};

#endif //ORACS_ENV_H
