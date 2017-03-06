//
// Created by Mark van der Broek on 06/03/2017.
//

#include "solver.ih"

void Solver::print()
{
    cout << totalCost() << "\n\n";

    for (Depot const &depot: d_env->d_depots)
    {
        cout << depot;
    }
//
//    for (Customer const &customer: d_env->d_customers)
//    {
//        cout << customer;
//    }
}
