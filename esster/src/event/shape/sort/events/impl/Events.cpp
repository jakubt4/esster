/*
 * Events.cpp
 *
 *  Created on: Feb 19, 2017
 *      Author: ary
 */

#include "../headers/Events.h"

bool compare(Event ev_a, Event ev_b) {
    return ev_a.getSorter() < ev_b.getSorter();
}

Events::Events(std::list<Event> _events) {
    events = _events;
    events.sort(compare);
}

std::list<Event> Events::get() {
    return events;
}

void Events::sort() {
    events.sort(compare);
}

int Events::size() {
    return events.size();
}

Events::~Events() {
    for (Event e : events) {
        e.getParticles().clear();
    }
    events.clear();
}

