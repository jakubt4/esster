/*
 * Particle.cpp
 *
 *  Created on: Mar 2, 2017
 *      Author: ary
 */

#include "../headers/Particle.h"

Particle::Particle(long double _angle) {
    angle = _angle;
}

long double Particle::getAngle() {
    return angle;
}

Particle::~Particle() {
}

