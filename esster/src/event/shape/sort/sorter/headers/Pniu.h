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
#include "../../events/headers/Bin.h"

class Pniu {
    public:
        Pniu();
        long double compute_P_ni_u(Bin b, Event event);
        virtual ~Pniu();
};

#endif /* EVENT_SHAPE_SORT_SORTER_HEADERS_PNIU_H_ */
