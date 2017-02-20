/*
 * Bin.h
 *
 *  Created on: Feb 14, 2017
 *      Author: ary
 */

#ifndef EVENT_SHAPE_SORT_EVENTS_HEADERS_BIN_H_
#define EVENT_SHAPE_SORT_EVENTS_HEADERS_BIN_H_

#include "../../common/CommonLibraries.h"
#include "Event.h"

class Bin {
    private:
        std::list<Event> events;
    public:
        Bin();
        void addEvent(Event event);
        std::list<Event> get();
        virtual ~Bin();
};

#endif /* EVENT_SHAPE_SORT_EVENTS_HEADERS_BIN_H_ */
