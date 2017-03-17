//
// Created by Mark van der Broek on 01/03/2017.
//

/**
 * @brief Output operator of the customer class
 *
 * @param [in] os       The stream to write to
 * @param [in] customer The customer to write to the stream
 */

#include "customer.ih"

std::ostream& operator<<(std::ostream &os, Customer const &customer)
{
    os << customer.d_id << ' ';
    for (auto vehicle: customer.d_vehicles)
        os << vehicle.first << ' ';

    os << '\n';

    return os;
}
