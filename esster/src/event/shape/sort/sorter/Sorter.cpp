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
        event.setActualBin(i);
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

long double P_i_u(int bin_i, Bin bin) {

    long double multiplicityAllEvents = 0.0;
    long double multiplicityBinIEvents = 0.0;
    for (Event event : bin.get()) {
        multiplicityAllEvents = multiplicityAllEvents + event.getMultiplicity();
        int *angleBin = event.getAngleBin();
        multiplicityBinIEvents = multiplicityBinIEvents + angleBin[bin_i];
    }
    if (multiplicityBinIEvents == 0) {
        return 0.0;
    }
    return multiplicityBinIEvents / multiplicityAllEvents;
}

long double P_ni_u(Event event, Bin bin) {
    long double p = 1.0;
    int *angleBin = event.getAngleBin();
    for (int i = 0; i < 20; i++) {
        if (angleBin[i] == 0) {
            continue;
        }
        long double p_i_u = P_i_u(i, bin);
        if (p_i_u == 0) {
            continue;
        }
        long double power = angleBin[i];
        long double pow_r = pow(p_i_u, power);
        p = p * pow_r;
    }
    return p;
}

long double P_u_ni(Event event, Bin actualBin, std::list<Bin> bins) {
    long double numerator = 0.0;
    long double denominator = 0.0;

    numerator = P_ni_u(event, actualBin) / bins.size();
    for (Bin bin : bins) {
        denominator += P_ni_u(event, bin) / bins.size();
    }
    long double partial = numerator / denominator;
    return partial;
}

void Sorter::avarageU() {
    long double avarageU = 0.0;
    int i = 1;
    for (Event event : events->get()) {
        int bin_u = 1;
        for (Bin bin : bins) {
            long double p_u_ni = P_u_ni(event, bin, bins);
            avarageU = avarageU + (bin_u * p_u_ni);
            bin_u++;
        }
        cout << avarageU << endl;
        event.setSorter(avarageU);
        avarageU = 0.0;
        if (i % 10 == 0) {
            cout << "For " << i << " events computed u." << endl;
        }
        i++;
    }
}

Events Sorter::sort() {
    ofstream events_f;
    string path = LOADED_EVENTS_FILE_PATH + "_init";
    events_f.open(path.c_str());
    int en = 1;
    for (Event e : events->get()) {
        events_f << en << setw(15) << e.getMultiplicity() << setw(15) << e.getSorter() << endl;
        en++;
    }
    events_f.close();
    bool sort = true;
    int cyc = 1;
    while (sort) {
        sort = false;
        avarageU();
        events->sort();
        int i = 1;
        int j = 1;
        std::list<Bin> newBins;
        Bin* bin = new Bin(i);
        for (Event event : events->get()) {
            if (event.getActualBin() != i) {
                event.setActualBin(i);
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

        string cyc_str = to_string(cyc);
        string path = LOADED_EVENTS_FILE_PATH + cyc_str;
        ofstream events_f;
        events_f.open(path.c_str());
        int en = 1;
        for (Event e : events->get()) {
            events_f << en << setw(15) << e.getMultiplicity() << setw(15) << e.getSorter() << endl;
            en++;
        }
        events_f.close();
        cout << cyc << " cycle." << endl;
        cyc++;
        if (cyc > 10) {
            break;
        }
    }
    return *events;
}

Sorter::~Sorter() {
}

