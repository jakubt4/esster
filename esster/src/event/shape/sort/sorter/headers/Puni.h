/*
 * Puni.h
 *
 *  Created on: Feb 24, 2017
 *      Author: ary
 */

#ifndef EVENT_SHAPE_SORT_SORTER_HEADERS_PUNI_H_
#define EVENT_SHAPE_SORT_SORTER_HEADERS_PUNI_H_

#include "../../events/headers/Bin.h"
#include "Pniu.h"

class Puni {
    private:
        std::list<Event> bin;
        std::list<Bin> bins;
        Event event;
    public:
        Puni(std::list<Event> _bin, std::list<Bin> _bins, Event _event);
        long double compute_P_u_ni();
        virtual ~Puni();
};

#endif /* EVENT_SHAPE_SORT_SORTER_HEADERS_PUNI_H_ */
