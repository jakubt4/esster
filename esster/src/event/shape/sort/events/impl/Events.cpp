/*
 * Events.cpp
 *
 *  Created on: Feb 19, 2017
 *      Author: ary
 */

#include "../headers/Events.h"

bool compare(Event ev_a, Event ev_b) {
    return ev_a.getQ2() < ev_b.getQ2();
}

Events::Events(std::list<Event> _events) {
    events = _events;
    events.sort(compare);
}

std::list<Event> Events::get() {
    return events;
}

Events::~Events() {
}

