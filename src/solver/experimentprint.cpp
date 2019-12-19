//
// Created by Mark van der Broek on 30/03/2017.
//

#include "solver.ih"

void Solver::experimentPrint()
{
    cout << d_objectiveAfterFirst << "\r\n";
    cout << d_env->d_bestFeasibleSolution.totalCost() << "\r\n";
    cout << d_feasibleIter << "\r\n";
    cout << d_iter1 << "\r\n";
    cout << d_iter2 << "\r\n";

    for (int operatorIdx = 0; operatorIdx != d_perturbationOperators.size(); ++operatorIdx)
    {
        if (d_perturbationImprovements[operatorIdx].size() == 0)
        {
            cout << "None ";
            continue;
        }
        cout << accumulate(begin(d_perturbationImprovements[operatorIdx]), end(d_perturbationImprovements[operatorIdx]), 0.0)
                / d_perturbationImprovements[operatorIdx].size() << ' ';
    }
    cout << "\r\n";
    for (int operatorIdx = 0; operatorIdx != d_perturbationOperators.size(); ++operatorIdx)
    {
        if (d_perturbationTimes[operatorIdx].size() == 0)
        {
            cout << "None ";
            continue;
        }
        cout << accumulate(begin(d_perturbationTimes[operatorIdx]), end(d_perturbationTimes[operatorIdx]), 0.0)
                / d_perturbationTimes[operatorIdx].size() << ' ';
    }
    cout << "\r\n";

    for (int operatorIdx = 0; operatorIdx != d_localSearchOperators.size(); ++operatorIdx)
    {
        if (d_localSearchImprovements[operatorIdx].size() == 0)
        {
            cout << "None ";
            continue;
        }
        cout << accumulate(begin(d_localSearchImprovements[operatorIdx]), end(d_localSearchImprovements[operatorIdx]), 0.0)
                        / d_localSearchImprovements[operatorIdx].size() << ' ';
    }
    cout << "\r\n";
    for (int operatorIdx = 0; operatorIdx != d_localSearchOperators.size(); ++operatorIdx)
    {
        if (d_localSearchTimes[operatorIdx].size() == 0)
        {
            cout << "None ";
            continue;
        }
        cout << accumulate(begin(d_localSearchTimes[operatorIdx]), end(d_localSearchTimes[operatorIdx]), 0.0)
                        / d_localSearchTimes[operatorIdx].size() << ' ';
    }
    cout << "\r\n";
    cout << setprecision(5) << fixed << d_ratioSplitsAfterInitial << "\r\n";
    cout << d_ratioSplitsAfterFirst << "\r\n";
    cout << d_ratioSplitsAfterSecond << "\r\n";
}