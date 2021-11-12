#include "toolbox.h"
#include "ex1/tp3ex1.h"
#include "ex2/tp3ex2.h"
#include "ex3/tp3ex3.h"
#include "ex4/tp3ex4.h"

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
        FILE *f = fopen(f_name, "r");
        checkFopen(f, f_name);
        myWc(f, &l, &w, &c);
        printf("  %d  %d %d %s\n", l, w, c, f_name);
        //4)
        printf("%f\n", avg(2, 5, 4));
        //// if there is a non-int in our params, the program compiles, and executes, but the behavior is erroneous
        //// if n (the size) is greater than the number of other params, behavior is erroneous
        //// if n is less, some params get ignored of course
        //5)
        printf("%f\n", MAX(45.5, 65.0));
        printf("%d\n", MAX(45, 65));
        printf("%d\n", MAX(151, MAX(45, 65)));
        //// we can compare elements of various types in each call
        //// but only elements of the same type within one call
////        ({
////            typeof(151) _a = (151);
////            typeof(({
////                typeof(45) _a = (45);
////                typeof(65) _b = (65);
////                _a > _b ? _a : _b;
////            })) _b = (({
////                typeof(45) _a = (45);
////                typeof(65) _b = (65);
////                _a > _b ? _a : _b;
////            }));
////            _a > _b ? _a : _b;
////        });
////    }

        return 0;
    }
}