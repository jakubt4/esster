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
#include <vector>

class Event {
    private:
        std::list<EventPart> eventParts;
        int multiplicity;
        int id = 0;
        double sorter = 0.0;
        int angle_bin[20];
    public:
        Event();
        void addEventPart(const EventPart eventPart);
        std::list<EventPart> get();
        void setMultiplicity(int _multiplicity);
        int getMultiplicity();
        void setSorter(double _sorter);
        double getSorter();
        void setActualEventBin(int _id);
        int getActualEventBin();
        void fillAngleBin();
        int* getAngleBin();
        long double PI = 3.14159265358979323846;
        EventPart getActualEventPart(int actualEventPart);
        virtual ~Event();
};

#endif /* EVENT_SHAPE_SORT_EVENTS_HEADERS_EVENT_H_ */
