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
//    EventsGenerator eveGen(1000);
//    eveGen.generate();

    Reader reader(GEN_EVENTS_FILE_PATH);
    std::list<Event> evReaded = reader.readData();
    Sorter sorter(evReaded);
//    Events events(evReaded);
//    ofstream events_f;
//    events_f.open(LOADED_EVENTS_FILE_PATH.c_str());
//    int en = 1;
//    for (Event e : events.get()) {
////        for (EventPart ep : e.get()) {
////            events_f << en << setw(15) << ep.getAngle() << setw(15) << ep.getParticles() << setw(15) << e.getQ2()
////                    << endl;
////        }
//        events_f << en << setw(15) << e.getMultiplicity() << setw(15) << e.getSorter() << endl;
//        en++;
//    }
//    events_f.close();
    cout << "ALL DONE" << endl;

    return EXIT_SUCCESS;
}
