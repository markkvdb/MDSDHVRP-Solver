//
// Created by Mark van der Broek on 27/02/2017.
//

/**
 * @brief Constructor
 *
 * @param [in] env          Environment pointer
 * @param [in] depotID      ID of the depot
 * @param [in] route        Vector of customers IDs to add
 * @param [in] demandRoute  Vector of demands of the customers to add
 */

#include "route.ih"

Route::Route(Env *env, int depotID, std::vector<int> route, std::vector<int> demandRoute)
:
    d_env(env),
    d_depotID(depotID),
    d_route(route),
    d_demandRoute(demandRoute),
    d_load(0),
    d_length(0),
    d_serviceTime(0)
{
    updateDistance();
    updateLoad();
    updateServiceTime();
}