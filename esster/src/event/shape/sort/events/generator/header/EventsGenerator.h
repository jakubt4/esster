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
#include "../../../utils/files/BasePath.h"
#include "../../../utils/files/FileConstants.h"
#include <cmath>

using namespace std;

class EventsGenerator {
    private:
        int numOfEvents;
        std::list<Event> events;
        double fn[2];
        double vn[2];
        double vn0[2];
        double fi = 0;
        double params[2][3] = { { 0, -0.000006, -0.00018 }, { -0.000092, 0.00811, 0.0418 } };

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

typedef unsigned long long int Ullong;

struct random {
        Ullong u, v, w;
        random(Ullong j) :
                v(4101842887655102017LL), w(1)
        //constructor
        {
            u = j ^ v;
            int64();
            v = u;
            int64();
            w = v;
            int64();
        }
        inline Ullong int64() //inline; compiler inserts complete function body when the function is called
        {
            u = u * 2862933555777941757LL + 7046029254386353087LL;
            v ^= v >> 17;
            v ^= v << 31;
            v ^= v >> 8;
            w = 4294957665U * (w & 0xffffffff) + (w >> 32);
            Ullong x = u ^ (u << 21);
            x ^= x >> 35;
            x ^= x << 4;
            return (x + v) ^ w;
        }
        inline double doub() {
            return 5.42101086242752217E-20 * int64();
        }
};

#endif /* EVENT_SHAPE_SORT_EVENTS_GENERATOR_HEADER_EVENTSGENERATOR_H_ */
