//
// Created by draia on 10/10/2021.
//

#ifndef Y2_C_TOOLBOX_H
#define Y2_C_TOOLBOX_H

typedef char *str;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>

#define DEBUG printf("file %s; line %d\n", __FILE__, __LINE__);
#define FAIL_OUT DEBUG exit(EXIT_FAILURE);
#define MALLOC_FAIL printf("!_malloc failed_!\n"); FAIL_OUT
#define EMPTY_OR_NULL printf("this data structure doesn't have a positive integer value as its size, or the pointer to it isn't valid\n");

void showStrArr(str *arr, int n);

void checkFopen(FILE *f, str f_name);

char *mkStr(int size);

#endif //Y2_C_TOOLBOX_H
