/*
 * AvarageU.cpp
 *
 *  Created on: Feb 25, 2017
 *      Author: ary
 */

#include "../headers/AvarageU.h"

AvarageU::AvarageU(std::list<Bin> _bins, Event _event) {
    bins = _bins;
    event = _event;
}

long double AvarageU::compute_avarage_u() {
    long double i = 1.0;
    long double result = 0.0;
    for (Bin bin : bins) {
        std::list<Event> binEvents = bin.get();
        Puni puni(binEvents, bins, event);
        long double puniResult = puni.compute_P_u_ni();
        result += (i * puniResult);
        i++;
    }
    return result;
}

AvarageU::~AvarageU() {
}

