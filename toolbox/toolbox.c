//
// Created by draia on 14/11/2021.
//

#include "toolbox.h"

//// add `srand(time(NULL));` to main

int randInRange(int min, int max) {
    if (min == max) {
        DEBUG
        printf("min == max...\n");
        return min;
    } else if (min > max) {
        DEBUG
        printf("min > max...\n");
        min = max;
        max = min;
    }
    return (rand() % max + 1 - min) + min;
}

char *mkStr(int n) {
    if (n < 1) {
        EMPTY_OR_NULL
        return NULL;
    }

    char *res = NULL;
    res = malloc(sizeof(char) * n);
    if (res == NULL) { MALLOC_FAIL }
    sprintf(res, "%c", '\0');
    return res;
}

int *mkIntArr(int n) {
    if (n < 1) {
        EMPTY_OR_NULL
        return NULL;
    }

    int *res = NULL;
    res = malloc(sizeof(int) * n);
    if (res == NULL) {
        MALLOC_FAIL
    }
    return res;
}

void showIntArr(int *T, int n) {
    if (T == NULL || n < 1) { EMPTY_OR_NULL }

    printf("[");
    for (int i = 0; i < n; ++i) {
        printf("%d", T[i]);
        if (i < n - 1) { printf(", "); }
    }
    printf("]\n");
}

void fillIntArrRdm(int *T, int n) {
    if (T == NULL || n < 1) {
        EMPTY_OR_NULL
        FAIL_OUT
    }

    for (int i = 0; i < n; ++i) {
        T[i] = (rand() % 21) - 10;
    }
}

int fiboRec(int n) {
    if (n < 0) {
        EMPTY_OR_NULL
        return -1;
    }

    if (n == 0 || n == 1) { return n; }
    else { return (fiboRec(n - 1) + fiboRec(n - 2)); }
}

int fiboImp(int n) {
    if (n < 0) {
        EMPTY_OR_NULL
        return -1;
    }

    if (n == 0 || n == 1) {
        return n;
    } else {
        int n_2 = 0;
        int n_1 = 1;
        int res;
        for (int i = 1; i < n; ++i) {
            res = n_1 + n_2;
            n_2 = n_1;
            n_1 = res;
        }
        return res;
    }
}

int *mkFiboArr(int n) {
    if (n < 1) {
        EMPTY_OR_NULL
        return NULL;
    }

    int *arr = mkIntArr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = fiboImp(i);
    }
    return arr;
}