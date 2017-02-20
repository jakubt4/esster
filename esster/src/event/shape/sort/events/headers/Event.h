/*
 * Event.h
 *
 *  Created on: Feb 14, 2017
 *      Author: ary
 */

#ifndef EVENT_SHAPE_SORT_EVENTS_HEADERS_EVENT_H_
#define EVENT_SHAPE_SORT_EVENTS_HEADERS_EVENT_H_

#include "../../common/CommonLibraries.h"
#include "EventPart.h"

class Event {
    private:
        std::list<EventPart> eventParts;
        int multiplicity;
        double q2 = 0.0;
    public:
        Event();
        void addEventPart(const EventPart eventPart);
        std::list<EventPart> get();
        void setMultiplicity(int _multiplicity);
        int getMultiplicity();
        void setQ2(double _q2);
        double getQ2();
        void sortEventPartByAngles();
        virtual ~Event();
};

#endif /* EVENT_SHAPE_SORT_EVENTS_HEADERS_EVENT_H_ */
