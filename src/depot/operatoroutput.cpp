//
// Created by Mark van der Broek on 06/03/2017.
//

/**
 * @brief Output operator of the depot class
 *
 * @param [in] os       The stream to write to
 * @param [in] customer The depot to write to the stream
 */

#include "depot.ih"

ostream& operator<<(ostream &os, Depot const &depot)
{
    for (Vehicle const& vehicle: depot.d_vehicles)
    {
        os << depot.d_id << ' ' << vehicle << "\r\n";
    }

    return os;

}