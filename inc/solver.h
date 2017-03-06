//
// Created by Mark van der Broek on 03/03/2017.
//

#ifndef ORACS_SOLVER_H
#define ORACS_SOLVER_H

#include "solution.h"
#include <utility>

class Env;

class Solver {

    Env *d_env;


public:
    Solver() = delete;
    Solver(Env *env);

    void initialSolution();
    void print();

private:
    std::pair<
            std::vector<std::vector<int>>,
            std::vector<std::vector<double>>>
                                    allocateCustomers();
    std::vector<int>                getClosestDepots(int customer);
    std::vector<int>                sortVehicleList(int depotNumber);
    void                            assignRouteToVehicle(int vehicleNumber, int depotNumber,
                                                         std::vector<int> &depotCustomerAllocation,
                                                         std::vector<double> &depotCustomerDemand);
    void                            addCustomer(int pickedCustomer, double &remainingCapacity,
                                                std::vector<int> &customerList, std::vector<double> &customerDropOff,
                                                std::vector<int> &depotCustomerAllocation,
                                                std::vector<double> &depotCustomerDemand);
    void                            getClosestCustomer(int &pickedCustomer, std::vector<int> &depotCustomerAllocation);
    std::pair<std::vector<int>,
            std::vector<double>>    cheapestInsertion(int depotNumber, std::vector<int> &customerList,
                                                       std::vector<double> &customerDropOff);

};


#endif //ORACS_SOLVER_H
