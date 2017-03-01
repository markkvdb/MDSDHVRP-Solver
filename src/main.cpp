//
// Created by Mark van der Broek on 27/02/2017.
//

#include "main.h"

int main()
{
    // LOAD DATA
    std::string fileName = "/Users/markvanderbroek/CLionProjects/ORACS/src/data/instanceA_10_input.txt";
    Init init{fileName};
    init.show();

    // Create empty solution
    Solution solution{init};

    // Construct initial solution
    solution.initialSolution();

}