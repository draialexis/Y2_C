//
// Created by draia on 23/09/2021.
//

#ifndef Y2_C_TP1EX2_H
#define Y2_C_TP1EX2_H

int fib(int n) {
    if (n < 0) {
        printf("abort\n");
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
    if (n > 0) {
        int *arr = malloc(sizeof(int) * n);
        if (arr == NULL) {
            MALLOC_FAIL
        }
        int *arrStart = arr;
        int i;
        for (i = 0; i < n; i++) {
            *arr = fib(i);
            arr++;
        }
        return arrStart;
    } else {
        EMPTY_OR_NULL
        return NULL;
    }
}

#endif //Y2_C_TP1EX2_H