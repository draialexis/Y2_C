//
// Created by draia on 12/11/2021.
//

#include "../toolbox.h"

void myWc(FILE *f, int *l, int *w, int *c) {
    *w = 0;
    *c = 0;
    *l = 0;
    int ch;
    int isCharPrev;

    while (!feof(f)) {
        ch = fgetc(f);
        *c += 1;

        if (isalpha(ch)) {
            isCharPrev = 1;
        } else if (isspace(ch) && isCharPrev) {
            *w += 1;
            isCharPrev = 0;
        } else if (ch == '\n') {
            *l += 1;
            if (isCharPrev) {
                *w += 1;
            }
            isCharPrev = 0;
        }
    }
    printf("\n");
}