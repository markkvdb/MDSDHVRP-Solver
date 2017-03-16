//
// Created by Mark van der Broek on 09/03/2017.
//

#include "route.ih"

int Route::removeCustomer(int customerID)
{
    long positionCustomer = find(begin(d_route), end(d_route), customerID) - begin(d_route);

    int demand = 0;
    if (positionCustomer != d_route.size())
    {
        d_route.erase(begin(d_route) + positionCustomer);
        demand = d_demandRoute[positionCustomer];
        d_demandRoute.erase(begin(d_demandRoute) + positionCustomer);
    }

    updateLoad();
    updateServiceTime();
    updateDistance();

    return demand;
}