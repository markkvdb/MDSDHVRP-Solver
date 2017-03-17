//
// Created by Mark van der Broek on 13/03/2017.
//

/**
 * @brief Delete vehicle from the vehicle list of the customer.
 *
 * @param [in] depotID      Depot ID
 * @param [in] vehicleID    Vehicle ID in the depot
 */

#include "customer.ih"

void Customer::deleteVehicle(int depotID, int vehicleID)
{
    bool deleted = false;
    for (size_t vehicleIdx = 0; vehicleIdx < d_vehicles.size(); ++vehicleIdx)
    {
        if (d_vehicles[vehicleIdx].first == depotID && d_vehicles[vehicleIdx].second == vehicleID)
        {
            d_vehicles.erase(begin(d_vehicles) + vehicleIdx);
            deleted = true;
        }
    }
    if (not deleted)
        cerr << "Not deleted.\n";
}