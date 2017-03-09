//
// Created by Mark van der Broek on 09/03/2017.
//

#include "route.ih"

void Route::addCustomer(int customerID, double load, int routePos)
{
    d_route.insert(begin(d_route) + routePos, customerID);
    d_demandRoute.insert(begin(d_demandRoute) + routePos, load);

    updateLoad();
    updateDistance();
    updateServiceTime();
}