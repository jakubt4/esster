/*
 * folder_creator_util.cpp
 *
 *  Created on: Feb 3, 2017
 *      Author: ary
 */

#include <iostream>
#include <sys/stat.h> //mkdir

#include "../../headers/utils/utils.h"

void create_folder(string path, string name) {
    mkdir(GEN_PATH.c_str(), 0777);
    cout << "Creation of " << path << ": " << strerror(errno) << endl;
    cout << endl;
}

