//
// Created by Mark van der Broek on 01/03/2017.
//

#include "solution.ih"

Solution::Solution(Init &init)
{
    vector<vector<double>> depotMatrix      (init.getDepotMatrix());
    vector<vector<double>> vehicleMatrix    (init.getVehicleMatrix());
    vector<vector<double>> customerMatrix   (init.getCustomerMatrix());

    for (int depot = 0; depot != init.getNoOfDepots(); ++depot)
    {
        Depot depotToAdd{depotMatrix[depot][3]};
        // TODO resolve magic numbers
        // Add vehicles to depot.
        for (int vehicleType = 4; vehicleType != depotMatrix[depot].size(); ++vehicleType)
        {
            for (int noOfVehicles = 0; noOfVehicles != depotMatrix[depot][vehicleType]; ++noOfVehicles)
            {
                depotToAdd.addVehicle(Vehicle{vehicleMatrix[vehicleType-4][1],
                                              vehicleMatrix[vehicleType-4][2],
                                              vehicleMatrix[vehicleType-4][3],
                                              vehicleMatrix[vehicleType-4][4]});
            }
        }
        addDepot(depotToAdd);
    }

    for (int customer = 0; customer != init.getNoOfCustomers(); ++customer)
    {
        Customer customerToAdd{customerMatrix[customer][3], customerMatrix[customer][4]};
        addCustomer(customerToAdd);
    }
}

