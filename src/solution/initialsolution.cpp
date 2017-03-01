//
// Created by Mark van der Broek on 01/03/2017.
//

#include "solution.ih"

void Solution::initialSolution()
{
    // Create Depot-Customer allocation
    vector<vector<int>> depotCustomerAllocation = allocateCustomers();

    for (int row = 0; row != depotCustomerAllocation.size(); ++row)
    {
        cout << "Depot " << row << ": ";
        for (int col = 0; col != depotCustomerAllocation[row].size(); ++col)
        {
            cout << depotCustomerAllocation[row][col] << '\t';
        }
        cout << '\n';
    }
    cout << '\n';
}