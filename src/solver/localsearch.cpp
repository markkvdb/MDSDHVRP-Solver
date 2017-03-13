//
// Created by Mark van der Broek on 10/03/2017.
//

#include "solver.ih"

void Solver::localSearch(Solution &s)
{
    cout << s.totalCost() << ' ';
    oneInsertionIntraRoute(s);
    twoOptIntraRoute(s);
    swap(s);
    oneInsertionInterRoute(s);
    twoInsertionIntraRoute(s);
    cout << s.totalCost() << '\n';
//    for (size_t operatorIdx = 0; operatorIdx != d_localSearchOperators.size(); ++operatorIdx) {
//
//        double oldTotalCost = s.totalCost();
//        //d_localSearchOperators[operatorIdx](s);
//
//        if (s.totalCost() < oldTotalCost)
//            operatorIdx = 0;
//    }
}