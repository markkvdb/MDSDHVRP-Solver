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

            if (vehicle.getRoute().getRoute().size() < 5)
                continue;

            for (int customerIdx = 1; customerIdx != vehicle.getRoute().getRoute().size() - 2; ++customerIdx)
            {
                int customerID1 = vehicle.getRoute().getRoute()[customerIdx];
                int customerID2 = vehicle.getRoute().getRoute()[customerIdx+1];
                int customerDemand1 = vehicle.getRoute().getDemandRoute()[customerIdx];
                int customerDemand2 = vehicle.getRoute().getDemandRoute()[customerIdx+1];

                Vehicle newVehicle = vehicle;
                double gainDistance = newVehicle.getRoute().getDistance();
                double oldPenaltyTime = newVehicle.getPenaltyTime();

                newVehicle.removeCustomer(customerID1);
                newVehicle.removeCustomer(customerID2);
                gainDistance -= newVehicle.getRoute().getDistance();

                auto insertion = newVehicle.cheapestInsertion(customerID1, customerID2);

                double extraTravelDistance = insertion.second - gainDistance;
                double extraPenaltyCost =  (max(0.0, oldPenaltyTime + extraTravelDistance / newVehicle.getDrivingSpeed()) - oldPenaltyTime) * d_env->d_penalty;
                double extraCost = extraTravelDistance * newVehicle.getCost() + extraPenaltyCost;

                if (extraCost < minInsertion)
                {
                    minCustomer1 = customerID1;
                    minCustomer2 = customerID2;
                    minDemand1 = customerDemand1;
                    minDemand2 = customerDemand2;
                    minPos = insertion.first;
                    minInsertion = extraCost;
                }
            }
            if (minCustomer1 != -1)
            {
                vehicle.removeCustomer(minCustomer1);
                vehicle.removeCustomer(minCustomer2);
                vehicle.addCustomer(minCustomer1, minDemand1, minPos);
                vehicle.addCustomer(minCustomer2, minDemand2, minPos+1);
            }
        }
    }
}