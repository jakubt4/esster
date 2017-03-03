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
        int id = 0;
        long double mOverMyEvents = 0.0;
        long double mOverAngleBins[20] = { 0 };
    public:
        Bin();
        void setId(int _id);
        void addEvent(Event event);
        std::list<Event> get();
        int getId();
        void setMultiplicityOverMyEvents(long double _mOverMyEvents);
        long double getMultiplicityOverMyEvents();
        void setMultiplicityOverAngleBins(long double* _mOverAngleBins);
        long double* getMultiplicityOverAngleBins();
        virtual ~Bin();
};

#endif /* EVENT_SHAPE_SORT_EVENTS_HEADERS_BIN_H_ */
