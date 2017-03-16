//
// Created by Mark van der Broek on 10/03/2017.
//

#include "solver.ih"

void Solver::localSearch(Solution &s)
{
    for (int operatorIdx = 0; operatorIdx != d_localSearchOperators.size(); ++operatorIdx) {

        double oldTotalCost = s.totalCost();
        d_localSearchOperators[operatorIdx](s);

        double newCost = s.totalCost();
        if (newCost < oldTotalCost)
            operatorIdx = -1;
    }
}