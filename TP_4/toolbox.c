//
// Created by draia on 13/11/2021.
//

#include "toolbox.h"

void showIntArr(int *T, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", T[i]);
        if (i < n - 1) { printf(", "); }
    }
    printf("]\n");
}

void fillIntArrRdm(int *T, int n) {
    for (int i = 0; i < n; i++) {
        T[i] = (rand() % 21) - 10;
    }
}