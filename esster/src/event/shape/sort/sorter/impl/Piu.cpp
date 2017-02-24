/*
 * Piu.cpp
 *
 *  Created on: Feb 24, 2017
 *      Author: ary
 */

#include "../headers/Piu.h"

Piu::Piu(std::list<Event> _uEventBin, int _iPartAngleBin) {
    uEventBin = _uEventBin;
    iPartAngleBin = _iPartAngleBin;
}

long double Piu::compute_P_iu() {
    long double allEventsMultiplicity = 0.0;
    long double iAngleBinMultiplicity = 0.0;
    for (Event e : uEventBin) {
        allEventsMultiplicity += e.getMultiplicity();

        int *angleBin = e.getAngleBin();
        iAngleBinMultiplicity += angleBin[iPartAngleBin];
    }
    long double result = iAngleBinMultiplicity / allEventsMultiplicity;
    return result;
}

Piu::~Piu() {
}

