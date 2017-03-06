//
// Created by Mark van der Broek on 06/03/2017.
//

#include "solver.ih"

void Solver::print()
{
    for (Depot const& depot: d_env->d_depots)
    {
        cout << depot;
    }
}
