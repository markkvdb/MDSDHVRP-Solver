//
// Created by Mark van der Broek on 01/03/2017.
//

#include "customer.h"

std::ostream& operator<<(std::ostream &os, Customer const &customer)
{
    os << "ID:\t" << customer.d_id << "\nDemand:\t" << customer.d_demand << "\nRemaining demand:\t"
       << customer.d_remainingDemand << "\nService time:\t" << customer.d_serviceTime << "\n\n";

    return os;
}
