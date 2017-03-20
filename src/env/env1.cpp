//
// Created by Mark van der Broek on 03/03/2017.
//

/**
 * @brief Constructor
 *
 * @param [in] init Init instance with all the data stored for the problem
 */

#include "env.ih"

Env::Env(Init &init)
        :
        d_distanceMatrix(init.getDistanceMatrix()),
        d_bestSolution(Solution{this}),
        d_currentSolution(Solution{this}),
        d_newSolution(Solution{this}),
        d_bestFeasibleSolution(Solution{this}),
        d_rng(0),
        d_delta(1.1),
        d_penalty(100),
        d_penaltyLower(100),
        d_penaltyUpper(100000),
        d_temp(0),
        d_r(0.95),
        d_tempMin(0),
        d_output(init.getOutputFile()),
        d_log(init.getLogFile())
{
    vector<vector<double>> depotMatrix      (init.getDepotMatrix());
    vector<vector<double>> vehicleMatrix    (init.getVehicleMatrix());
    vector<vector<double>> customerMatrix   (init.getCustomerMatrix());

    int vehicleIdx = 0;
    for (int depot = 0; depot != init.getNoOfDepots(); ++depot)
    {
        int vehicleIdxPos = 0;
        Depot depotToAdd{this, depot, static_cast<int>(depotMatrix[depot][3])};

        // Add vehicles to depot.
        for (int vehicleType = 4; vehicleType != depotMatrix[depot].size(); ++vehicleType)
        {
            for (int noOfVehicles = 0; noOfVehicles != depotMatrix[depot][vehicleType]; ++noOfVehicles)
            {
                depotToAdd.addVehicle(Vehicle{this,
                                              vehicleIdx,
                                              vehicleIdxPos,
                                              static_cast<int>(vehicleMatrix[vehicleType-4][0]),
                                              depot,
                                              static_cast<int>(vehicleMatrix[vehicleType-4][1]),
                                              vehicleMatrix[vehicleType-4][2],
                                              vehicleMatrix[vehicleType-4][3],
                                              vehicleMatrix[vehicleType-4][4]});
                ++vehicleIdx;
                ++vehicleIdxPos;
            }
        }
        d_currentSolution.addDepot(depotToAdd);
    }

    for (int customer = 0; customer != init.getNoOfCustomers(); ++customer)
    {
        Customer customerToAdd{this, customer, static_cast<int>(customerMatrix[customer][3]),
                               customerMatrix[customer][4]};
        d_currentSolution.addCustomer(customerToAdd);
    }


}