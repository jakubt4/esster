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
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-gen") == 0) {
            if ((i + 1) < argc) {
                EventsGenerator eveGen(atoi(argv[i + 1]));
                i++;
                eveGen.generate();
            } else {
                EventsGenerator eveGen(1000);
                eveGen.generate();
            }
        } else {
            cout << "Bad parameter !!" << endl;
            cout << "Try: -gen int" << endl;
            return 0;
        }
    }

    BasePath bp;
    string str = bp.getBasePath() + GEN_PARTICLES_FILE_PATH;
    Reader reader(str);
    std::list<Event> evReaded = reader.readData();

    ofstream events_f, particles_f;
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

    Sorter sorter(evReaded);
    std::vector<Bin> ev = sorter.sort();

    str = bp.getBasePath() + GEN_PATH + "sorted_events.txt";
    events_f.open(str.c_str());
    str = bp.getBasePath() + GEN_PATH + "sorted_particles.txt";
    particles_f.open(str.c_str());
    int binsSize = ev.size();
    int evn = 1;
    for (int i = 0; i < binsSize; i++) {
        for (Event e : ev[i].get()) {
            events_f << evn << setw(15) << e.getMultiplicity() << setw(15) << e.getSorter() << endl;
            int *angleBin = e.getAngleBin();
            for (int i = 0; i < 20; i++) {
                particles_f << evn << setw(15) << i << setw(15) << angleBin[i] << endl;
            }
            evn++;
        }
    }
    events_f.close();
    particles_f.close();

    cout << "ALL DONE" << endl;
    return EXIT_SUCCESS;
}
