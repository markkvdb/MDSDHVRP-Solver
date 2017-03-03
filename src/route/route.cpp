//
// Created by Mark van der Broek on 27/02/2017.
//

#include "route.ih"

Route::Route(Env *env, int depotID, std::vector<Customer> route, std::vector<double> demandRoute)
:
    d_env(env),
    d_depotID(depotID),
    d_route(route),
    d_demandRoute(demandRoute)
{}

Route::Route(Env *env, int depotID)
:
    d_env(env),
    d_depotID(depotID)
{}