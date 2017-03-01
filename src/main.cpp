//
// Created by Mark van der Broek on 27/02/2017.
//

#include "main.h"

int Vehicle::noOfVehicles = 0;

int main()
{
    // Create empty solution
    Solution solution{};

    // LOAD DATA
    std::string fileName = "/Users/markvanderbroek/CLionProjects/ORACS/src/data/instanceA_1_input.txt";
    Init init{fileName};
    init.show();

    int numberOfDepots = 2;
    int numberOfDifVehicles = 5;
    int numberOfCustomers = 10;

    for (int depot = 0; depot != numberOfDepots; ++depot)
    {
        Depot depotToAdd{100};
        solution.addDepot(depotToAdd);


    }

}