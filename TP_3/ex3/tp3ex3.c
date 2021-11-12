//
// Created by draia on 12/11/2021.
//

#include "../toolbox.h"

void myWc(str f_name, int *l, int *w, int *c) {
    *w = 0;
    *c = 0;
    *l = 0;
    int ch;
    int isCharPrev;
    FILE *f = fopen(f_name, "r");
    checkFopen(f);

    while (1) {
        ch = fgetc(f);
        c += 1;

        if (isalnum(ch)) {
            isCharPrev = 1;
        } else if (!isalnum(ch) && isCharPrev) {
            w += 1;
            isCharPrev = 0;
        }

        if (ch == '\n') {
            l += 1;
        }

        if (feof(f)) {
            break;
        }
    }
}