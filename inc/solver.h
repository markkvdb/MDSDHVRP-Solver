//
// Created by Mark van der Broek on 03/03/2017.
//

#ifndef ORACS_SOLVER_H
#define ORACS_SOLVER_H

#include "solution.h"
#include <utility>
#include <functional>

class Env;

class Solver {

    Env *d_env;
    std::vector<std::function<void(Solution &)>> d_localSearchOperators;

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
            std::vector<std::vector<int>>>
                                    allocateCustomers();
    std::vector<int>                getClosestDepots(int customer);
    std::vector<int>                sortVehicleList(int depotNumber);
    void                            assignRouteToVehicle(int vehicleNumber, int depotNumber,
                                                         std::vector<int> &depotCustomerAllocation,
                                                         std::vector<int> &depotCustomerDemand);
    void                            addCustomer(int pickedCustomer, int &remainingCapacity,
                                                std::vector<int> &customerList, std::vector<int> &customerDropOff,
                                                std::vector<int> &depotCustomerAllocation,
                                                std::vector<int> &depotCustomerDemand);
    void                            getClosestCustomer(int seedCustomer, int &pickedCustomer,
                                                       std::vector<int> &depotCustomerAllocation);
    std::pair<std::vector<int>,
            std::vector<int>>       cheapestInsertion(int depotNumber, std::vector<int> &customerList,
                                                       std::vector<int> &customerDropOff);

    // Functions for perturbation
    void                            perturbation(Solution &solution, int q);
    std::vector<int>                randomRemoval(Solution &solution, int q);
    std::vector<int>                costRemoval(Solution &solution, int q);
    std::vector<int>                routeRemoval(Solution &solution, int q);
    double                          computeRemovalGain(Solution &solution, int customerID);
    std::vector<std::pair<int, int>> getNonEmptyRoutes(Solution &solution);
    void                            removeCustomers(Solution &solution, std::vector<int> const &customersToRemove);
    void                            reinsert(Solution &solution, std::vector<int> &customersToAdd);
    std::vector<int>                getClosestCustomers(int seedCustomer, int q);
    void                            insertCustomer(Solution &solution, int selectedCustomer, int positionCustomer,
                                                   int depotID, int vehicleID, int routePos,
                                                   std::vector<int> &customersToAdd);

    // Functions for local search
    void                            localSearch(Solution &s);
    void                            oneInsertionIntraRoute(Solution &s);
    void                            twoInsertionIntraRoute(Solution &s);
    void                            twoOptIntraRoute(Solution &s);
    void                            swap(Solution &s);
    void                            swapStar(Solution &s);
    void                            routeAddition(Solution &s);
    void                            swapStarTwo(Solution &s);



    // Other functions
    Solution &                      simulatedAnnealing(Solution &sPrime, Solution &s);
    int                             selectq();

};


#endif //ORACS_SOLVER_H
