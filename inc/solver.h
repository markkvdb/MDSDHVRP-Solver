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
    std::vector<std::vector<int>>   allocateCustomers();
    std::vector<int>                getClosestDepots(int customer);
    std::vector<int>                sortVehicleList(int depotNumber);
    void                            assignRouteToVehicle(int vehicleNumber, int depotNumber,
                                                         std::vector<int> &depotCustomerAllocation);
    void                            addCustomer(int pickedCustomer, double &remainingCapacity,
                                                std::vector<int> &customerList, std::vector<double> &customerDropOff,
                                                std::vector<int> &depotCustomerAllocation);
    void                            getClosestCustomer(int &pickedCustomer, std::vector<int> &depotCustomerAllocation);

};


#endif //ORACS_SOLVER_H
