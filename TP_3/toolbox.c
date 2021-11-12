//
// Created by draia on 12/11/2021.
//

#include "toolbox.h"

void showStrArr(str *arr, int n) {
    if (n > 0 && arr != NULL) {
        int i;
        printf("\n");
        for (i = 0; i < n; i++) {
            printf("%s", arr[i]);
            if (i < n - 1) {
                printf(",");
            } else {
                printf("\n");
            }
        }
    } else {
        EMPTY_OR_NULL
        FAIL_OUT
    }
}

void checkFopen(FILE *f, str f_name) {
    if (f == NULL) {
        EMPTY_OR_NULL
        printf("error while opening file %s\n", f_name);
        FAIL_OUT
    }
}

char *mkStr(int size) {
    char *res = NULL;
    res = malloc(sizeof(char) * size);
    if (res == NULL) {
        MALLOC_FAIL
    }
    sprintf(res, "%c", '\0');
    return res;
}