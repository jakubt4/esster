/*
 * generator.cpp
 *
 *  Created on: Feb 3, 2017
 *      Author: ary
 */

#include "../../headers/generator/generator.h"

typedef double Dabl;
typedef unsigned long long int ullong;
typedef unsigned int uint;

int seed();

struct random {
        ullong u, v, w;
        random(ullong j) :
                v(4101842887655102017LL), w(1) {
            u = j ^ v;
            int64();
            v = u;
            int64();
            w = v;
            int64();
        }
        inline ullong int64() {
            u = u * 2862933555777941757LL + 7046029254386353087LL;
            v ^= v >> 17;
            v ^= v << 31;
            v ^= v >> 8;
            w = 4294957665U * (w & 0xffffffff) + (w >> 32);
            ullong x = u ^ (u << 21);
            x ^= x >> 35;
            x ^= x << 4;
            return (x + v) ^ w;
        }
        inline Dabl dabl() {
            return 5.42101086242752217E-20 * int64();
        }
        inline uint int32() {
            return (uint) int64();
        }
};

struct random Gen(seed());

double rand_multiplicity();
double rand_phi();
double gauss(double mu);
double gen_fi(double fn[F_N], double vn[F_N]);


void generate(int num_of_events) {
    int multiplicity;
    int j;
    int k;

    double fi;
    double v_n0[F_N];
    double v_n[F_N];
    double f_n[F_N];

    cout << "Generate " << num_of_events << " events." << endl;
    create_folder(GEN_PATH);
    ofstream events_f;
    events_f.open(GEN_EVENTS_FILE_PATH.c_str());

    for (int i = 0; i < num_of_events; i++) {
        multiplicity = round(rand_multiplicity());

        for (j = 0; j < F_N; j++) {
            v_n0[j] = PARAMS[j][0] * (pow((75.0 / 2700.0), 2)) * (multiplicity ^ 2)
                    + (-PARAMS[j][1] * 75.0 / 2700.0 - PARAMS[j][0] * 125.0 / 27.0) * multiplicity + PARAMS[j][2]
                    + PARAMS[j][0] * (250.0 * 250.0 / 9.0) + PARAMS[j][1] * (250.0 / 3.0);
            //numbers comes from conversion centrality->multiplicity
            v_n[j] = gauss(v_n0[j]); //v_n randomly
            f_n[j] = rand_phi();             // psi_n randomly
        }

        for (k = 0; k < multiplicity; k++) {
            fi = gen_fi(f_n, v_n);
            events_f << i + 1 << setw(15) << multiplicity << setw(15) << fi << endl;
        }

        if ((i + 1) % 100 == 0) {
            cout << "Generated " << i + 1 << " events." << endl;
        }
    }
    cout << "DONE." << endl;
    events_f.close();
}

int seed() {
    srand(time(0));
    int s = rand();
    return s;
}

double rand_multiplicity() {
    return MULTIPLICITY_MIN + Gen.dabl() * (MULTIPLICITY_MAX - MULTIPLICITY_MIN);
}

double rand_phi() {
    return 2 * PI * Gen.dabl();
}

double gauss(double mu) { //ratio-of-uniforms method (NR)
    double u, v, x, y, q;
    do {
        u = Gen.dabl();
        v = 1.7156 * (Gen.dabl() - 0.5);
        x = u - 0.449871;
        y = abs(v) + 0.386595;
        q = pow(x, 2) + y * (0.19600 * y - 0.25472 * x);
    } while (q > 0.27597 && (q > 0.27846 || (pow(v, 2) > -4 * log(u) * pow(u, 2))));
    return mu + ((SIGMA * v) / u);
}

double gen_fi(double fn[F_N], double vn[F_N]) {

    int i = 0;
    double p, f; // p = p(phi)
                 // f: comparison function
    double x = 0;
    double fi = 0;

    //comparison function
    f = 1;
    for (i = 0; i < F_N; i++) {
        f = f + 2 * vn[i];
    }

    //rejection method
    do {
        x = Gen.dabl();
        p = 1;
        fi = rand_phi();
        for (i = 0; i < F_N; i++) {
            p = p + 2 * vn[i] * cos((i + 1) * (fi - fn[i]));
        }
    } while (x > p / f);

    return fi;
}
