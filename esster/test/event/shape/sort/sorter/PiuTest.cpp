/*
 * PiuTest.cpp
 *
 *  Created on: Feb 24, 2017
 *      Author: ary
 */

#include "../../../../../src/event/shape/sort/events/headers/Bin.h"
#include "../../../../../src/event/shape/sort/sorter/headers/Piu.h"
#include <stdexcept>

int main() {
    cout << "START PiuTest - P(i|u)..." << endl;
    Bin b(1);
    for (int i = 0; i < 10; i++) {
        Event e;
        EventPart ep1(50, 0);
        EventPart ep2(150, 0.35);
        e.addEventPart(ep1);
        e.addEventPart(ep2);
        e.setMultiplicity(200);
        e.prepareAngleBins();
        b.addEvent(e);
    }

    Piu piu1(b.get(), 0);
    long double result = piu1.compute_P_iu();
    if (result == 0.25) {
        cout << "Result of P(0|u) - OK." << endl;
    } else {
        cout << "Result should be 0.25 but was " << result << endl;
        throw std::invalid_argument("Bad result");
    }

    Piu piu2(b.get(), 1);
    result = piu2.compute_P_iu();
    if (result == 0.75) {
        cout << "Result of P(1|u) - OK" << endl;
    } else {
        cout << "Result should be 0.75 but was " << result << endl;
        throw std::invalid_argument("Bad result");
    }

    cout << "PiuTest SUCCESSFUL DONE" << endl;
}
