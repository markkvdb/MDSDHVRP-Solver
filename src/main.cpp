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
    init.show();

    // Create empty solution
    Solution solution{init};

    // Construct initial solution
    solution.initialSolution();

}