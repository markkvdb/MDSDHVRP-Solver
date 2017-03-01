//
// Created by Mark van der Broek on 01/03/2017.
//

#include "init.ih"

double Init::distance(double x1, double y1, double x2, double y2)
{
    // Euclidean distance
    return sqrt(pow(x1 - x2, 2) + pow(y1-y2, 2));
}
