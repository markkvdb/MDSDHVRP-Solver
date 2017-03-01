//
// Created by Mark van der Broek on 27/02/2017.
//

#ifndef ORACS_ROUTE_H
#define ORACS_ROUTE_H

#include "../inc/customer.h"
#include <vector>

class Route {
    std::vector<Customer> d_route;
    // TODO Why specify vehicle type and deliver quantity here?

public:
    Route();
    std::vector<Customer> &getRoute();

};

inline std::vector<Customer> &Route::getRoute()
{
    return d_route;
}
#endif //ORACS_ROUTE_H
