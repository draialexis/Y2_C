//
// Created by draia on 13/11/2021.
//

#ifndef Y2_C_TOOLBOX_H
#define Y2_C_TOOLBOX_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0')

typedef union IntChar {
    int x;
    char bytes[4];
} IntChar;

typedef int (*compPtr)(int, int);

void showIntArr(int *T, int n);

void fillIntArrRdm(int *T, int n);

#endif //Y2_C_TOOLBOX_H
