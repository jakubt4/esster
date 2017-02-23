/*
 * Bin.cpp
 *
 *  Created on: Feb 14, 2017
 *      Author: ary
 */

#include "../headers/Bin.h"

Bin::Bin(int _id) {
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

Bin::~Bin() {
}

