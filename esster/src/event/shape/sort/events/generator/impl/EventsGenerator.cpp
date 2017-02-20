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

    create_folder(GEN_PATH);
    ofstream events_f;
    events_f.open(GEN_EVENTS_FILE_PATH.c_str());
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
    return rand() % 1000 + 1;
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
    int numOfParts = generateRandomNumber() % 100;
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
