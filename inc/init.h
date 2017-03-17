//
// Created by Mark van der Broek on 01/03/2017.
//

#ifndef ORACS_INIT_H
#define ORACS_INIT_H

#include <iostream>
#include <vector>

/**
 * Init class reads the data from the input file, and puts it in the approriate data members.
 */
class Init
{
    int                                 d_noOfDepots; /*!< Number of depots */
    int                                 d_noOfVehicleTypes; /*!< Number of vehicle types */
    int                                 d_noOfCustomers; /*!< Number of customers */
    std::vector<std::vector<double>>    d_vehicleMatrix; /*!< List of all vehicles, and its attributes */
    std::vector<std::vector<double>>    d_depotMatrix; /*!< List of all depots, and its attributes */
    std::vector<std::vector<double>>    d_customerMatrix; /*!< List of all customers, and its attributes */
    std::vector<std::vector<double>>    d_distanceMatrix; /*!< Distance matrix for all instances of the problem */

public:
    Init() = delete;
    Init(std::string &file);

    void                                    showVehicleMatrix();
    void                                    showDepotMatrix();
    void                                    showCustomerMatrix();
    void                                    showDistanceMatrix();
    void                                    show();

    int                                     getNoOfDepots()         const;
    int                                     getNoOfVehicleTypes()   const;
    int                                     getNoOfCustomers()      const;
    const std::vector<std::vector<double>>  &getVehicleMatrix()     const;
    const std::vector<std::vector<double>>  &getDepotMatrix()       const;
    const std::vector<std::vector<double>>  &getCustomerMatrix()    const;
    const std::vector<std::vector<double>>  &getDistanceMatrix()    const;

private:
    void                                    showMatrix(std::vector<std::vector<double>> matrix);
    void                                    createDistanceMatrix();
    double                                  distance(double x1, double y1, double x2, double y2);
};

/**
 * Shows the vehicles, depots, customers, and the distance matrix.
 */
inline void Init::show()
{
    showVehicleMatrix();
    showDepotMatrix();
    showCustomerMatrix();
    showDistanceMatrix();
}

/**
 * Find the number of depots in the problem.
 * @return Number of depots
 */
inline int Init::getNoOfDepots() const
{
    return d_noOfDepots;
}

/**
 * Find the number of vehicle types in the problem
 * @return Number of vehicle types
 */
inline int Init::getNoOfVehicleTypes() const
{
    return d_noOfVehicleTypes;
}

/**
 * Find the number of customers in the problem
 * @return Number of customers
 */
inline int Init::getNoOfCustomers() const
{
    return d_noOfCustomers;
}

/**
 * Find the matrix of all vehicles. Each row corresponds to one vehicle.
 * @return Matrix of all vehicles. Each row corresponds to one vehicle.
 */
inline const std::vector<std::vector<double>> &Init::getVehicleMatrix() const
{
    return d_vehicleMatrix;
}

/**
 * Find the matrix of all depots. Each row corresponds to one depot.
 * @return Matrix of all depots. Each row corresponds to one depot.
 */
inline const std::vector<std::vector<double>> &Init::getDepotMatrix() const
{
    return d_depotMatrix;
}

/**
 * Find the matrix of all customers. Each row corresponds to one customer.
 * @return Matrix of all customers. Each row corresponds to one customer.
 */
inline const std::vector<std::vector<double>> &Init::getCustomerMatrix() const
{
    return d_customerMatrix;
}

/**
 * Find the matrix with all distances between each instance in the problem.
 * @return Matrix with all distances between every instance (Depots and Customers)
 */
inline const std::vector<std::vector<double>> &Init::getDistanceMatrix() const
{
    return d_distanceMatrix;
}

#endif //ORACS_INIT_H
