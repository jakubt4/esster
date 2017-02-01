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
#include <string>

#include "src/headers/generator.h"
#include "src/headers/sort.h"

int main(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-gen")) {
            generate();
        } else if (strcmp(argv[i], "-sort")) {
            sort();
        }
    }
    puts("Hello World!!!");
    return EXIT_SUCCESS;
}
