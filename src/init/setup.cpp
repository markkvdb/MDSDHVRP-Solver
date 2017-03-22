//
// Created by Mark van der Broek on 20/03/2017.
//

#include "init.ih"

void Init::setup()
{
    // Open file
    ifstream inputFile{d_inputFile};
    string line;

    // Read the number of vehicles types, depots, and customers.
    getline(inputFile, line);
    istringstream parameters(line);
    parameters >> d_noOfVehicleTypes;
    parameters >> d_noOfDepots;
    parameters >> d_noOfCustomers;

    // Empty line
    getline(inputFile, line);

    // Read vehicle types
    d_vehicleMatrix.resize(d_noOfVehicleTypes);

    for (int vehicles = 0; vehicles != d_noOfVehicleTypes; ++vehicles)
    {
        getline(inputFile, line);
        istringstream vehicle{line};
        int value;
        while (vehicle >> value)
            d_vehicleMatrix[vehicles].push_back(value);
    }

    //Empty line
    getline(inputFile, line);

    // Read depot information
    d_depotMatrix.resize(d_noOfDepots);

    for (int depots = 0; depots != d_noOfDepots; ++depots)
    {
        getline(inputFile, line);
        istringstream depot{line};
        double value;
        while (depot >> value)
            d_depotMatrix[depots].push_back(value);
    }

    // Empty line
    getline(inputFile, line);

    // Read customer information
    d_customerMatrix.resize(d_noOfCustomers);

    for (int customers = 0; customers != d_noOfCustomers; ++customers)
    {
        getline(inputFile, line);
        istringstream customer{line};
        double value;
        while (customer >> value)
            d_customerMatrix[customers].push_back(value);
    }

    inputFile.close();

    size_t found = d_inputFile.find("input");

    if (found == string::npos)
    {
        cerr << "input not found in input file.\n";
        return;
    }

    string tmpString = d_inputFile;
    d_outputFile = tmpString.replace(found, 5, "output");
    tmpString = d_inputFile;
    d_logFile = tmpString.replace(found, 5, "log");

    createDistanceMatrix();
}