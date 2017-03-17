//
// Created by Mark van der Broek on 09/03/2017.
//

/**
 * @brief Reset the remaning demand of the customer to the total demand.
 */

#include "customer.ih"

void Customer::resetRemainingDemand()
{
    d_remainingDemand = d_demand;
}