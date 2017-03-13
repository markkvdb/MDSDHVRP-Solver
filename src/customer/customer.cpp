//
// Created by Mark van der Broek on 27/02/2017.
//

#include "customer.ih"

Customer::Customer(Env *env, int id, int demand, double serviceTime)
:
    d_env(env),
    d_id(id),
    d_demand(demand),
    d_remainingDemand(demand),
    d_serviceTime(serviceTime)
{}
