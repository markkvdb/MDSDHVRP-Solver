//
// Created by Mark van der Broek on 27/02/2017.
//

#include <env.h>
#include "main.h"

int main(int argc, char* argv[])
{
    // LOAD DATA
    if (argc != 2)
    {
        cerr << "Usage: " << argv[0] << " <FILENAME>\n";
        return 1;
    }

    std::string fileName{argv[1]};
    Init init{fileName};
    init.setup();

    // Create environment with all the data
    Env env{init};

    // Create empty solution
    Solver solver{&env};
    solver.run();
    solver.print();
}