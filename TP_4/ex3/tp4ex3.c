//
// Created by draia on 13/11/2021.
//

#include "../toolbox.h"

void printIntAsHexBytes(IntChar x) {
    for (int i = 0; i < sizeof(int); i++) {
        printf("byte %d as hex: %02hhx\n", i + 1, x.bytes[i]);
    }
}

