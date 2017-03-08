//
// Created by Mark van der Broek on 27/02/2017.
//

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
//    init.show();

    // Create environment with all the data
    Env env{init};
    // Create empty solution
    Solver solver{&env};

    // Construct initial solution
    solver.initialSolution();

    env.d_currentSolution.print();
    env.d_bestSolution.print();

}