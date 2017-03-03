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
    public:
        Puni();
        long double compute_P_u_ni(Bin b, std::vector<Bin> bins, Event event);
        virtual ~Puni();
};

#endif /* EVENT_SHAPE_SORT_SORTER_HEADERS_PUNI_H_ */
