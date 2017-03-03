/*
 * Bins.h
 *
 *  Created on: Mar 3, 2017
 *      Author: ary
 */

#ifndef EVENT_SHAPE_SORT_EVENTS_HEADERS_BINS_H_
#define EVENT_SHAPE_SORT_EVENTS_HEADERS_BINS_H_

#include "Bin.h"

class Bins {
    private:
        std::vector<Bin> bins;
    public:
        Bins(std::vector<Bin> _bins);
        std::vector<Bin> get();
        virtual ~Bins();
};

#endif /* EVENT_SHAPE_SORT_EVENTS_HEADERS_BINS_H_ */
