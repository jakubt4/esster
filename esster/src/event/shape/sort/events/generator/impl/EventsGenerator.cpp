/*
 * EventsGenerator.cpp
 *
 *  Created on: Feb 14, 2017
 *      Author: ary
 */

#include "../header/EventsGenerator.h"

EventsGenerator::EventsGenerator(int _numOfEvents) {
    numOfEvents = _numOfEvents;
    srand(time(NULL));
}

std::list<Event> EventsGenerator::generate() {
    for (int i = 0; i < numOfEvents; i++) {
        prepareEvent();
    }
    BasePath bp;
    string str = bp.getBasePath();
    create_folder(str + GEN_PATH);
    ofstream events_f;
    str = str + GEN_EVENTS_FILE_PATH;
    events_f.open(str.c_str());
    int en = 1;
    for (Event e : events) {
        for (EventPart ep : e.get()) {
            events_f << en << setw(15) << ep.getAngle() << setw(15) << ep.getParticles() << endl;
            // cout << en << setw(15) << ep.getAngle() << setw(15) << ep.getParticles() << endl;
        }
        en++;
    }
    events_f.close();
    return events;
}

const int _PI = 3141593;

int EventsGenerator::generateRandomNumber() {
    return rand() % 100 + 1;
}

double EventsGenerator::generateRandomAngle() {
    int r = rand() % 10000000;
    while (r > 2 * _PI) {
        r = rand() % 10000000;
    }
    return (double) r / 1000000;
}

void EventsGenerator::prepareEvent() {
    Event e;
    int numOfParts = generateRandomNumber();
    for (int i = 0; i < numOfParts; i++) {
        int particles = generateRandomNumber();
        double angle = generateRandomAngle();
        EventPart eventPart(particles, angle);
        e.addEventPart(eventPart);
    }
    events.push_back(e);
}

EventsGenerator::~EventsGenerator() {
}
