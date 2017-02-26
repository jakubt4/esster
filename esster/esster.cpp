//============================================================================
// Name        : esster.cpp
// Author      : Jakub Toth
// Version     : 1.0.0
// Copyright   : Jakub Toth
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

#include "src/event/shape/sort/events/generator/header/EventsGenerator.h"
#include "src/event/shape/sort/events/headers/Event.h"
#include "src/event/shape/sort/events/headers/EventPart.h"
#include "src/event/shape/sort/events/headers/Events.h"
#include "src/event/shape/sort/events/reader/Reader.h"
#include "src/event/shape/sort/sorter/Sorter.h"

int main(int argc, char* argv[]) {
//    for (int i = 1; i < argc; ++i) {
//        if (strcmp(argv[i], "-gen") == 0) {
//            if ((i + 1) < argc) {
//                generate(atoi(argv[i + 1]));
//            } else {
//                generate(NUM_OF_EVENTS);
//            }
//        } else if (strcmp(argv[i], "-sort")) {
//            //sort();
//        }
//    }
    EventsGenerator eveGen(100);
    eveGen.generate();
    BasePath bp;
    string str = bp.getBasePath() + GEN_EVENTS_FILE_PATH;
    cout << str << endl;
    Reader reader(str);
    std::list<Event> evReaded = reader.readData();
    Sorter sorter(evReaded);
    Events ev = sorter.sort();
    Events events(evReaded);
    ofstream events_f;
    str = bp.getBasePath() + LOADED_EVENTS_FILE_PATH;
    events_f.open(str.c_str());
    int en = 1;
    for (Event e : evReaded) {
        int *angleBin = e.getAngleBin();
        for (int i = 0; i < 20; i++) {
            events_f << en << setw(15) << i << setw(15) << angleBin[i] << endl;
        }
        en++;
//        events_f << en << setw(15) << e.getMultiplicity() << setw(15) << e.getSorter() << endl;
//        en++;
    }
    events_f.close();
    cout << "ALL DONE" << endl;
    return EXIT_SUCCESS;
}
