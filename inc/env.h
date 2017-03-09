//
// Created by Mark van der Broek on 03/03/2017.
//

#ifndef ORACS_ENV_H
#define ORACS_ENV_H

#include <vector>
#include "depot.h"
#include "customer.h"
#include "solution.h"
#include "init.h"

class Env {

    typedef std::vector<std::vector<double>> DoubleMatrix;

public:
    Solution                d_bestSolution;
    Solution                d_currentSolution;
    Solution                d_newSolution;
    DoubleMatrix            d_distanceMatrix;

    Env();
    Env(Init &init);

};

#endif //ORACS_ENV_H
