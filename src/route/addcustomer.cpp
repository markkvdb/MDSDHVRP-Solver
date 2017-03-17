//
// Created by Mark van der Broek on 09/03/2017.
//

/**
 * @brief Add customer to the route. Update the d_route member and the d_demandRoute member.
 *
 * @param [in] customerID   ID of the customer
 * @param [in] load         Total demand of the customer
 * @param [in] routePos     The position to insert the customer into.
 */

#include "route.ih"

void Route::addCustomer(int customerID, int load, int routePos)
{
    d_route.insert(begin(d_route) + routePos, customerID);
    d_demandRoute.insert(begin(d_demandRoute) + routePos, load);

    updateLoad();
    updateDistance();
    updateServiceTime();
}