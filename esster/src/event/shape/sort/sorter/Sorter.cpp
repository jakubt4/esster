/*
 * Sorter.cpp
 *
 *  Created on: Feb 20, 2017
 *      Author: ary
 */

#include "Sorter.h"

Sorter::Sorter(std::list<Event> _events) {
    events = new Events(_events);
    int i = 1;
    Bin* bin = new Bin();
    for (Event event : events->get()) {
        bin->addEvent(event);
        if (i % numverOfBins == 0) {
            bins.push_back(*bin);
            bin = new Bin();
            cout << "Prepared BIN number " << i / numverOfBins << endl;
        }
        i++;
    }
    cout << "Number of all bins is " << bins.size() << endl;
}

Sorter::~Sorter() {
}

