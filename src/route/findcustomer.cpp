//
// Created by Mark van der Broek on 13/03/2017.
//

#include "route.ih"

long Route::findCustomer(int customerID) const
{
    return (find(begin(d_route), end(d_route), customerID) - begin(d_route));
}
