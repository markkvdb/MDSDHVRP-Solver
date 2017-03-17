//
// Created by Mark van der Broek on 01/03/2017.
//

/**
 * @brief Show the vehicle matrix.
 */

#include "init.ih"

void Init::showVehicleMatrix()
{
    cout << "Vehicle type list: \n";
    showMatrix(d_vehicleMatrix);
    cout << '\n';
}