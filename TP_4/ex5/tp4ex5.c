//
// Created by draia on 14/11/2021.
//

#include "../toolbox.h"

int lessThanBis(int *a, int *b) {
    if (*a < *b) { return 1; } else { return -1; }
}

int greaterThanBis(int *a, int *b) {
    if (*a > *b) { return 1; } else { return -1; }
}

int evenAboveUnevenBis(int *a, int *b) {
    int remA = *a % 2;
    int remB = *b % 2;
    if (remA == 0 && remB != 0) { return 1; }
    if (remB == 0 && remA != 0) { return -1; }
    return 0;
}