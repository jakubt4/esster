/*
 * EventsGenerator.h
 *
 *  Created on: Feb 14, 2017
 *      Author: ary
 */

#ifndef EVENT_SHAPE_SORT_EVENTS_GENERATOR_HEADER_EVENTSGENERATOR_H_
#define EVENT_SHAPE_SORT_EVENTS_GENERATOR_HEADER_EVENTSGENERATOR_H_

#include "../../../common/CommonLibraries.h"
#include "../../headers/Event.h"
#include "../../../utils/files/FilesWorker.h"
#include "../../../utils/files/FileConstants.h"

using namespace std;

class EventsGenerator {
    private:
        int numOfEvents;
        std::list<Event> events;
    public:
        EventsGenerator(const int _numOfEvents);
        std::list<Event> generate();
        void prepareEvent();
        int generateRandomNumber();
        double generateRandomAngle();

        void create_folder(string path) {
            struct stat sb;

            if (stat(path.c_str(), &sb) != 0 && !S_ISDIR(sb.st_mode)) {
                mkdir(path.c_str(), 0777);
                cout << "Creation of " << path << endl;
            }
        }
        virtual ~EventsGenerator();
};

#endif /* EVENT_SHAPE_SORT_EVENTS_GENERATOR_HEADER_EVENTSGENERATOR_H_ */
