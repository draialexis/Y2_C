#include "toolbox.h"
#include "ex1/tp3ex1.h"
#include "ex2/tp3ex2.h"
#include "ex3/tp3ex3.h"

int main(int argc, char *argv[]) {
    if (argc == 3) {
        str f_name = argv[1];
        str clip = argv[2];
        wri2k(f_name, clip);
    } else {
        str nums = "3-H-23 a-b67 89 _5-56f-hui5";
        int n;
        str *arr = getIntsFromStr(nums, &n);
        printf("size: %d", n);
        showStrArr(arr, n);
    }
    return 0;
}