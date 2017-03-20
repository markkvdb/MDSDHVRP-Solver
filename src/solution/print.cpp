//
// Created by Mark van der Broek on 27/02/2017.
//

/**
 * @brief Print the solution in the required output format.
 */

#include <env.h>
#include "solution.ih"

using namespace std;

void Solution::print()
{
    d_env->d_output << setprecision(2) << fixed << totalCost() << "\r\n\r\n";

    for (Depot const &depot: d_depots)
    {
        d_env->d_output << depot;
    }
}
