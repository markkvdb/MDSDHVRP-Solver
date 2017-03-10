//
// Created by Mark van der Broek on 03/03/2017.
//

#ifndef ORACS_SOLVER_H
#define ORACS_SOLVER_H

#include "solution.h"
#include <utility>

class Env;

class Solver {

    typedef void (Solver::*operatorFunction)(Solution &);

    Env *d_env;
    std::vector<operatorFunction> d_localSearchOperators;

public:
    Solver() = delete;
    Solver(Env *env);

    void initialSolution();
    void run();
    void print();

private:
    // Functions for initial solution
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
    void                            getClosestCustomer(int seedCustomer, int &pickedCustomer,
                                                       std::vector<int> &depotCustomerAllocation);
    std::pair<std::vector<int>,
            std::vector<double>>    cheapestInsertion(int depotNumber, std::vector<int> &customerList,
                                                       std::vector<double> &customerDropOff);

    // Functions for perturbation
    void                            perturbation(Solution &solution, int q);
    std::vector<int>                randomRemoval(Solution &solution, int q);
    void                            removeCustomers(Solution &solution, std::vector<int> const &customersToRemove);
    void                            reinsert(Solution &solution, std::vector<int> &customersToAdd);
    std::vector<int>                getClosestCustomers(int seedCustomer, int q);
    void                            insertCustomer(Solution &solution, int selectedCustomer, int positionCustomer,
                                                   int depotID, int vehicleID, int routePos,
                                                   std::vector<int> &customersToAdd);

    // Functions for local search
    void                            localSearch(Solution &s);
    void                            oneInsertionIntraRoute(Solution &s);

    // Other functions
    Solution &                      simulatedAnnealing(Solution &sPrime, Solution &s);

};


#endif //ORACS_SOLVER_H
