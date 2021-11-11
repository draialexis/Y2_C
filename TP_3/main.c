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
        str nums = "3-H-23 a-b67 89 _5-56f-hui5";
        int n;
        str *arr = decoupage(nums, &n);
        printf("size: %d", n);
        showStrArr(arr, n);
    }
    return 0;
}