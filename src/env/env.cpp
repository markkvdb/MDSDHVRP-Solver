//
// Created by Mark van der Broek on 03/03/2017.
//

#include "env.h"

Env::Env()
:
        d_bestSolution(Solution{this}),
        d_currentSolution(Solution{this}),
        d_newSolution(Solution{this})
{}
