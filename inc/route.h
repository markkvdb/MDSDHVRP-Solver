//
// Created by Mark van der Broek on 27/02/2017.
//

#ifndef ORACS_ROUTE_H
#define ORACS_ROUTE_H

#include <vector>
#include <fstream>

class Env;

/**
 * Route is a class that holds a route.
 */
class Route {

    Env *                   d_env; /*!< Environment pointer */
    int                     d_depotID; /*!< ID of the depot where the route belongs to */
    int                     d_load; /*!< Total load of the route */
    double                  d_length; /*!< Total length of the route */
    double                  d_serviceTime; /*!< Total service time of the route. (Customers + distance) */
    std::vector<int>        d_route; /*!< Vector of ints containing the ID of the customers in the route */
    std::vector<int>        d_demandRoute; /*!< Vector of ints containing the demands corresponds to the route */

public:
    Route() = delete;
    Route(Env *env, int depotID);
    Route(Env *env, int depotID, std::vector<int> route, std::vector<int> demandRoute);

    std::vector<int> &      getRoute();
    std::vector<int>        getRouteCopy();
    std::vector<int> &      getDemandRoute();
    std::vector<int> const &getRoute()         const;
    int const               getLoad()           const;
    double const            getDistance()       const;
    double const            getServiceTime()    const;

    int                     removeCustomer(int customerID);
    void                    addCustomer(int customerID, int load, int routePos);
    long                    findCustomer(int customerID) const;
    void                    twoOpt(int bIdx, int cIdx);
    void                    swap(int aIdx, int bIdx);

    friend std::ostream &operator<<(std::ostream &, Route const &route);


private:
    void updateDistance();
    void updateServiceTime();
    void updateLoad();

};

/**
 * Get the actual route.
 * @return Vector of ints containing the IDs of the customers to traverse
 */
inline std::vector<int> &Route::getRoute()
{
    return d_route;
}

/**
 * Get the actual route as a copy.
 * @return Vector of ints containing the IDs of the customers to traverse
 */
inline std::vector<int> Route::getRouteCopy()
{
    return d_route;
}

/**
 * Get the actual route (consts).
 * @return Vector of ints containing the IDs of the customers to traverse (const)
 */
inline std::vector<int> const &Route::getRoute() const
{
    return d_route;
}

/**
 * Get the demands of the route.
 * @return Vector of ints containing the demands of the customers to traverse
 */
inline std::vector<int> &Route::getDemandRoute()
{
    return d_demandRoute;
}

/**
 * Get the total load of the route.
 * @return Load of the route
 */
inline int const Route::getLoad() const
{
    return d_load;
}

/**
 * Get the total distance travelled by the route.
 * @return Total distance of the route
 */
inline double const Route::getDistance() const
{
    return d_length;
}

/**
 * Get the total service time of the route
 * @return Total service time of the route
 */
inline double const Route::getServiceTime() const
{
    return d_serviceTime;
}
#endif //ORACS_ROUTE_H
