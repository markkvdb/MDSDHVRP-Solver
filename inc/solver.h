//
// Created by Mark van der Broek on 03/03/2017.
//

#ifndef ORACS_SOLVER_H
#define ORACS_SOLVER_H

#include "solution.h"

class Env;

class Solver {

    Env *d_env;


public:
    Solver() = delete;
    Solver(Env *env);

    void initialSolution();

private:
    std::vector<std::vector<int>> allocateCustomers();
    std::vector<int> getClosestDepots(int customer);

};


#endif //ORACS_SOLVER_H
