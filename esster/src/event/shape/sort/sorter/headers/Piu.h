/*
 * Piu.h
 *
 *  Created on: Feb 24, 2017
 *      Author: ary
 */

#ifndef EVENT_SHAPE_SORT_SORTER_HEADERS_PIU_H_
#define EVENT_SHAPE_SORT_SORTER_HEADERS_PIU_H_

#include "../../events/headers/Event.h"

class Piu {
    private:
        std::list<Event> uEventBin;
        int iPartAngleBin;
    public:
        Piu(std::list<Event> _uEventBin, int _iPartAngleBin);
        long double compute_P_iu();
        virtual ~Piu();
};

#endif /* EVENT_SHAPE_SORT_SORTER_HEADERS_PIU_H_ */
