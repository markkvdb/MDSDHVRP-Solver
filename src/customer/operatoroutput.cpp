//
// Created by Mark van der Broek on 01/03/2017.
//

#include "customer.ih"

std::ostream& operator<<(std::ostream &os, Customer const &customer)
{
    os << customer.d_id << ' ';
    for (auto vehicle: customer.d_vehicles)
        os << vehicle.first << ' ';

    os << '\n';

    return os;
}
