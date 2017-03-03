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
    int d_id;
    const double d_demand;
    double d_remainingDemand;
    const double d_serviceTime;
//    std::vector<Route> d_routes;

public:
    Customer() = delete;
    Customer(Env *env, int id, double demand, double serviceTime);

    int getId() const;
    double getDemand() const;
    double getServiceTime() const;
    double getRemainingDemand() const;
    void changeDemand(double demand);

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


#endif //ORACS_CUSTOMER_H
