/*
 * Puni.cpp
 *
 *  Created on: Feb 24, 2017
 *      Author: ary
 */

#include "../headers/Puni.h"

Puni::Puni() {
}

long double Puni::compute_P_u_ni(Bin b, std::vector<Bin> bins, Event event) {
    Pniu pniu;
    long double resultPniu = pniu.compute_P_ni_u(b, event);
    long double numerator = resultPniu / 10.0;

    long double denominator = 0.0;
    for (Bin b : bins) {
        std::list<Event> innerBin = b.get();
        Pniu pniu;
        long double resultPniuPart = pniu.compute_P_ni_u(b, event);
        denominator += resultPniuPart / 10.0;
    }

    if (denominator == 0) {
        return 0;
    }

    long double result = numerator / denominator;
    return result;
}

Puni::~Puni() {
}

