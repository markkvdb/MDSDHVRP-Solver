//
// Created by Mark van der Broek on 27/02/2017.
//

#include "solution.h"

using namespace std;

void Solution::print()
{
    cout << totalCost() << "\n\n";

    for (Depot const &depot: d_depots)
    {
        cout << depot;
    }
}
