//
// Created by Mark van der Broek on 27/02/2017.
//

#ifndef ORACS_ROUTE_H
#define ORACS_ROUTE_H

#include <vector>

class Env;

class Route {
    Env *                   d_env;
    int                     d_depotID;
    std::vector<int>        d_route;
    std::vector<double>     d_demandRoute;

public:
    Route() = delete;
    Route(Env *env, int depotID);
    Route(Env *env, int depotID, std::vector<int> route, std::vector<double> demandRoute);

    std::vector<int>        &getRoute();
    std::vector<double>     &getDemandRoute();
    double                  travelDistance();

};

inline std::vector<int> &Route::getRoute()
{
    return d_route;
}

inline std::vector<double> &Route::getDemandRoute()
{
    return d_demandRoute;
}
#endif //ORACS_ROUTE_H
