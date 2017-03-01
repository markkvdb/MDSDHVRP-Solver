//
// Created by Mark van der Broek on 01/03/2017.
//

#ifndef ORACS_INIT_H
#define ORACS_INIT_H

#include <iostream>
#include <vector>

class Init
{
    int d_noOfDepots;
    int d_noOfVehicleTypes;
    int d_noOfCustomers;
    std::vector<std::vector<double>> d_vehicleMatrix;
    std::vector<std::vector<double>> d_depotMatrix;
    std::vector<std::vector<double>> d_customerMatrix;
    std::vector<std::vector<double>> d_distanceMatrix;

public:
    Init() = delete;
    Init(std::string &file);

    void showVehicleMatrix();
    void showDepotMatrix();
    void showCustomerMatrix();
    void showDistanceMatrix();
    void show();

private:
    void showMatrix(std::vector<std::vector<double>> matrix);
    void createDistanceMatrix();
    double distance(double x1, double y1, double x2, double y2);
};

inline void Init::show()
{
    showVehicleMatrix();
    showDepotMatrix();
    showCustomerMatrix();
    showDistanceMatrix();
}

#endif //ORACS_INIT_H
