//
// Created by Mark van der Broek on 01/03/2017.
//

/**
 * @brief Show the distance matrix.
 */

#include "init.ih"

void Init::showDistanceMatrix()
{
    cout << "Distance matrix:\n";
    showMatrix(d_distanceMatrix);
    cout << '\n';
}
