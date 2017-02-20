/*
 * Bin.cpp
 *
 *  Created on: Feb 14, 2017
 *      Author: ary
 */

#include "../headers/Bin.h"

Bin::Bin() {
}

void Bin::addEvent(Event event) {
    events.push_back(event);
}

std::list<Event> Bin::get() {
    return events;
}

Bin::~Bin() {
}

