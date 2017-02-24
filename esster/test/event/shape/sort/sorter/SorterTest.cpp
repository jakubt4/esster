/*
 * SorterTest.cpp
 *
 *  Created on: Feb 24, 2017
 *      Author: ary
 */

#include "../../../../../src/event/shape/sort/sorter/Sorter.h"
#include "../../../../../src/event/shape/sort/events/headers/Events.h"

int main() {
    std::list<Event> listOfEvents;
    for (int j = 0; j < 10; j++) {
        Event ev;
        for (int i = 0; i < 5; i++) {
            EventPart part(50 * (i + 1), 0.5 * (i + 1));
            ev.addEventPart(part);
        }
        listOfEvents.push_back(ev);
    }



    Events events()
}
