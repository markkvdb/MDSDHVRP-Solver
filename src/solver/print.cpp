//
// Created by Mark van der Broek on 06/03/2017.
//

#include "solver.ih"

void Solver::print()
{
    cout << "Objective after first phase: \t\t" << d_objectiveAfterFirst << '\n';
    cout << "Objective after second phase: \t\t" << d_env->d_bestFeasibleSolution.totalCost() << '\n';
    cout << '\n';
    cout << "Number of iterations first phase: \t" << d_iter1 << '\n';
    cout << "Number of iterations second phase: \t" << d_iter2 << '\n';
    cout << "Elapsed seconds first phase: \t\t" << d_elapsedSeconds1 << '\n';
    cout << "Elapsed seconds second phase: \t\t" << d_elapsedSeconds2 << '\n';
    cout << "Number of local search routines: \t" << d_localIter << '\n';
    cout << '\n';
    cout << "Average gain of operator: \n";
    for (int operatorIdx = 0; operatorIdx != d_localSearchOperators.size(); ++operatorIdx)
    {
        if (d_localSearchImprovements[operatorIdx].size() == 0)
        {
            cout << "\t " << operatorIdx << ": None\n";
            continue;
        }
        cout << "\t " << operatorIdx << ": "
             << accumulate(begin(d_localSearchImprovements[operatorIdx]), end(d_localSearchImprovements[operatorIdx]), 0)
                / d_localSearchImprovements[operatorIdx].size() << "\t("
             << setprecision(2) << fixed << static_cast<double>(d_localSearchImprovements[operatorIdx].size()) * 100
                / d_localSearchTimes[operatorIdx].size() << "%) \n";
    }
    cout << '\n';
    cout << "Average time of operator: \n";
    for (int operatorIdx = 0; operatorIdx != d_localSearchOperators.size(); ++operatorIdx)
    {
        cout << "\t " << operatorIdx << ": "
             << accumulate(begin(d_localSearchTimes[operatorIdx]), end(d_localSearchTimes[operatorIdx]), 0)
                / d_localSearchTimes[operatorIdx].size() << " \u00B5s \n";
    }
    cout << '\n';
    cout << "Number of splits after initial solution: \t" << setprecision(5) << fixed << d_ratioSplitsAfterInitial << '\n';
    cout << "Number of splits after first phase: \t\t" << d_ratioSplitsAfterFirst << '\n';
    cout << "Number of splits after second phase: \t\t" << d_ratioSplitsAfterSecond << '\n';
}
