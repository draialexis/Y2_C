//
// Created by draia on 10/10/2021.
//

#ifndef Y2_C_TOOLBOX_H
#define Y2_C_TOOLBOX_H

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

#endif //Y2_C_TOOLBOX_H
