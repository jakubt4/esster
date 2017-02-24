/*
 * Puni.cpp
 *
 *  Created on: Feb 25, 2017
 *      Author: ary
 */

#include "../../../../../src/event/shape/sort/sorter/headers/Puni.h"
#include <stdexcept>

int main() {
    std::list<Bin> bins;
    for (int j = 0; j < 10; j++) {
        Bin b(j);
        for (int i = 0; i < 10; i++) {
            Event e;
            EventPart ep1(50, 0);
            EventPart ep2(150, 0.35);
            e.addEventPart(ep1);
            e.addEventPart(ep2);
            e.setMultiplicity(200);
            e.fillAngleBin();
            b.addEvent(e);
        }
        bins.push_back(b);
    }

    Bin b(0);
    for (int i = 0; i < 10; i++) {
        Event e;
        EventPart ep1(50, 0);
        EventPart ep2(150, 0.35);
        e.addEventPart(ep1);
        e.addEventPart(ep2);
        e.setMultiplicity(200);
        e.fillAngleBin();
        b.addEvent(e);
    }

    Event e;
    EventPart ep1(50, 0);
    EventPart ep2(150, 0.35);
    e.addEventPart(ep1);
    e.addEventPart(ep2);
    e.setMultiplicity(200);
    e.fillAngleBin();

    std::list<Event> binEv = b.get();
    Puni puni(binEv, bins, e);
    long double result = puni.compute_P_u_ni();
    if (round(result * 10) == 1) {
        cout << "Result for similar events is OK" << endl;
    } else {
        cout.precision(35);
        cout << "Result should be 0.10000000000000000000813151629364128 but was " << result << endl;
        throw std::invalid_argument("Bad result");
    }

    std::list<Bin> bins2;
    for (int j = 0; j < 10; j++) {
        Bin b(j);
        for (int i = 0; i < 10; i++) {
            Event e;
            EventPart ep1(50, 0);
            EventPart ep2(150, 0.35);
            e.addEventPart(ep1);
            e.addEventPart(ep2);
            e.setMultiplicity(200);
            e.fillAngleBin();
            b.addEvent(e);
        }
        bins2.push_back(b);
    }

    Bin b2(0);
    for (int i = 0; i < 10; i++) {
        Event e;
        EventPart ep1(500, 0);
        EventPart ep2(500, 0.35);
        EventPart ep3(500, 0.8);
        e.addEventPart(ep1);
        e.addEventPart(ep2);
        e.addEventPart(ep3);
        e.setMultiplicity(1500);
        e.fillAngleBin();
        b2.addEvent(e);
    }

    Event e2;
    EventPart ep21(500, 0);
    EventPart ep22(500, 0.35);
    EventPart ep23(500, 0.35);
    EventPart ep24(500, 0.35);
    e2.addEventPart(ep21);
    e2.addEventPart(ep22);
    e2.addEventPart(ep23);
    e2.addEventPart(ep24);
    e2.setMultiplicity(2000);
    e2.fillAngleBin();

    Puni puni2(b2.get(), bins2, e2);
    result = puni2.compute_P_u_ni();
    if (result == 0) {
        cout << "Result for different events is OK" << endl;
    } else {
        cout.precision(35);
        cout << "Result should be 0 but was " << result << endl;
        throw std::invalid_argument("Bad result");
    }

    cout << "PuniTest successful" << endl;
}
