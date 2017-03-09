//
// Created by Mark van der Broek on 27/02/2017.
//

#ifndef ORACS_ROUTE_H
#define ORACS_ROUTE_H

#include <vector>
#include <fstream>

class Env;

class Route {

    Env *                   d_env;
    int                     d_depotID;
    double                  d_load;
    double                  d_length;
    double                  d_serviceTime;
    std::vector<int>        d_route;
    std::vector<double>     d_demandRoute;

public:
    Route() = delete;
    Route(Env *env, int depotID);
    Route(Env *env, int depotID, std::vector<int> route, std::vector<double> demandRoute);

    std::vector<int> &      getRoute();
    std::vector<double> &   getDemandRoute();
    std::vector<int> const &getRoute()         const;
    double const            getLoad()           const;
    double const            getDistance()       const;
    double const            getServiceTime()    const;

    double                  removeCustomer(int customerID);
    void                    addCustomer(int customerID, double load, int routePos);

    friend std::ostream &operator<<(std::ostream &, Route const &route);


private:
    void updateDistance();
    void updateServiceTime();
    void updateLoad();

};

inline std::vector<int> &Route::getRoute()
{
    return d_route;
}

inline std::vector<int> const &Route::getRoute() const
{
    return d_route;
}

inline std::vector<double> &Route::getDemandRoute()
{
    return d_demandRoute;
}

inline double const Route::getLoad() const
{
    return d_load;
}

inline double const Route::getDistance() const
{
    return d_length;
}

inline double const Route::getServiceTime() const
{
    return d_serviceTime;
}

#endif //ORACS_ROUTE_H
