/*
 * tests.cpp
 *
 *  Created on: Feb 25, 2017
 *      Author: ary
 */

#include "src/event/shape/sort/utils/files/FilesWorker.h"
#include "src/event/shape/sort/utils/files/FileConstants.h"
#include "src/event/shape/sort/utils/files/BasePath.h"

using namespace std;

int main() {
    ofstream events_f;
    BasePath bp;
    string str = bp.getBasePath() + TEST;
    events_f.open(str.c_str());
    string echoDash = "echo -e \"-----------------------------------\"";
    string echoStart = "echo -e \"Start testing\"";
    string echoDon = "echo -e \"Testing DONE\"";
    events_f << "#!/bin/bash" << endl;
    events_f << echoDash.c_str() << endl;
    events_f << echoDash.c_str() << endl;
    events_f << echoStart.c_str() << endl;
    events_f << echoDash.c_str() << endl;
    events_f << "./test_event" << endl;
    events_f << echoDash.c_str() << endl;
    events_f << "./test_piu" << endl;
    events_f << echoDash.c_str() << endl;
    events_f << "./test_pniu" << endl;
    events_f << echoDash.c_str() << endl;
    events_f << "./test_puni" << endl;
    events_f << echoDash.c_str() << endl;
    events_f << "./test_avarageu" << endl;
    events_f << echoDash.c_str() << endl;
    events_f << echoDash.c_str() << endl;
    events_f << echoDon.c_str() << endl;
    events_f << echoDash.c_str() << endl;
    events_f.close();
    return 0;
}
