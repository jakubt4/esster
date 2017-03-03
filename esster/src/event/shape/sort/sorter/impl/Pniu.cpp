/*
 * Pniu.cpp
 *
 *  Created on: Feb 24, 2017
 *      Author: ary
 */

#include "../headers/Pniu.h"

Pniu::Pniu() {
}

long double Pniu::compute_P_ni_u(Bin b, Event event) {

    long double result = 1.0;
    int *angleBin = event.getAngleBin();
    for (int i = 0; i < 20; i++) {
//        Piu piu(bin, i);
        long double* m = b.getMultiplicityOverAngleBins();
        long double piuResult = m[i] / b.getMultiplicityOverMyEvents(); //piu.compute_P_iu();
        long double powPiuResult = pow(piuResult, angleBin[i]);
        result *= powPiuResult;
    }
    return result;
}


Pniu::~Pniu() {

}

