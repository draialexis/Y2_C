//
// Created by draia on 13/11/2021.
//

#include "toolbox.h"
#include "ex3/tp4ex3.h"
#include "ex4/tp4ex4.h"
#include "ex5/tp4ex5.h"

#define N 8

int main() {
    time_t t;
    srand((unsigned) time(&t));
    printf("\n==========ex1==========\n\n");
    IntChar a;
    a.x = 13;// largest -> 00000000 00000000 00000000 00001101 <- smallest
    for (int i = 0; i < sizeof(int); ++i) {
        printf("byte %d as bin: "BYTE_TO_BINARY_PATTERN"\n", i + 1, BYTE_TO_BINARY(a.bytes[i]));
    }

    //// least significant byte first => little-endianness
    printf("\n==========ex2==========\n\n");
    IntChar b;
    b.x = -5;
    for (int i = 0; i < sizeof(int); ++i) {
        printf("byte %d as bin: "BYTE_TO_BINARY_PATTERN"\n", i + 1, BYTE_TO_BINARY(b.bytes[i]));
    }

    //// all the bits are inverted + 1... this looks like 2's complement
    /*
              | two's complement    | ones' complement    | sign/magnitude
       =======|=====================|=====================|====================
            5 | 0000 0000 0000 0101 | 0000 0000 0000 0101 | 0000 0000 0000 0101
           -5 | 1111 1111 1111 1011 | 1111 1111 1111 1010 | 1000 0000 0000 0101
     */

    printf("\n==========ex3==========\n\n");
    IntChar c;
    c.x = 271;
    printIntAsHexBytes(c);

    printf("\n==========ex4==========\n\n");

    int res;

    for (int i = 0; i < 5; ++i) {
        for (int j = i; j < 5; ++j) {
            res = isACompThanB(&greaterThan, i, j);
            printf("%d > %d?: %d\n", i, j, res);
            res = isACompThanB(&lessThan, i, j);
            printf("%d < %d?: %d\n", i, j, res);
            res = isACompThanB(&evenAboveUneven, i, j);
            printf("%d 'more even than' %d?: %d\n", i, j, res);
        }
    }

    printf("\n==========ex5==========\n\n");
    int T[N];
    fillIntArrRdm(T, N);
    printf("unsorted: ");
    showIntArr(T, N);

    printf("sort with greaterThan: ");
    qsort(T, N, sizeof(int), &greaterThanBis);
    showIntArr(T, N);

    printf("sort with lessThan: ");
    qsort(T, N, sizeof(int), &lessThanBis);
    showIntArr(T, N);

    printf("sort with evenAboveUneven: ");
    qsort(T, N, sizeof(int), &evenAboveUnevenBis);
    showIntArr(T, N);

    return 0;
}