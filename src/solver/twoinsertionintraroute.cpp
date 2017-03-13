//
// Created by Mark van der Broek on 13/03/2017.
//

#include "solver.ih"

void Solver::twoInsertionIntraRoute(Solution &s)
{
    for (Depot &depot: s.getDepots())
    {
        for (Vehicle &vehicle: depot.getVehicles())
        {
            int minCustomer1 = -1;
            int minCustomer2 = -1;
            int minDemand1 = -1;
            int minDemand2 = -1;
            int minPos = -1;
            double minInsertion = numeric_limits<double>::max();

            for (int customerIdx = 1; customerIdx != vehicle.getRoute().getRoute().size() - 2; ++customerIdx)
            {
                int customerID1 = vehicle.getRoute().getRoute()[customerIdx];
                int customerID2 = vehicle.getRoute().getRoute()[customerIdx+1];
                Vehicle newVehicle = vehicle;

                int customerDemand1 = newVehicle.removeCustomer(customerID1);
                int customerDemand2 = newVehicle.removeCustomer(customerID2);
                auto insertion = newVehicle.cheapestInsertion(customerID1);

                if (insertion.second < minInsertion)
                {
                    minCustomer1 = customerID1;
                    minCustomer2 = customerID2;
                    minDemand1 = customerDemand1;
                    minDemand2 = customerDemand2;
                    minPos = insertion.first;
                    minInsertion = insertion.second;
                }
            }
            if (minCustomer1 != -1)
            {
                vehicle.removeCustomer(minCustomer1);
                vehicle.removeCustomer(minCustomer2);
                vehicle.addCustomer(minCustomer1, minDemand1, minPos);
            }
        }
    }
}