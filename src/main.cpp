//
// Created by Mark van der Broek on 27/02/2017.
//

#include <env.h>
#include "main.h"

int main(int argc, char* argv[])
{
    // LOAD DATA
    if (argc != 4)
    {
        cerr << "Usage: " << argv[0] << " <FILENAME> <R> <PERCTEMP>\n";
        return 1;
    }

    std::string fileName{argv[1]};
    Init init{fileName};
    init.setup();

    // Create environment with all the data
    double r = atof(argv[2]);
    double percTemp = atof(argv[2]);
    Env env{init, r, percTemp};

    // Create empty solution
    Solver solver{&env};

    // Construct initial solution
    solver.run();

    solver.print();
}