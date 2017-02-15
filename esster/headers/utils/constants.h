/*
 * constants.h
 *
 *  Created on: Feb 3, 2017
 *      Author: ary
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include<string>
#include "file_types.h"

using namespace std;

const string GEN_PATH = "/home/ary/generated_files/";
const string GEN_EVENTS = "generated_events";
const string GEN_EVENTS_FILE_PATH = GEN_PATH + GEN_EVENTS + TXT;

const int NUM_OF_EVENTS = 10000000;
const int MULTIPLICITY_MIN = 300;
const int MULTIPLICITY_MAX = 3000;
const int F_N = 2;
const int TT = 400;

const double SIGMA = 0.025;
const double PARAMS[F_N][3] = { { 0, -0.000006, -0.00018 }, { -0.000092, 0.00811, 0.0418 } };
const double PI = 3.14159265358979323846;
const double EU = 2.71828182846;


#endif /* CONSTANTS_H_ */
