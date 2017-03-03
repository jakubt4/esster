/*
 * Particle.h
 *
 *  Created on: Mar 2, 2017
 *      Author: ary
 */

#ifndef EVENT_SHAPE_SORT_EVENTS_HEADERS_PARTICLE_H_
#define EVENT_SHAPE_SORT_EVENTS_HEADERS_PARTICLE_H_

class Particle {
    private:
        long double angle;
    public:
        Particle(long double _angle);
        long double getAngle();
        virtual ~Particle();
};

#endif /* EVENT_SHAPE_SORT_EVENTS_HEADERS_PARTICLE_H_ */
