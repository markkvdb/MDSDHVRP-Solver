//
// Created by Mark van der Broek on 06/03/2017.
//

#include "solver.ih"

void Solver::print()
{
    d_env->d_log << "Objective after first phase: \t\t" << d_objectiveAfterFirst << "\r\n";
    d_env->d_log << "Objective after second phase: \t\t" << d_env->d_bestFeasibleSolution.totalCost() << "\r\n";
    d_env->d_log << "\r\n";
    d_env->d_log << "Number of iterations first phase: \t" << d_iter1 << "\r\n";
    d_env->d_log << "Number of iterations second phase: \t" << d_iter2 << "\r\n";
    d_env->d_log << "Elapsed seconds first phase: \t\t" << d_elapsedSeconds1 << "\r\n";
    d_env->d_log << "Elapsed seconds second phase: \t\t" << d_elapsedSeconds2 << "\r\n";
    d_env->d_log << "Number of local search routines: \t" << d_localIter << "\r\n";
    d_env->d_log << "\r\n";
    d_env->d_log << "Average gain of operator: \r\n";
    for (int operatorIdx = 0; operatorIdx != d_localSearchOperators.size(); ++operatorIdx)
    {
        if (d_localSearchImprovements[operatorIdx].size() == 0)
        {
            d_env->d_log << "\t " << operatorIdx << ": None\r\n";
            continue;
        }
        d_env->d_log << "\t " << operatorIdx << ": "
             << accumulate(begin(d_localSearchImprovements[operatorIdx]), end(d_localSearchImprovements[operatorIdx]), 0.0)
                / d_localSearchImprovements[operatorIdx].size() << "\t("
             << setprecision(2) << fixed << static_cast<double>(d_localSearchImprovements[operatorIdx].size()) * 100
                / d_localSearchTimes[operatorIdx].size() << "%) \r\n";
    }
    d_env->d_log << "\r\n";
    d_env->d_log << "Average time of operator: \r\n";
    for (int operatorIdx = 0; operatorIdx != d_localSearchOperators.size(); ++operatorIdx)
    {
        if (d_localSearchTimes[operatorIdx].size() == 0)
        {
            d_env->d_log << "\t " << operatorIdx << ": None \r\n";
            continue;
        }
        d_env->d_log << "\t " << operatorIdx << ": "
             << accumulate(begin(d_localSearchTimes[operatorIdx]), end(d_localSearchTimes[operatorIdx]), 0.0)
                / d_localSearchTimes[operatorIdx].size() << " \u00B5s \r\n";
    }
    d_env->d_log << "\r\n";
    d_env->d_log << "Number of splits after initial solution: \t" << setprecision(5) << fixed << d_ratioSplitsAfterInitial << "\r\n";
    d_env->d_log << "Number of splits after first phase: \t\t" << d_ratioSplitsAfterFirst << "\r\n";
    d_env->d_log << "Number of splits after second phase: \t\t" << d_ratioSplitsAfterSecond << "\r\n";
}
