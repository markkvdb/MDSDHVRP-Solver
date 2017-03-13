//
// Created by Mark van der Broek on 27/02/2017.
//

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

Route::Route(Env *env, int depotID)
:
    d_env(env),
    d_depotID(depotID),
    d_load(0),
    d_length(0),
    d_serviceTime(0)
{}