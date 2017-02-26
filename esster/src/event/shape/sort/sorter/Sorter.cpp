/*
 * Sorter.cpp
 *
 *  Created on: Feb 20, 2017
 *      Author: ary
 */

#include "Sorter.h"

Sorter::Sorter(std::list<Event> _events) {
    events = new Events(_events);
    int i = 1;
    int j = 1;
    Bin* bin = new Bin(i);
    for (Event event : events->get()) {
        event.setActualEventBin(i);
        bin->addEvent(event);
        if (j % eventsInBin == 0) {
            bins.push_back(*bin);
            bin = new Bin(i);
            cout << "Prepared BIN number " << i << endl;
            i++;
        }
        j++;
    }
    std::list<Event> newListOFEvents;
    for (Bin bin : bins) {
        std::list<Event> eventsInBin = bin.get();
        newListOFEvents.insert(newListOFEvents.end(), eventsInBin.begin(), eventsInBin.end());
    }
    events = new Events(newListOFEvents);
    cout << "Number of all bins is " << bins.size() << endl;
}

Events Sorter::sort() {
    ofstream events_f;
    BasePath bp;
    string path = LOADED_EVENTS_FILE_PATH + "_init";
    string str = bp.getBasePath() + path;
    cout << "Prepare init file..." << endl;
    events_f.open(str.c_str());
    int en = 1;
    for (Event e : events->get()) {
        events_f << en << setw(15) << e.getMultiplicity() << setw(15) << e.getSorter() << endl;
        en++;
    }
    events_f.close();
    cout << "OK" << endl;
    bool sort = true;
    int cyc = 1;
    cout << "Start sorting cycle..." << endl;
    while (sort) {
        cout << cyc << " cycle." << endl;
        sort = false;
        //avarageU()
        std::list<Event> newEventList;
        std::list<Event> listEvents = events->get();
        int listEventsSize = listEvents.size();
        std::vector<Event> vecEvent { listEvents.begin(), listEvents.end() };

#pragma omp parallel for simd
        for (int i = 0; i < listEventsSize; i++) {
            Event event = vecEvent[i];
            AvarageU avU(bins, event);
            long double resu = avU.compute_avarage_u();
            event.setSorter(resu);
            cout << i + 1 << ". event - computed with result - " << resu << endl;
            newEventList.push_back(event);
        }

        cout << "Sorting by actual avarage u for every event - cycle " << cyc << endl;
        events = new Events(newEventList);
        events->sort();
        int i = 1;
        int j = 1;
        std::list<Bin> newBins;
        Bin* bin = new Bin(i);
        for (Event event : events->get()) {
            if (event.getActualEventBin() != i) {
                event.setActualEventBin(i);
                sort = true;
            }
            bin->addEvent(event);
            if (j % eventsInBin == 0) {
                newBins.push_back(*bin);
                bin = new Bin(i);
                cout << "Prepared BIN number " << i << endl;
                i++;
            }
            j++;
        }
        bins = newBins;

        std::list<Event> newListOFEvents;
        for (Bin bin : bins) {
            std::list<Event> eventsInBin = bin.get();
            newListOFEvents.insert(newListOFEvents.end(), eventsInBin.begin(), eventsInBin.end());
        }
        events = new Events(newListOFEvents);

        if (cyc % 1 == 0) {
            string cyc_str = to_string(cyc);
            string path = LOADED_EVENTS_FILE_PATH + cyc_str;
            string str = bp.getBasePath() + path;
            ofstream events_f;
            events_f.open(str.c_str());
            int en = 1;
            for (Event e : events->get()) {
                events_f << en << setw(15) << e.getMultiplicity() << setw(15) << e.getSorter() << endl;
                en++;
            }
            events_f.close();
        }
        cyc++;
        if (cyc > 5000) {
            break;
        }
    }
    return *events;
}

Sorter::~Sorter() {
}

