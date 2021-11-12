//
// Created by draia on 12/11/2021.
//

#include "../toolbox.h"

double avg(int n, ...) {
    double a = 0;
    va_list l;
    va_start(l, n);
    for (int i = 0; i < n; i++) {
        a += va_arg(l, int);
    }
    va_end(l);
    a /= (float) n;
    return a;
}

