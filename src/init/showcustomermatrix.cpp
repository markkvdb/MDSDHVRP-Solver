//
// Created by Mark van der Broek on 01/03/2017.
//

/**
 * @brief Show the customer matrix.
 */

#include "init.ih"

void Init::showCustomerMatrix()
{
    cout << "Customer list: \n";
    showMatrix(d_customerMatrix);
    cout << '\n';
}