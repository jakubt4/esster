/*
 * Pniu.h
 *
 *  Created on: Feb 24, 2017
 *      Author: ary
 */

#ifndef EVENT_SHAPE_SORT_SORTER_HEADERS_PNIU_H_
#define EVENT_SHAPE_SORT_SORTER_HEADERS_PNIU_H_

#include <math.h>
#include "Piu.h"
#include "../../events/headers/Event.h"

class Pniu {
    private:
        std::list<Event> bin;
        Event event;
    public:
        Pniu(std::list<Event> _bin, Event _event);
        long double compute_P_ni_u();
        virtual ~Pniu();
};

#endif /* EVENT_SHAPE_SORT_SORTER_HEADERS_PNIU_H_ */
