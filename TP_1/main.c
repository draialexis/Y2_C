#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 12

#include "ex1.h"
#include "ex2.h"
#include "ex3.h"
#include "ex5.h"
#include "ex6.h"
#include "ex7.h"

int main() {

    srand(time(NULL));

    printf("TP#1: initiated\n");
    ////
    printf("\nEX#1\n");

    int arr1[N];
    /*
     * unsigned short int arr[5] = {1, 2, 3, 4, 5};
     * short ints exist on 2 bytes rather than 4, typically. Incompatible pointer types.
     * unsigned int arr[5] = {1, 2, 3, 4, 5};
     * ints and unsigned ints take the same amount of memory each, and the function works as expected... it seems.
     */
    AfficheTab(arr1, N);

    ////
    printf("\nEX#2\n");

    int *arr2 = createFibArr(N);
    AfficheTab(arr2, N);
    free(arr2);

    ////
    printf("\nEX#3\n");

    variable("ivLVIl");
    /*
     * i: int
     * I: int pointer
     * v: void
     * V: void pointer
     * l: long
     * L: long pointer
     */

    //https://www.tutorialspoint.com/cprogramming/c_data_types.htm
    //Why do my longs take only 4 bytes..? I do have a 64bit OS... Is my compiler based on a 32bit OS?

    ////
    printf("\nEX#4\n");

    void *Z = malloc(10 * 4);
    if (Z != NULL) {
        int *X = Z;
        AfficheTab(X, 10);
        AfficheTab((int *) ((char *) X + 8), 8);
        free(X);
    }
    //"X+8" shifts the pointer by 2 spaces to the right (shouldn't it be 1, since pointers have size 8?)
    //the cast to a "char *" may be successful
    //the cast back to "int *" is successful, if the previous one was
    //the "8" in the second argument just ensures only 8 elements of the array will be printed
    //in short, some casting operations cancelled each other, we display 8 elements of the array...
    //...after shifting the array start by 2 spaces to the right. It's correct, but seems far-fetched

    ////
    printf("\nEX#5\n");

    int arr3[N] = {1, 3, 5, 6, 8, 2, 4, 7, 0, 10, 11, 9}; // isPermutation = 1
    int arr4[N] = {1, 3, 1, 6, 8, 2, 4, 7, 0, 10, 11, 9}; // isPermutation = 0 (double 1)
    int arr5[N] = {1, 9, 5, 6, 8, 2, 4, 7, 0, 10, 11, 9}; // isPermutation = 0 (missing 0)
    int arr6[N] = {86741, 56416, 41, 684, 6841, 68, 4, 6, 84, 684, 6, 6874}; // isPermutation = 0 (out of bounds)
    printf("\narr3: ");
    AfficheTab(arr3, N);
    printf("arr3 is a permutation: %s\n", isPermutation(arr3, N) ? "true" : "false");

    printf("\narr4: ");
    AfficheTab(arr4, N);
    printf("arr4 is a permutation: %s\n", isPermutation(arr4, N) ? "true" : "false");

    printf("\narr5: ");
    AfficheTab(arr5, N);
    printf("arr5 is a permutation: %s\n", isPermutation(arr5, N) ? "true" : "false");

    printf("\narr6: ");
    AfficheTab(arr6, N);
    printf("arr6 is a permutation: %s\n", isPermutation(arr6, N) ? "true" : "false");

    ////
    printf("\nEX#6\n");

    createRdmPerm(N);
    createRdmPerm(N);

    ////
    printf("\nEX#7\n");
    //error in instructions: example shows a string with 9 chars and an array with 8 ints

    char *T = malloc(sizeof(char) * N);
    if (T != NULL) {
        sprintf(T, "qwertyuiopas");//hardcoding this is a bad idea
        int *arr7 = createRdmPerm(N);
        //(!) array and string need to be same size. Crash if array is smaller..?
        printf("%s\n", T);
        printf("%s", permuteString(T, arr7));
        free(T);
    }
    return 0;
}
