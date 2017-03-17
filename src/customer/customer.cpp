//
// Created by Mark van der Broek on 27/02/2017.
//

/**
 * @brief Constructor
 *
 * @param [in] env          Environment pointer
 * @param [in] id           ID of the customer
 * @param [in] demand       Total demand to satisfy for customer
 * @param [in] serviceTime  The service time
 *
 */

#include "customer.ih"

Customer::Customer(Env *env, int id, int demand, double serviceTime)
:
    d_env(env),
    d_id(id),
    d_demand(demand),
    d_remainingDemand(demand),
    d_serviceTime(serviceTime)
{}
