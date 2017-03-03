//
// Created by Mark van der Broek on 27/02/2017.
//

#ifndef ORACS_SOLUTION_H
#define ORACS_SOLUTION_H

#include <vector>
#include <iostream>
#include "depot.h"
#include "customer.h"
#include "init.h"

class Solution {

    std::vector<Depot> d_depots;
    std::vector<Customer> d_customers;
    std::vector<std::vector<double>> d_distanceMatrix;

public:
    Solution();

    void print();

private:

};

#endif //ORACS_SOLUTION_H
