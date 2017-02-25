/*
 * AvarageUTest.cpp
 *
 *  Created on: Feb 25, 2017
 *      Author: ary
 */

#include "../../../../../src/event/shape/sort/sorter/headers/AvarageU.h"
#include <stdexcept>


int main() {
    cout << "START AvarageUTest - u..." << endl;
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

    Event e;
    EventPart ep1(50, 0);
    EventPart ep2(150, 0.35);
    e.addEventPart(ep1);
    e.addEventPart(ep2);
    e.setMultiplicity(200);
    e.fillAngleBin();

    AvarageU avarageU(bins, e);
    long double result = avarageU.compute_avarage_u();
    if (result == 5.5) {
        cout << "Result for similar events is OK" << endl;
    } else {
        cout.precision(35);
        cout << "Result should be 5.5 but was " << result << endl;
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
    Event e2;
    EventPart ep21(500, 0);
    EventPart ep22(500, 0.35);
    EventPart ep23(500, 0.8);
    e2.addEventPart(ep21);
    e2.addEventPart(ep22);
    e2.addEventPart(ep23);
    e2.setMultiplicity(1500);
    e2.fillAngleBin();

    AvarageU avarageU2(bins2, e2);
    result = avarageU2.compute_avarage_u();
    if (result == 0) {
        cout << "Result for different events is OK" << endl;
    } else {
        cout.precision(35);
        cout << "Result should be 0 but was " << result << endl;
        throw std::invalid_argument("Bad result");
    }
    cout << "AvarageUTest SUCCESSFUL DONE" << endl;
}
