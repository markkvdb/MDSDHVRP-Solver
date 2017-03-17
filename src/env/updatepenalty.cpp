//
// Created by Mark van der Broek on 10/03/2017.
//

/**
 * @brief Update the penalty parameter between the minimum d_penaltyLower and the maximum d_penaltyUpper
 *
 * @param [in] solution Solution to check whether this is feasible or not
 */

#include "env.ih"

void Env::updatePenalty(Solution &solution)
{
    if (solution.feasible())
        d_penalty = max(d_penalty / d_delta, d_penaltyLower);
    else
        d_penalty = min(d_penalty * d_delta, d_penaltyUpper);
}