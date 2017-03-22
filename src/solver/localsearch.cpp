//
// Created by Mark van der Broek on 10/03/2017.
//

/**
 * @brief Local search mechanism for applying the local search operators.
 *
 * @param [in] s    Solution
 */

#include "solver.ih"

void Solver::localSearch(Solution &s)
{
    for (int operatorIdx = 0; operatorIdx != d_localSearchOperators.size(); ++operatorIdx)
    {
        // Start timing
        auto start = chrono::system_clock::now();
        double oldCost = s.totalCost();

        d_localSearchOperators[operatorIdx](s);

        auto end = chrono::system_clock::now();
        double newCost = s.totalCost();

        d_localSearchTimes[operatorIdx].push_back(chrono::duration_cast<chrono::microseconds>(end - start).count());

        if (newCost + d_env->d_eps < oldCost)
        {
            d_localSearchImprovements[operatorIdx].push_back(oldCost - newCost);
            operatorIdx = -1;
        }
    }
}