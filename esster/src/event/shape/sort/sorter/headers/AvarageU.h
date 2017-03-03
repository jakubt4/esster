/*
 * AvarageU.h
 *
 *  Created on: Feb 25, 2017
 *      Author: ary
 */

#ifndef EVENT_SHAPE_SORT_SORTER_HEADERS_AVARAGEU_H_
#define EVENT_SHAPE_SORT_SORTER_HEADERS_AVARAGEU_H_

#include "Puni.h"

class AvarageU {
    public:
        AvarageU();
        long double compute_avarage_u(std::vector<Bin> bins, Event event);
        virtual ~AvarageU();
};

#endif /* EVENT_SHAPE_SORT_SORTER_HEADERS_AVARAGEU_H_ */
