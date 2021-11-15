//
// Created by draia on 10/10/2021.
//

#ifndef Y2_C_TOOLBOX_H
#define Y2_C_TOOLBOX_H

#define DEBUG printf("file %s; line %d\n", __FILE__, __LINE__);
#define FAIL_OUT exit(EXIT_FAILURE);
#define MALLOC_FAIL printf("!_malloc failed_!\n"); DEBUG; FAIL_OUT;
#define EMPTY_OR_NULL printf("this data structure doesn't have a positive integer value as its size, or the pointer to it isn't valid\n"); DEBUG;


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

void checkFopen(FILE *fileName) {
    if (fileName == NULL) {
        EMPTY_OR_NULL
        perror("error while opening file");
        FAIL_OUT
    }
}

int isPermutation(const int *arr, int n) {
    if (n > 0 && arr != NULL) {

        int count = 0;

        for (int i = 0; i < n; i++) {
            if (i > 0) {
                if (count != 1) {
                    printf("element: %d wasn't found\n", i - 1);
                    return 0;
                }
            }

            count = 0;

            for (int j = 0; j < n; j++) {
                if (arr[j] >= n || arr[j] < 0) {
                    printf("element: %d out of bounds\n", arr[j]);
                    return 0;
                }
                if (arr[j] == i) {
                    count++;
                    if (count > 1) {
                        printf("element: %d appears more than once\n", arr[j]);
                        return 0;
                    }
                }
            }
        }
        return 1;
    } else {
        EMPTY_OR_NULL
        return 0;
    }
}

#endif //Y2_C_TOOLBOX_H
