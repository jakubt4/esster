/*
 * EventsGenerator.cpp
 *
 *  Created on: Feb 14, 2017
 *      Author: ary
 */

#include "../header/EventsGenerator.h"

EventsGenerator::EventsGenerator(int _numOfEvents) {
    numOfEvents = _numOfEvents;
    srand(time(NULL));
}

std::list<Event> EventsGenerator::generate() {
    cout << "Generating events..." << endl;
    for (int i = 0; i < numOfEvents; i++) {
        prepareEvent();
        if ((i + 1) % 1000 == 0) {
            cout << "Generated : " << i + 1 << " events." << endl;
        }
    }
    cout << "Events generated." << endl;
    cout << "--------------------------------" << endl;

    BasePath bp;
    string str = bp.getBasePath();
    create_folder(str + GEN_PATH);
    ofstream events_f;
    ofstream particles_f;
    string evnts = str + GEN_PARTICLES_FILE_PATH;
    str = str + GEN_EVENTS_FILE_PATH;

    events_f.open(str.c_str());
    particles_f.open(evnts.c_str());
    int en = 1;

    cout << "Writing events to files..." << endl;
    for (Event e : events) {
        if (en % 1000 == 0) {
            cout << "Wrote to files: " << en << " events." << endl;
        }
        events_f << en << setw(15) << e.getMultiplicity() << endl;
        for (Particle p : e.getParticles()) {
            particles_f << en << setw(15) << p.getAngle() << endl;
        }
        e.getParticles().clear();
        en++;
    }
    events_f.close();
    particles_f.close();
    cout << "Events wrote to files." << endl;
    cout << "--------------------------------" << endl;
    events.clear();
    return events;
}

int seed() {
    srand(time(0));
    int s = rand();
    return s;
}

struct random gen(seed());

double generateMultiplicity(int numOfEvents) {
    int max = sqrt(numOfEvents);
    int min = numOfEvents / 10;
    if (min == 0) {
        min = 1;
    }
    return min + gen.doub() * (max - min);
}

double gauss(double mu) {
    double u, v, x, y, q;
    do {
        u = gen.doub();
        v = 1.7156 * (gen.doub() - 0.5);
        x = u - 0.449871;
        y = abs(v) + 0.386595;
        q = pow(x, 2) + y * (0.19600 * y - 0.25472 * x); //SQR(x) should return x*x
    } while (q > 0.27597 && (q > 0.27846 || pow(v, 2) > -4 * log(u) * pow(u, 2)));
    return mu + 0.025 * v / u;
}

double phi() {
    return 2 * 3.14159265358979323846 * gen.doub();
}

double run() {
    return gen.doub();
}

double gen_fi(double fn[2], double vn[2]) {

    int i = 0;
    double p, f;
    double x = 0;
    double fi = 0;

    f = 1;
    for (i = 0; i < 2; i++) {
        f = f + 2 * vn[i];
    }

    do {
        x = run();
        p = 1;
        fi = phi();
        for (i = 0; i < 2; i++) {
            p = p + 2 * vn[i] * cos((i + 1) * (fi - fn[i]));
        }
    } while (x > p / f);

    return fi;
}

void EventsGenerator::prepareEvent() {
    Event e;
    int M = round(generateMultiplicity(numOfEvents));
    e.setMultiplicity(M);
    for (int j = 0; j < 2; j++) {
        vn0[j] = params[j][0] * (pow((75.0 / 2700.0), 2)) * M * M
                + (-params[j][1] * 75.0 / 2700.0 - params[j][0] * 125.0 / 27.0) * M + params[j][2]
                + params[j][0] * (250.0 * 250.0 / 9.0) + params[j][1] * (250.0 / 3.0);
        vn[j] = gauss(vn0[j]);
        fn[j] = phi();
    }

    for (int k = 0; k < M; k++) {
        fi = gen_fi(fn, vn);
        Particle p(fi);
        e.addParticle(p);
    }
    events.push_back(e);
}

EventsGenerator::~EventsGenerator() {
    for (Event e : events) {
        e.getParticles().clear();
    }
    events.clear();
}
