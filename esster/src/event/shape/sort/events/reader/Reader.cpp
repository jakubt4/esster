/*
 * Reader.cpp
 *
 *  Created on: Feb 17, 2017
 *      Author: ary
 */

#include "Reader.h"

Reader::Reader(string _path) {
    path = _path;
}

std::list<Event> Reader::readData() {
    cout << "Loading data.." << endl;
    std::ifstream ifile(path.c_str(), std::ios::in);
    int eventNumber = 1;
//    int numberOfParticles = 0;
    double angle = 0.0;
    int actualEvent = 1;
    int multiplicity = 0;
    double q_x = 0.0;
    double q_y = 0.0;
    double q_2 = 0.0;

    std::list<Event> events;

    Event* e = new Event();
    while (ifile >> eventNumber) {
        if (actualEvent != eventNumber) {
            q_2 = sqrt(pow(q_x, 2) + pow(q_y, 2)) / sqrt(multiplicity);

            e->setSorter(q_2);
            e->setMultiplicity(multiplicity);
            e->prepareAngleBins();
            multiplicity = 0;
            actualEvent = eventNumber;
            if (actualEvent % 100 == 0) {
                cout << actualEvent << " events loaded." << endl;
            }
            events.push_back(*e);
            e = new Event();
            q_x = 0.0;
            q_y = 0.0;
        }
        ifile >> angle;
//        ifile >> numberOfParticles;
//        multiplicity += numberOfParticles;
        multiplicity += 1;

        q_x += cos(2.0 * angle);
        q_y += sin(2.0 * angle);

//        EventPart eventPart(numberOfParticles, angle);
//        e->addEventPart(eventPart);

        Particle p(angle);
        e->addParticle(p);

    }
    q_2 = sqrt(pow(q_x, 2) + pow(q_y, 2)) / sqrt(multiplicity);
    e->setSorter(q_2);
    e->setMultiplicity(multiplicity);
    e->prepareAngleBins();
    events.push_back(*e);
    cout << "Data loaded." << endl;
    return events;
}

Reader::~Reader() {
}

