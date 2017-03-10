//
// Created by Mark van der Broek on 10/03/2017.
//

#include "env.ih"

void Env::updatePenalty(Solution &solution)
{
    if (solution.feasible())
        d_penalty = max(d_penalty / d_delta, d_penaltyLower);
    else
        d_penalty = min(d_penalty * d_delta, d_penaltyUpper);
}