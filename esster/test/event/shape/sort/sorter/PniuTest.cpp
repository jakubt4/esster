/*
 * PniuTest.cpp
 *
 *  Created on: Feb 24, 2017
 *      Author: ary
 */

#include "../../../../../src/event/shape/sort/events/headers/Bin.h"
#include "../../../../../src/event/shape/sort/sorter/headers/Pniu.h"
#include <stdexcept>

int main() {
    cout << "START PniuTest - P(ni|u)..." << endl;
    Bin b(1);
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

    Pniu pniu(b.get(), e);
    long double result = pniu.compute_P_ni_u();

    if (result == 1.4328144157343807586182059746435232e-49) {
        cout << "Result for event with similar angle bin is OK" << endl;
    } else {
        cout.precision(34);
        cout << "Result should be 1.4328144157343807586182059746435232e-49 but was " << result << endl;
        throw std::invalid_argument("Bad result");
    }

    Event e2;
    EventPart ep21(500, 0);
    EventPart ep22(500, 0.35);
    EventPart ep23(500, 0.8);
    e2.addEventPart(ep21);
    e2.addEventPart(ep22);
    e2.addEventPart(ep23);
    e2.setMultiplicity(1500);
    e2.fillAngleBin();

    Pniu pniu2(b.get(), e2);
    result = pniu2.compute_P_ni_u();

    if (result == 0) {
        cout << "Result for event with different angle bin is OK" << endl;
    } else {
        cout << "Result should be 1.43281e-49 but was " << result << endl;
        throw std::invalid_argument("Bad result");
    }

    cout << "PniuTest SUCCESSFUL DONE" << endl;
}
