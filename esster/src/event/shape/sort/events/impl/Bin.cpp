/*
 * Bin.cpp
 *
 *  Created on: Feb 14, 2017
 *      Author: ary
 */

#include "../headers/Bin.h"

Bin::Bin() {
}

void Bin::setId(int _id) {
    id = _id;
}

void Bin::addEvent(Event event) {
    events.push_back(event);
}

std::list<Event> Bin::get() {
    return events;
}

int Bin::getId() {
    return id;
}

void Bin::setMultiplicityOverMyEvents(long double _mOverMyEvents) {
    mOverMyEvents = _mOverMyEvents;
}

long double Bin::getMultiplicityOverMyEvents() {
    return mOverMyEvents;
}
void Bin::setMultiplicityOverAngleBins(long double* _mOverAngleBins) {
    for (int i = 0; i < 20; i++) {
        mOverAngleBins[i] = _mOverAngleBins[i];
    }
}

long double* Bin::getMultiplicityOverAngleBins() {
    return mOverAngleBins;
}

Bin::~Bin() {
    for (Event e : events) {
        e.getParticles().clear();
    }
    events.clear();
}

