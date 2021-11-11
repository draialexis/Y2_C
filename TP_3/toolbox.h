//
// Created by draia on 10/10/2021.
//

#ifndef Y2_C_TOOLBOX_H
#define Y2_C_TOOLBOX_H

#define DEBUG printf("file %s; line %d\n", __FILE__, __LINE__);
#define FAIL_OUT exit(EXIT_FAILURE);
#define MALLOC_FAIL printf("!_malloc failed_!\n"); DEBUG FAIL_OUT
#define EMPTY_OR_NULL printf("this data structure doesn't have a positive integer value as its size, or the pointer to it isn't valid\n"); DEBUG FAIL_OUT;

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
    }
}

void checkFopen(FILE *fileName) {
    if (fileName == NULL) {
        EMPTY_OR_NULL
        perror("error while opening file");
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

int *mkIntArr(int size) {
    int *res = NULL;
    res = malloc(sizeof(int) * size);
    if (res == NULL) {
        MALLOC_FAIL
    }
    return res;
}

#endif //Y2_C_TOOLBOX_H
