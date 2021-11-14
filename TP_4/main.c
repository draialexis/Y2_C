//
// Created by draia on 13/11/2021.
//

#include "toolbox.h"
#include "ex3/tp4ex3.h"
#include "ex4/tp4ex4.h"
#include "ex5/tp4ex5.h"


int main() {
    //1)
    IntChar a;
    a.x = 13;// largest -> 00000000 00000000 00000000 00001101 <- smallest
    for (int i = 0; i < sizeof(int); ++i) {
        printf("\nbyte %d: "BYTE_TO_BINARY_PATTERN, i + 1, BYTE_TO_BINARY(a.bytes[i]));
    }

    //// least significant byte first => little-endianness
    printf("\n");
    //2)
    IntChar b;
    b.x = -5;
    for (int i = 0; i < sizeof(int); ++i) {
        printf("\nbyte %d: "BYTE_TO_BINARY_PATTERN, i + 1, BYTE_TO_BINARY(b.bytes[i]));
    }
    printf("\n");

    //// all the bits are inverted + 1... this looks like 2's complement
    /*
              | two's complement    | ones' complement    | sign/magnitude
       =======|=====================|=====================|====================
            5 | 0000 0000 0000 0101 | 0000 0000 0000 0101 | 0000 0000 0000 0101
           -5 | 1111 1111 1111 1011 | 1111 1111 1111 1010 | 1000 0000 0000 0101
     */

    //3)

    printIntAsHexBytes(a);
    printf("\n");

    return 0;
}