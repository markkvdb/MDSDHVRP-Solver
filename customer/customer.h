//
// Created by Mark van der Broek on 27/02/2017.
//

#ifndef ORACS_CUSTOMER_H
#define ORACS_CUSTOMER_H


#include "../route/route.h"

class Customer {
    int d_demand;
    std::vector<Route> d_routes;

public:
    Customer(int demand);

};


#endif //ORACS_CUSTOMER_H
