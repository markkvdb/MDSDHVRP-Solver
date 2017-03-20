//
// Created by Mark van der Broek on 06/03/2017.
//

#include "solver.ih"

void Solver::print()
{
    d_env->d_log << "Objective after first phase: \t\t" << d_objectiveAfterFirst << '\n';
    d_env->d_log << "Objective after second phase: \t\t" << d_env->d_bestFeasibleSolution.totalCost() << '\n';
    d_env->d_log << '\n';
    d_env->d_log << "Number of iterations first phase: \t" << d_iter1 << '\n';
    d_env->d_log << "Number of iterations second phase: \t" << d_iter2 << '\n';
    d_env->d_log << "Elapsed seconds first phase: \t\t" << d_elapsedSeconds1 << '\n';
    d_env->d_log << "Elapsed seconds second phase: \t\t" << d_elapsedSeconds2 << '\n';
    d_env->d_log << "Number of local search routines: \t" << d_localIter << '\n';
    d_env->d_log << '\n';
    d_env->d_log << "Average gain of operator: \n";
    for (int operatorIdx = 0; operatorIdx != d_localSearchOperators.size(); ++operatorIdx)
    {
        if (d_localSearchImprovements[operatorIdx].size() == 0)
        {
            d_env->d_log << "\t " << operatorIdx << ": None\n";
            continue;
        }
        d_env->d_log << "\t " << operatorIdx << ": "
             << accumulate(begin(d_localSearchImprovements[operatorIdx]), end(d_localSearchImprovements[operatorIdx]), 0)
                / d_localSearchImprovements[operatorIdx].size() << "\t("
             << setprecision(2) << fixed << static_cast<double>(d_localSearchImprovements[operatorIdx].size()) * 100
                / d_localSearchTimes[operatorIdx].size() << "%) \n";
    }
    d_env->d_log << '\n';
    d_env->d_log << "Average time of operator: \n";
    for (int operatorIdx = 0; operatorIdx != d_localSearchOperators.size(); ++operatorIdx)
    {
        d_env->d_log << "\t " << operatorIdx << ": "
             << accumulate(begin(d_localSearchTimes[operatorIdx]), end(d_localSearchTimes[operatorIdx]), 0)
                / d_localSearchTimes[operatorIdx].size() << " \u00B5s \n";
    }
    d_env->d_log << '\n';
    d_env->d_log << "Number of splits after initial solution: \t" << setprecision(5) << fixed << d_ratioSplitsAfterInitial << '\n';
    d_env->d_log << "Number of splits after first phase: \t\t" << d_ratioSplitsAfterFirst << '\n';
    d_env->d_log << "Number of splits after second phase: \t\t" << d_ratioSplitsAfterSecond << '\n';
}
