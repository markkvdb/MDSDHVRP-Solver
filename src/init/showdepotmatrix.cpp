//
// Created by Mark van der Broek on 01/03/2017.
//

/**
 * @brief Show the depot matrix.
 */

#include "init.ih"

void Init::showDepotMatrix()
{
    cout << "Depot list: \n";
    showMatrix(d_depotMatrix);
    cout << '\n';
}