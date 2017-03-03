/*
 * AvarageU.cpp
 *
 *  Created on: Feb 25, 2017
 *      Author: ary
 */

#include "../headers/AvarageU.h"

AvarageU::AvarageU() {
}

long double AvarageU::compute_avarage_u(std::vector<Bin> bins, Event event) {
    long double i = 1.0;
    long double result = 0.0;
    for (Bin bin : bins) {
        Puni puni;
        long double puniResult = puni.compute_P_u_ni(bin, bins, event);
        result += (i * puniResult);
        i++;
    }
    return result;
}

AvarageU::~AvarageU() {
}

