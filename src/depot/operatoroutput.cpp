//
// Created by Mark van der Broek on 06/03/2017.
//

#include "depot.ih"

ostream& operator<<(ostream &os, Depot const &depot)
{
    for (Vehicle const& vehicle: depot.d_vehicles)
    {
        os << depot.d_id << ' ' << vehicle << "\r\n";
    }

    return os;

}