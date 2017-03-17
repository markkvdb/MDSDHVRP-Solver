//
// Created by Mark van der Broek on 27/02/2017.
//

/**
 * @brief Print the solution in the required output format.
 */

#include "solution.ih"

using namespace std;

void Solution::print()
{
    cout << setprecision(2) << fixed << totalCost() << "\r\n\r\n";

    for (Depot const &depot: d_depots)
    {
        cout << depot;
    }
}
