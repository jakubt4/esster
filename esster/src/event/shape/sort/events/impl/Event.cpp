/*
 * Event.cpp
 *
 *  Created on: Feb 14, 2017
 *      Author: ary
 */

#include "../headers/Event.h"

Event::Event() {
    multiplicity = 0;
    for (int i = 0; i < 20; i++) {
        angle_bin[i] = 0;
    }
}

void Event::addParticle(Particle p) {
    particles.push_back(p);
}

std::list<Particle> Event::getParticles() {
    return particles;
}

void Event::setMultiplicity(int _multiplicity) {
    multiplicity = _multiplicity;
}

int Event::getMultiplicity() {
    return multiplicity;
}

void Event::setSorter(double _sorter) {
    sorter = _sorter;
}

double Event::getSorter() {
    return sorter;
}

void Event::setActualEventBin(int _id) {
    id = _id;
}

int Event::getActualEventBin() {
    return id;
}

void Event::prepareAngleBins() {
    long double baseAngle = PI / 10.0;
    for (Particle p : particles) {
        long double angle = p.getAngle();
        for (int i = 0; i < 20; i++) {
            if (angle >= (baseAngle * i) && angle < (baseAngle * (i + 1))) {
                angle_bin[i] += 1;
                break;
            }
        }
    }
}

int* Event::getAngleBin() {
    return angle_bin;
}

Event::~Event() {
    particles.clear();
}

