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
    private:
        std::list<Bin> bins;
        Event event;
    public:
        AvarageU(std::list<Bin> _bins, Event _event);
        long double compute_avarage_u();
        virtual ~AvarageU();
};

#endif /* EVENT_SHAPE_SORT_SORTER_HEADERS_AVARAGEU_H_ */
