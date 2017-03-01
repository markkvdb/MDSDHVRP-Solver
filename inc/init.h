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

    int getNoOfDepots() const;
    int getNoOfVehicleTypes() const;
    int getNoOfCustomers() const;
    const std::vector<std::vector<double>> &getVehicleMatrix() const;
    const std::vector<std::vector<double>> &getDepotMatrix() const;
    const std::vector<std::vector<double>> &getCustomerMatrix() const;
    const std::vector<std::vector<double>> &getDistanceMatrix() const;

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

inline int Init::getNoOfDepots() const
{
    return d_noOfDepots;
}

inline int Init::getNoOfVehicleTypes() const
{
    return d_noOfVehicleTypes;
}

inline int Init::getNoOfCustomers() const
{
    return d_noOfCustomers;
}

inline const std::vector<std::vector<double>> &Init::getVehicleMatrix() const
{
    return d_vehicleMatrix;
}

inline const std::vector<std::vector<double>> &Init::getDepotMatrix() const
{
    return d_depotMatrix;
}

inline const std::vector<std::vector<double>> &Init::getCustomerMatrix() const
{
    return d_customerMatrix;
}

inline const std::vector<std::vector<double>> &Init::getDistanceMatrix() const
{
    return d_distanceMatrix;
}

#endif //ORACS_INIT_H
