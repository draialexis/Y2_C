//
// Created by draia on 14/11/2021.
//

#include "../toolbox.h"

int lessThan(int a, int b) {
    if (a < b) { return 1; } else { return -1; }
}

int greaterThan(int a, int b) {
    if (a > b) { return 1; } else { return -1; }
}

int evenAboveUneven(int a, int b) {
    int remA = a % 2;
    int remB = b % 2;
    if (remA == 0 && remB != 0) { return 1; }
    if (remB == 0 && remA != 0) { return -1; }
    return 0;
}

int isACompThanB(compPtr comp, int a, int b) {
    int res;
    if (a == b) { res = 0; }
    else { res = comp(a, b); }
    return res;
}

/*
int extract(int *T, int n, int (*comp)(int, int)) {
    int i, m = 0;
    for (i = 1; i < n; i++) {
        if (comp(T[m], T[i]) > 0) {
            m = i;
        }
    }
    return m;
}

int max(int a, int b) {
    if (a < b) { return +1; } else { return -1; }
}

int min(int a, int b) {
    if (a > b) { return +1; } else { return -1; }
}
*/

//int A = extract(T, n, &max);
//// va extraire l’indice du maximum.
//Int B = extract(T, n, &min)
//// va extraire l’indice du minimum.