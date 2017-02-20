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

void Event::setSorter(double _sorter) {
    sorter = _sorter;
}

double Event::getSorter() {
    return sorter;
}


bool compare(EventPart evP_a, EventPart evP_b) {
    return evP_a.getAngle() < evP_b.getAngle();
}


void Event::sortEventPartByAngles() {
    eventParts.sort(compare);
}

Event::~Event() {
}

