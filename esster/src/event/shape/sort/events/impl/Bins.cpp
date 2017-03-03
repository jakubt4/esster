/*
 * Bins.cpp
 *
 *  Created on: Mar 3, 2017
 *      Author: ary
 */

#include "../headers/Bins.h"

Bins::Bins(std::vector<Bin> _bins) {
    bins = _bins;
}

std::vector<Bin> Bins::get() {
    return bins;
}

Bins::~Bins() {
    for (Bin b : bins) {
        for (Event e : b.get()) {
            e.getParticles().clear();
        }
        b.get().clear();
    }
}

