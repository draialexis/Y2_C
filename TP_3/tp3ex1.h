
//
// Created by draia on 27/10/2021.
//

#ifndef Y2_C_TP3EX1_H
#define Y2_C_TP3EX1_H

void wri2k(str f_name, str clip);

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

#endif //Y2_C_TP3EX1_H