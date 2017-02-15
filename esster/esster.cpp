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

#include "headers/generator/generator.h"
#include "headers/sort/sort.h"
#include "src/EventsGenerator.h"
#include "src/Event.h"
#include "src/EventPart.h"
#include "src/EventsGeneratorUtil.h"
#include "src/utils/folder_creator_util.cpp"

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
    std::list<Event> events = eveGen.generate();

    create_folder(GEN_PATH);
    ofstream events_f;
    events_f.open(GEN_EVENTS_FILE_PATH.c_str());
    int en = 1;
    for (Event e : events) {
        for (EventPart ep : e.get()) {
            events_f << en << setw(15) << ep.getAngle() << setw(15) << ep.getParticles() << endl;
            cout << en << setw(15) << ep.getAngle() << setw(15) << ep.getParticles() << endl;
        }
        en++;
    }
    events_f.close();
    return EXIT_SUCCESS;
}
