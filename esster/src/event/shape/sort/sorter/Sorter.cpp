/*
 * Sorter.cpp
 *
 *  Created on: Feb 20, 2017
 *      Author: ary
 */

#include "Sorter.h"

Sorter::Sorter(std::list<Event> _events) {
    cout << "--------------------------------------------------" << endl;

    int i = 1;
    int j = 0;
    eventsInBin = _events.size() / 10;
    cout << "Events per bin = " << eventsInBin << endl;
    Bin* bin = new Bin();
    bin->setId(i);
    for (Event event : _events) {
        j++;
        event.setActualEventBin(i);
        bin->addEvent(event);
//        if (j % eventsInBin == 0) {
        if (j == eventsInBin) {
            bins.push_back(*bin);
            bin = new Bin();
            bin->setId(i);
            cout << "Prepared BIN number " << i << endl;
            i++;
            j = 0;
        }
    }
    _events.clear();
    cout << "Number of all bins is " << bins.size() << endl;
    cout << "--------------------------------------------------" << endl;

}

Events Sorter::sort() {
    ofstream events_f;
    BasePath bp;
    string path = LOADED_EVENTS_FILE_PATH + "_init";
    string str = bp.getBasePath() + path;

    events_f.open(str.c_str());
    int en = 0;
    for (Bin b : bins) {
        for (Event e : b.get()) {
            en++;
            events_f << en << setw(15) << e.getMultiplicity() << setw(15) << e.getSorter() << endl;
        }
    }
    events_f.close();

    bool sort = true;
    int cyc = 1;

    cout << "--------------------------------------------------" << endl;
    cout << "Start sorting cycle..." << endl;
    cout << endl;

    while (sort) {
        cout << cyc << " cycle." << endl;
        sort = false;

        int listBinsSize = bins.size();
        cout << listBinsSize << " - > BINS SIZE :::::::::" << endl;

        int iam, np;
        cout << "Prepare M for bins and angle bins.." << endl;
        clock_t begin = clock();
#pragma omp parallel
        {
#pragma omp for private(iam, np)
            for (int i = 0; i < listBinsSize; i++) {
//                np = omp_get_num_threads();
//                iam = omp_get_thread_num() + 1;
//                cout << "BIN " << i + 1 << " :: Thread = " << iam << " || out of " << np << endl;
                long double allEventsMultiplicity = 0.0;
                long double iAngleBinMultiplicity[20] = { 0 };
                Bin b = bins[i];
                for (Event e : b.get()) {
                    allEventsMultiplicity += e.getMultiplicity();
                    int *angleBins = e.getAngleBin();
                    for (int ii = 0; ii < 20; ii++) {
                        iAngleBinMultiplicity[ii] += angleBins[ii];
                    }
                }
                b.setMultiplicityOverMyEvents(allEventsMultiplicity);
                b.setMultiplicityOverAngleBins(iAngleBinMultiplicity);
                bins[i] = b;
            }
        }

        path = LOADED_EVENTS_FILE_PATH + "_init_prepared_M";
        str = bp.getBasePath() + path;

        events_f.open(str.c_str());
        int en = 0;
        for (Bin b : bins) {
            en++;
            events_f << en << setw(15) << b.getMultiplicityOverMyEvents();
            long double *gmoab = b.getMultiplicityOverAngleBins();
            for (int i = 0; i < 20; i++) {
                events_f << setw(15) << gmoab[i];
            }
            events_f << endl;
        }
        events_f.close();


        cout << "Preparing M done." << endl;
//        bs = new Bins(newBinsList);
//        cout << "Memory clearing.." << endl;
//        int vecBinSize = vecBin.size();
//        for (int i = 0; i < vecBinSize; i++) {
//            for (Event e : vecBin[i].get()) {
//                e.getParticles().clear();
//            }
//            vecBin[i].get().clear();
//        }
//        for (Bin b : newBinsList) {
//            for (Event e : b.get()) {
//                e.getParticles().clear();
//            }
//            b.get().clear();
//        }
//        newBinsList.clear();
//        cout << "Clearing done." << endl;
        cout << "--------------------------------------------------" << endl;

//        listBins = bs->get();
//        delete bs;
//        listBinsSize = listBins.size();
//        vecBin = {listBins.begin(), listBins.end()};
//        listBins.clear();

        cout << "Computing begin.." << endl;
        std::list<Event> evs;

        cout << listBinsSize << " - > BINS SIZE :::::::::" << endl;

#pragma omp parallel for schedule(dynamic)
        for (int i = 0; i < listBinsSize; i++) {
//            np = omp_get_num_threads();
//            iam = omp_get_thread_num() + 1;
//            cout << "Bin " << nob << " :: Thread = " << iam << " || out of " << np << endl;

            int noe = 0;
            for (Event e : bins[i].get()) {
                AvarageU avU;
                long double r = avU.compute_avarage_u(bins, e);
                e.setSorter(r);
                evs.push_back(e);
                e.getParticles().clear();
                iam = omp_get_thread_num() + 1;
                cout << "Thread -> " << iam << " :: Event -> " << noe + 1 << " :: Bin -> " << i + 1 << " :: Result -> "
                        << r << endl;
                noe++;
            }
            bins[i].get().clear();
        }
        bins.clear();

        cout << "--------------------------------------------------" << endl;
        cout << "Computing done." << endl;
        cout << "Sorting by actual average u for every event - cycle " << cyc << endl;


        Events* events = new Events(evs);
        events->sort();
        int i = 1;
        int j = 0;
//        std::vector<Bin> newBins;
        Bin* bin = new Bin();
        for (Event event : events->get()) {
            if (event.getActualEventBin() != i) {
                event.setActualEventBin(i);
                sort = true;
            }
            j++;
            bin->addEvent(event);
            if (j == eventsInBin) {
                bins.push_back(*bin);
                bin = new Bin();
                bin->setId(i);
                cout << "Prepared BIN number " << i << endl;
                i++;
                j = 0;
            }
        }
        delete events;

        for (Bin b : bins) {
            b.~Bin();
        }

//        if (cyc % 1 == 0) {
//            string cyc_str = to_string(cyc);
//            string path = LOADED_EVENTS_FILE_PATH + cyc_str;
//            string str = bp.getBasePath() + path;
//            ofstream events_f;
//            events_f.open(str.c_str());
//            int en = 1;
//            for (Event e : events->get()) {
//                events_f << en << setw(15) << e.getMultiplicity() << setw(15) << e.getSorter() << endl;
//                en++;
//            }
//            events_f.close();
//        }

        clock_t end = clock();
        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        cout << "End of " << cyc << ". cycle. :: TIME : " << elapsed_secs << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "--------------------------------------------------" << endl;

        cyc++;
    }
    std::list<Event> ev;
    return ev;
}

Sorter::~Sorter() {
    for (Bin b : bins) {
        for (Event e : b.get()) {
            e.getParticles().clear();
        }
        b.get().clear();
    }
    bins.clear();
}

