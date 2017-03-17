//
// Created by Mark van der Broek on 03/03/2017.
//

/**
 * @brief Constructor
 */

#include "env.h"

Env::Env()
:
        d_bestSolution(Solution{this}),
        d_currentSolution(Solution{this}),
        d_newSolution(Solution{this}),
        d_bestFeasibleSolution(Solution{this}),
        d_rng(0),
        d_delta(5),
        d_penalty(5),
        d_penaltyLower(5),
        d_penaltyUpper(1000),
        d_temp(100),
        d_r(0.5),
        d_tempMin(10)
{}
