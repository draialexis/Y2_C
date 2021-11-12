//
// Created by draia on 12/11/2021.
//

#include "../toolbox.h"

void wri2k(str f_name, str clip) {
    FILE *fh = fopen(f_name, "w+");
    checkFopen(fh);
    for (int i = 0; i < 2000; i++) {
        fputs(clip, fh);
        usleep((rand() % 100) + 1); //make the program sleep for 1 to 100 milsec
    }
    fclose(fh);
}

// when launching the same program twice at the same time, both strings
// get written down
// it seems 2000 * the size of the largest of the two strings is allocated to be
// written in the file, the smallest is written 2000 times, and whatever space there was
// left was used to print a few instances of the largest string