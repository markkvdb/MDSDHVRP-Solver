//
// Created by Mark van der Broek on 03/03/2017.
//

#ifndef ORACS_ENV_H
#define ORACS_ENV_H

#include <vector>
#include "depot.h"
#include "customer.h"
#include "init.h"

class Env {

    typedef std::vector<std::vector<double>> DoubleMatrix;

public:
    std::vector<Depot>      d_depots;
    std::vector<Customer>   d_customers;
    DoubleMatrix            d_distanceMatrix;

    Env();
    Env(Init &init);

    void addDepot(Depot &depot);
    void addCustomer(Customer &customer);

};

#endif //ORACS_ENV_H
