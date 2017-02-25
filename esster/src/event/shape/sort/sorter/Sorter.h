/*
 * Sorter.h
 *
 *  Created on: Feb 20, 2017
 *      Author: ary
 */

#ifndef EVENT_SHAPE_SORT_SORTER_SORTER_H_
#define EVENT_SHAPE_SORT_SORTER_SORTER_H_

#include "../utils/files/FilesWorker.h"
#include "../utils/files/FileConstants.h"
#include "../utils/files/FileTypes.h"
#include "../events/headers/Events.h"
#include "../events/headers/Bin.h"
#include "../utils/files/BasePath.h"
#include "headers/AvarageU.h"
#include <string>
#include <math.h>
#include <ctime>
#include <omp.h>

class Sorter {
    private:
        Events* events;
        int eventsInBin = 10;
        std::list<Bin> bins;
        void avarageU();
    public:
        Sorter(std::list<Event> _events);
        Events sort();
        virtual ~Sorter();
};

#endif /* EVENT_SHAPE_SORT_SORTER_SORTER_H_ */
