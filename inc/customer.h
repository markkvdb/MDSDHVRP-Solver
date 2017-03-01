//
// Created by Mark van der Broek on 27/02/2017.
//

#ifndef ORACS_CUSTOMER_H
#define ORACS_CUSTOMER_H

#include <vector>

class Customer {
    double d_demand;
    double d_serviceTime;
//    std::vector<Route> d_routes;

public:
    Customer(double demand, double serviceTime);

};


#endif //ORACS_CUSTOMER_H
