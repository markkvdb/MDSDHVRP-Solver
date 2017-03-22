//
// Created by Mark van der Broek on 01/03/2017.
//

/**
 * @brief Create distance matrix based on the coordinates of all locations.
 */

#include "init.ih"

void Init::createDistanceMatrix()
{
    size_t numberOfElements = d_noOfDepots + d_noOfCustomers;
    d_distanceMatrix.resize(numberOfElements * numberOfElements);
    for (int customer1 = 0; customer1 != d_customerMatrix.size(); ++customer1)
    {
        for (int customer2 = 0; customer2 != d_customerMatrix.size(); ++customer2)
        {

            d_distanceMatrix[customer1 * numberOfElements + customer2] = distance(d_customerMatrix[customer1][1],
                                                                                  d_customerMatrix[customer1][2],
                                                                                  d_customerMatrix[customer2][1],
                                                                                  d_customerMatrix[customer2][2]);
        }
        for (int depot = 0; depot != d_depotMatrix.size(); ++depot)
        {
            d_distanceMatrix[customer1 * numberOfElements + depot + d_noOfCustomers] =
                    distance(d_customerMatrix[customer1][1], d_customerMatrix[customer1][2], d_depotMatrix[depot][1],
                             d_depotMatrix[depot][2]);
        }
    }
    for (int depot1 = 0; depot1 != d_depotMatrix.size(); ++depot1)
    {
        for (int customer = 0; customer != d_customerMatrix.size(); ++customer)
        {
            d_distanceMatrix[(depot1 + d_noOfCustomers) * numberOfElements + customer] =
                    distance(d_depotMatrix[depot1][1], d_depotMatrix[depot1][2], d_customerMatrix[customer][1],
                             d_customerMatrix[customer][2]);
        }
        for (int depot2 = 0; depot2 != d_depotMatrix.size(); ++depot2)
        {
            d_distanceMatrix[(depot1 + d_noOfCustomers) * numberOfElements + depot2 + d_noOfCustomers] =
                    distance(d_depotMatrix[depot1][1], d_depotMatrix[depot1][2], d_depotMatrix[depot2][1],
                             d_depotMatrix[depot2][2]);
        }
    }

}