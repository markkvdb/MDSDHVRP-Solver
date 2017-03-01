//
// Created by Mark van der Broek on 27/02/2017.
//

#include "customer.h"

Customer::Customer(int id, double demand, double serviceTime)
:
    d_id(id),
    d_demand(demand),
    d_remainingDemand(demand),
    d_serviceTime(serviceTime)
{}
