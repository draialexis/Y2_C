#include "toolbox.h"
#include "ex1/tp3ex1.h"
#include "ex2/tp3ex2.h"
#include "ex3/tp3ex3.h"

int main(int argc, char *argv[]) {
    //1)
    if (argc == 3) {
        str f_name = argv[1];
        str clip = argv[2];
        wri2k(f_name, clip);
    } else {
        //2)
        str nums = "3-H-23 a-b67 89 _5-56f-hui5";
        int n;
        str *arr = getIntsFromStr(nums, &n);
        printf("size: %d", n);
        showStrArr(arr, n);
        //3)
        int w, c, l;
        str f_name = "shakey.txt";
        myWc(f_name, &l, &w, &c);
        printf("%d %d %d %s", l, w, c, f_name);
    }
    return 0;
}