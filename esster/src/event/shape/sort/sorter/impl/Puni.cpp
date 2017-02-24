/*
 * Puni.cpp
 *
 *  Created on: Feb 24, 2017
 *      Author: ary
 */

#include "../headers/Puni.h"

Puni::Puni(std::list<Event> _bin, std::list<Bin> _bins, Event _event) {
    bin = _bin;
    bins = _bins;
    event = _event;
}

long double Puni::compute_P_u_ni() {
    Pniu pniu(bin, event);
    long double resultPniu = pniu.compute_P_ni_u();
    long double numerator = resultPniu / 10.0;

    long double denominator = 0.0;
    for (Bin b : bins) {
        std::list<Event> innerBin = b.get();
        Pniu pniu(innerBin, event);
        long double resultPniuPart = pniu.compute_P_ni_u();
        denominator += resultPniuPart / 10.0;
    }
    long double result = numerator / denominator;
    return result;
}

Puni::~Puni() {
}

