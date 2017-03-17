//
// Created by Mark van der Broek on 01/03/2017.
//

/**
 * @brief Return distance of two (x,y) coordinates.
 *
 * @param [in] x1   x coordinate of the first point
 * @param [in] y1   y coordinate of the first point
 * @param [in] x2   x coordinate of the second point
 * @param [in] y2   y coordinate of the second point
 *
 * @return The distance between the two points
 */

#include "init.ih"

double Init::distance(double x1, double y1, double x2, double y2)
{
    // Euclidean distance
    return sqrt(pow(x1 - x2, 2) + pow(y1-y2, 2));
}
