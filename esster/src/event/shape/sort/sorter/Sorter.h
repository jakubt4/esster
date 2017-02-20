/*
 * Sorter.h
 *
 *  Created on: Feb 20, 2017
 *      Author: ary
 */

#ifndef EVENT_SHAPE_SORT_SORTER_SORTER_H_
#define EVENT_SHAPE_SORT_SORTER_SORTER_H_

#include "../events/headers/Events.h"
#include "../events/headers/Bin.h"

class Sorter {
    private:
        Events* events;
        int numverOfBins = 10;
        std::list<Bin> bins;
    public:
        Sorter(std::list<Event> _events);
        virtual ~Sorter();
};

#endif /* EVENT_SHAPE_SORT_SORTER_SORTER_H_ */
