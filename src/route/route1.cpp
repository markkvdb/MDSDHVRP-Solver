//
// Created by Mark van der Broek on 17/03/2017.
//

/**
 * @brief Constructor
 *
 * @param [in] env      Environment pointer
 * @param [in] depotID  ID of the depot
 */

#include "route.ih"

Route::Route(Env *env, int depotID)
        :
        d_env(env),
        d_depotID(depotID),
        d_load(0),
        d_length(0),
        d_serviceTime(0)
{
    d_length = 0;
    d_load = 0;
    d_load = 0;
}