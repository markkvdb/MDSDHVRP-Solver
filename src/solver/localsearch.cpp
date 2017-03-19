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
    for (int operatorIdx = 0; operatorIdx != d_localSearchOperators.size(); ++operatorIdx) {

        double oldTotalCost = s.totalCost();
        d_localSearchOperators[operatorIdx](s);


        double newCost = s.totalCost();

        if (newCost > oldTotalCost) {
            cout << "Local search deteriorated the solution, operatorIdx: " << operatorIdx << "\n";
            cout << "Old: " << oldTotalCost << " new: " << newCost << "\n";
        }

        if (newCost < oldTotalCost) {
            operatorIdx = -1;

        }

    }
}