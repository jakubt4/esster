/*
 * EventTest.cpp
 *
 *  Created on: Feb 24, 2017
 *      Author: ary
 */

#include "../../../../../src/event/shape/sort/events/headers/Event.h"
#include <stdexcept>

int main() {
    cout << "START Event TEST..." << endl;
    Event ev;
    int M = 0;
    for (int i = 0; i < 10; i++) {
        M += (50 * i);
        EventPart ep(50 * i, (6.0 / (i + 1)));
        ev.addEventPart(ep);
    }
    ev.setMultiplicity(M);
    ev.prepareAngleBins();

    if (ev.getMultiplicity() != 2250) {
        cout << "Multiplicity of event should be 2250 but was " << ev.getMultiplicity() << endl;
        throw std::invalid_argument("Bad result");
    } else {
        cout << "Multiplicity for event test: OK" << endl;
    }
    int *angleBin = ev.getAngleBin();

    for (int i = 0; i < 20; i++) {
        cout << "Angle bin " << i << " :" << endl;
        switch (i) {
            case 1:
                if (angleBin[i] == 450) {
                    cout << "OK" << endl;
                } else {
                    cout << "Should be 450 but was " << angleBin[i] << endl;
                    throw std::invalid_argument("Bad result");
                }
                break;
            case 2:
                if (angleBin[i] == 1050) {
                    cout << "OK" << endl;
                } else {
                    cout << "Should be 1050 but was " << angleBin[i] << endl;
                    throw std::invalid_argument("Bad result");
                }
                break;
            case 3:
                if (angleBin[i] == 450) {
                    cout << "OK" << endl;
                } else {
                    cout << "Should be 450 but was " << angleBin[i] << endl;
                    throw std::invalid_argument("Bad result");
                }
                break;
            case 4:
                if (angleBin[i] == 150) {
                    cout << "OK" << endl;
                } else {
                    cout << "Should be 150 but was " << angleBin[i] << endl;
                    throw std::invalid_argument("Bad result");
                }
                break;
            case 6:
                if (angleBin[i] == 100) {
                    cout << "OK" << endl;
                } else {
                    cout << "Should be 100 but was " << angleBin[i] << endl;
                    throw std::invalid_argument("Bad result");
                }
                break;
            case 9:
                if (angleBin[i] == 50) {
                    cout << "OK" << endl;
                } else {
                    cout << "Should be 50 but was " << angleBin[i] << endl;
                    throw std::invalid_argument("Bad result");
                }
                break;
            default:
                if (angleBin[i] == 0) {
                    cout << "OK" << endl;
                } else {
                    cout << "Should be 0 but was " << angleBin[i] << endl;
                    throw std::invalid_argument("Bad result");
                }
                break;
        }
    }
    cout << "EventTest SUCCESSFUL DONE" << endl;
}
