/*
 * EventPart.cpp
 *
 *  Created on: Feb 14, 2017
 *      Author: ary
 */

#include "../headers/EventPart.h"

EventPart::EventPart(const int _particles, const double _angle) {
    particles = _particles;
    angle = _angle;
}

int EventPart::getParticles() {
    return particles;
}

double EventPart::getAngle() {
    return angle;
}

EventPart::~EventPart() {
}

