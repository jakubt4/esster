/*
 * Reader.h
 *
 *  Created on: Feb 17, 2017
 *      Author: ary
 */

#ifndef EVENT_SHAPE_SORT_EVENTS_READER_READER_H_
#define EVENT_SHAPE_SORT_EVENTS_READER_READER_H_

#include "../../utils/files/FilesWorker.h"
#include "../../utils/files/FileConstants.h"
#include "../../utils/files/FileTypes.h"
#include "../headers/Event.h"
#include "../headers/EventPart.h"

using namespace std;

class Reader {
    private:
        string path;
    public:
        Reader(string _path);
        std::list<Event> readData();
        virtual ~Reader();
};

#endif /* EVENT_SHAPE_SORT_EVENTS_READER_READER_H_ */
