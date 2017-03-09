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
    int                 d_id;
    double              d_demand;
    double              d_remainingDemand;
    double              d_serviceTime;
    std::vector<int>    d_vehicles;

public:
    Customer() = delete;
    Customer(Env *env, int id, double demand, double serviceTime);

    int     getId()                      const;
    double  getDemand()                  const;
    double  getServiceTime()             const;
    double  getRemainingDemand()         const;
    void    changeDemand(double demand);
    void    addToVehicle(int vehicle);

    friend std::ostream& operator<<(std::ostream &os, Customer const &customer);

};

inline int Customer::getId() const
{
    return d_id;
}

inline double Customer::getDemand() const
{
    return d_demand;
}

inline double Customer::getServiceTime() const
{
    return d_serviceTime;
}

inline double Customer::getRemainingDemand() const
{
    return d_remainingDemand;
}

inline void Customer::changeDemand(double demand)
{
    d_remainingDemand += demand;
}

inline void Customer::addToVehicle(int vehicle)
{
    d_vehicles.push_back(vehicle);
}


#endif //ORACS_CUSTOMER_H
