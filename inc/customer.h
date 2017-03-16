//
// Created by Mark van der Broek on 27/02/2017.
//

#ifndef ORACS_CUSTOMER_H
#define ORACS_CUSTOMER_H

#include <vector>
#include <fstream>

class Env;

class Customer {

    Env *d_env;
    int                                 d_id;
    int                                 d_demand;
    int                                 d_remainingDemand;
    double                              d_serviceTime;
    std::vector<std::pair<int, int>>    d_vehicles;

public:
    Customer() = delete;
    Customer(Env *env, int id, int demand, double serviceTime);

    int                                 getId()                      const;
    int                                 getDemand()                  const;
    double                              getServiceTime()             const;
    int                                 getRemainingDemand()         const;
    std::vector<std::pair<int, int>> &  getVehicles();
    void                                deleteVehicle(int depotID, int vehicleID);
    void                                changeDemand(int demand);
    void                                addToVehicle(int depotID, int vehicleID);
    void                                resetRemainingDemand();

    friend std::ostream&                operator<<(std::ostream &os, Customer const &customer);

};

inline int Customer::getId() const
{
    return d_id;
}

inline int Customer::getDemand() const
{
    return d_demand;
}

inline double Customer::getServiceTime() const
{
    return d_serviceTime;
}

inline int Customer::getRemainingDemand() const
{
    return d_remainingDemand;
}

inline void Customer::changeDemand(int demand)
{
    d_remainingDemand += demand;
}

inline void Customer::addToVehicle(int depotID, int vehicleID)
{
    d_vehicles.push_back(std::make_pair(depotID, vehicleID));
}

inline std::vector<std::pair<int, int>> &Customer::getVehicles()
{
    return d_vehicles;
}


#endif //ORACS_CUSTOMER_H
