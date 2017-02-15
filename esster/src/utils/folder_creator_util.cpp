/*
 * folder_creator_util.cpp
 *
 *  Created on: Feb 3, 2017
 *      Author: ary
 */

#include <sys/stat.h> //mkdir
#include <sys/types.h>

#include "../../headers/utils/utils.h"

/**
 * Create folder if exist
 *
 * @param path - path of folder
 */
void create_folder(string path) {
    struct stat sb;

    if (stat(path.c_str(), &sb) != 0 && !S_ISDIR(sb.st_mode)) {
        mkdir(path.c_str(), 0777);
        cout << "Creation of " << path << endl;
    }
}

