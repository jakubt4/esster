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

void Event::setActualEventBin(int _id) {
    id = _id;
}

int Event::getActualEventBin() {
    return id;
}

void Event::fillAngleBin() {
    long double baseAngle = PI / 10.0;
    for (EventPart eventPart : eventParts) {
        long double angle = eventPart.getAngle();
        for (int i = 0; i < 20; i++) {
            if (angle >= (baseAngle * i) && angle < (baseAngle * (i + 1))) {
                angle_bin[i] = angle_bin[i] + eventPart.getParticles();
            }
        }
    }
}

int* Event::getAngleBin() {
    return angle_bin;
}

EventPart Event::getActualEventPart(int actualEventPart) {
    std::vector<EventPart> vecEventPart { eventParts.begin(), eventParts.end() };
    return vecEventPart[actualEventPart];
}

Event::~Event() {
}

