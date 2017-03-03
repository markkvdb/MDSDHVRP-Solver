//
// Created by Mark van der Broek on 03/03/2017.
//

#include "solver.ih"

void Solver::assignRouteToVehicle(int vehicleNumber, int depotNumber,
                                  std::vector<int> &depotCustomerAllocation)
{
    double remainingCapacity = d_env->d_depots[depotNumber].getVehicle(vehicleNumber).getCapacity();

    // Create customer and drop off list
    std::vector<int> customerList{};
    std::vector<double> customerDropOff{};

    random_device rd;                                   // only used once to initialise (seed) engine
    mt19937 rng(rd());                                  // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(0, depotCustomerAllocation.size());    // guaranteed unbiased

    int pickedCustomer = depotCustomerAllocation[uni(rng)];

    while (remainingCapacity > 0 && not depotCustomerAllocation.empty())
    {
        addCustomer(pickedCustomer, remainingCapacity, customerList, customerDropOff,
                    depotCustomerAllocation);

        getClosestCustomer(pickedCustomer, depotCustomerAllocation);
    }

    cout << "[" << depotNumber << ", " << vehicleNumber << "]: ";
    for (int customer: customerList)
        cout << customer << ' ';
    cout << '\n';

}
