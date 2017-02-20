/*
 * Event.cpp
 *
 *  Created on: Feb 14, 2017
 *      Author: ary
 */

#include "../headers/Event.h"

Event::Event() {
    multiplicity = 0;
}

void Event::addEventPart(EventPart eventPart) {
    eventParts.push_back(eventPart);
}

std::list<EventPart> Event::get() {
    return eventParts;
}

void Event::setMultiplicity(int _multiplicity) {
    multiplicity = _multiplicity;
}

int Event::getMultiplicity() {
    return multiplicity;
}

void Event::setQ2(double _q2) {
    q2 = _q2;
}

double Event::getQ2() {
    return q2;
}


bool compare(EventPart evP_a, EventPart evP_b) {
    return evP_a.getAngle() < evP_b.getAngle();
}


void Event::sortEventPartByAngles() {
    eventParts.sort(compare);
}

Event::~Event() {
}

