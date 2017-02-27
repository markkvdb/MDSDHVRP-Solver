//
// Created by Mark van der Broek on 27/02/2017.
//

#ifndef ORACS_MAIN_H
#define ORACS_MAIN_H

#include <iostream>
#include "solution.h"
#include <vector>

using namespace std;

struct VehicleType
{
    int type;
    int maximumDrivingTime;
    int drivingSpeed;
    int travellingCost;
    int capacity;
};

class VehiclesTypes
{
    int numberOfDiffVehicles;
    vector<VehicleType> d_vehicletypes;

public:
    VehiclesTypes();
    void addVehicleType(int max)
};

#endif //ORACS_MAIN_H
