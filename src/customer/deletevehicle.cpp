//
// Created by Mark van der Broek on 13/03/2017.
//

#include "customer.ih"

void Customer::deleteVehicle(int depotID, int vehicleID)
{
    for (size_t vehicleIdx = 0; vehicleIdx < d_vehicles.size(); ++vehicleIdx)
    {
        if (d_vehicles[vehicleIdx].first == depotID && d_vehicles[vehicleIdx].second == vehicleID)
        {
            d_vehicles.erase(begin(d_vehicles) + vehicleIdx);
            return;
        }
    }
    cerr << "Not deleted.\n";
}