//
// Created by Mark van der Broek on 01/03/2017.
//

/**
 * @brief Output the matrix given as an argument. Write it to std::cout.
 *
 * @param [in] matrix   Matrix to output
 */

#include "../../inc/init.h"

using namespace std;

void Init::showMatrix(std::vector<std::vector<double>> matrix)
{
    for (int row = 0; row != matrix.size(); ++row)
    {
        for (int col = 0; col != matrix[row].size(); ++col)
        {
            cout << matrix[row][col] << '\t';
        }
        cout << '\n';
    }
}