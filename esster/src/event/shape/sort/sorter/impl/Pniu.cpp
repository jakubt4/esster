/*
 * Pniu.cpp
 *
 *  Created on: Feb 24, 2017
 *      Author: ary
 */

#include "../headers/Pniu.h"

Pniu::Pniu(std::list<Event> _bin, Event _event) {
    bin = _bin;
    event = _event;
}

long double Pniu::compute_P_ni_u() {

    long double result = 1.0;
    int *angleBin = event.getAngleBin();
    for (int i = 0; i < 20; i++) {
        Piu piu(bin, i);
        long double piuResult = piu.compute_P_iu();
        long double powPiuResult = pow(piuResult, angleBin[i]);
        result *= powPiuResult;
    }
    return result;
}


Pniu::~Pniu() {

}

