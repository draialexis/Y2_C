#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

typedef char *str;

#include "toolbox.h"
#include "tp3ex1.h"
#include "tp3ex2.h"

int main(int argc, char *argv[]) {
    if (argc == 3) {
        str f_name = argv[1];
        str clip = argv[2];
        wri2k(f_name, clip);
    } else {
        str nums = "456 3 -59 11";
//        int *arr = decoupage(nums);
    }
    return 0;
}