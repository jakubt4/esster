/*
 * Events.h
 *
 *  Created on: Feb 19, 2017
 *      Author: ary
 */

#ifndef EVENT_SHAPE_SORT_EVENTS_HEADERS_EVENTS_H_
#define EVENT_SHAPE_SORT_EVENTS_HEADERS_EVENTS_H_

#include "Event.h"

class Events {
    private:
        std::list<Event> events;
    public:
        Events(std::list<Event> _events);
        std::list<Event> get();
        void sort();
        int size();
        virtual ~Events();
};

#endif /* EVENT_SHAPE_SORT_EVENTS_HEADERS_EVENTS_H_ */
