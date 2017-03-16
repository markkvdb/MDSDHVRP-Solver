//
// Created by Mark van der Broek on 12/03/2017.
//

#include "route.ih"

void Route::twoOpt(int bIdx, int cIdx)
{
    vector<int> newRoute;
    vector<int> newLoad;

    vector<int> firstPart(begin(d_route), begin(d_route) + bIdx);
    vector<int> secondPart(begin(d_route) + bIdx, begin(d_route) + cIdx + 1);
    reverse(begin(secondPart), end(secondPart));
    vector<int> thirdPart(begin(d_route) + cIdx + 1, end(d_route));

    vector<int> firstPart2{begin(d_demandRoute), begin(d_demandRoute) + bIdx};
    vector<int> secondPart2{begin(d_demandRoute) + bIdx, begin(d_demandRoute) + cIdx + 1};
    reverse(begin(secondPart2), end(secondPart2));
    vector<int> thirdPart2{begin(d_demandRoute) + cIdx + 1, end(d_demandRoute)};

    newRoute.insert(end(newRoute), begin(firstPart), end(firstPart));
    newRoute.insert(end(newRoute), begin(secondPart), end(secondPart));
    newRoute.insert(end(newRoute), begin(thirdPart), end(thirdPart));
    newLoad.insert(end(newLoad), begin(firstPart2), end(firstPart2));
    newLoad.insert(end(newLoad), begin(secondPart2), end(secondPart2));
    newLoad.insert(end(newLoad), begin(thirdPart2), end(thirdPart2));

    d_route = newRoute;
    d_demandRoute = newLoad;

    updateServiceTime();
    updateDistance();
    updateLoad();

}