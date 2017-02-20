/*
 * EventPart.h
 *
 *  Created on: Feb 14, 2017
 *      Author: ary
 */

#ifndef EVENT_SHAPE_SORT_EVENTS_HEADERS_EVENTPART_H_
#define EVENT_SHAPE_SORT_EVENTS_HEADERS_EVENTPART_H_

class EventPart {
    private:
        int particles;
        double angle;
    public:
        EventPart(const int _particles, const double _angle);
        double getAngle();
        int getParticles();
        virtual ~EventPart();
};

#endif /* EVENT_SHAPE_SORT_EVENTS_HEADERS_EVENTPART_H_ */
