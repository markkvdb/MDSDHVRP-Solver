//
// Created by Mark van der Broek on 01/03/2017.
//

#include "init.ih"

void Init::createDistanceMatrix()
{
    d_distanceMatrix.resize(d_noOfCustomers + d_noOfDepots);
    for (int customer1 = 0; customer1 != d_customerMatrix.size(); ++customer1)
    {
        d_distanceMatrix[customer1].resize(d_noOfCustomers + d_noOfDepots);
        for (int customer2 = 0; customer2 != d_customerMatrix.size(); ++customer2)
        {

            d_distanceMatrix[customer1][customer2] = distance(d_customerMatrix[customer1][1],
                                                              d_customerMatrix[customer1][2],
                                                              d_customerMatrix[customer2][1],
                                                              d_customerMatrix[customer2][2]);
        }
        for (int depot = 0; depot != d_depotMatrix.size(); ++depot)
        {
            d_distanceMatrix[customer1][depot + d_noOfCustomers] = distance(d_customerMatrix[customer1][1],
                                                                            d_customerMatrix[customer1][2],
                                                                            d_depotMatrix[depot][1],
                                                                            d_depotMatrix[depot][2]);
        }
    }
    for (int depot1 = 0; depot1 != d_depotMatrix.size(); ++depot1)
    {
        d_distanceMatrix[depot1 + d_noOfCustomers].resize(d_noOfCustomers + d_noOfDepots);
        for (int customer = 0; customer != d_customerMatrix.size(); ++customer)
        {
            d_distanceMatrix[depot1 + d_noOfCustomers][customer] = distance(d_depotMatrix[depot1][1],
                                                                            d_depotMatrix[depot1][2],
                                                                            d_customerMatrix[customer][1],
                                                                            d_customerMatrix[customer][2]);
        }
        for (int depot2 = 0; depot2 != d_depotMatrix.size(); ++depot2)
        {
            d_distanceMatrix[depot1 + d_noOfCustomers][depot2 + d_noOfCustomers] = distance(d_depotMatrix[depot1][1],
                                                                                            d_depotMatrix[depot1][2],
                                                                                            d_depotMatrix[depot2][1],
                                                                                            d_depotMatrix[depot2][2]);
        }
    }
}