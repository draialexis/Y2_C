//
// Created by draia on 14/11/2021.
//

#ifndef Y2_C_TOOLBOX_H
#define Y2_C_TOOLBOX_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG printf("file %s; line %d\n", __FILE__, __LINE__);
#define FAIL_OUT DEBUG exit(EXIT_FAILURE);
#define MALLOC_FAIL printf("!_malloc failed_!\n"); FAIL_OUT
#define EMPTY_OR_NULL printf("this data structure doesn't have a positive integer value as its size, or the pointer to it isn't valid\n");

int randInRange(int min, int max);

char *mkStr(int n);

int *mkIntArr(int n);

void showIntArr(int *T, int n);

void fillIntArrRdm(int *T, int n);

int fiboRec(int n);

int fiboImp(int n);

int *mkFiboArr(int n);

#endif //Y2_C_TOOLBOX_H
