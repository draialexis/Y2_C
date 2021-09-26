//
// Created by draia on 23/09/2021.
//

#ifndef TP1_PA_EX2_H
#define TP1_PA_EX2_H

int fib(int n) {
    if (n < 0) {
        printf("abort");
        return -1;
    } else if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return (fib(n - 1) + fib(n - 2));
    }
}

int *createFibArr(int n) {
    int *arr = malloc(sizeof(int) * n);
    if (arr == NULL) {
        printf("!_malloc failed_!\n");
        DEBUG
        exit(EXIT_FAILURE);
    }
    int *arrStart = arr;
    int i;
    for (i = 0; i < n; i++) {
        *arr = fib(i);
        arr++;
    }
    return arrStart;
}

#endif //TP1_PA_EX2_H