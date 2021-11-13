//
// Created by draia on 13/11/2021.
//

#include "toolbox.h"
#include "ex1/tp4ex1.h"

int main() {
    IntBin a;
    a.x = 13;//00000000 00000000 00000000 00001101
    for (int i = 0; i < 4; ++i) {
        printf("%u", a.bytes[i]);//TODO work it out
    }
    return 0;
}