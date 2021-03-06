#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>

#define N 12
#define ROWS 3
#define COLS 4
#define DEBUG printf("file %s; line %d\n", __FILE__, __LINE__);
#define FAIL_OUT exit(EXIT_FAILURE);
#define MALLOC_FAIL printf("!_malloc failed_!\n"); DEBUG; FAIL_OUT;
#define EMPTY_OR_NULL printf("this data structure doesn't have a positive integer value as its size, or the pointer to it isn't valid\n"); DEBUG;

#include "tp1ex1.h"
#include "tp1ex2.h"
#include "tp1ex3.h"
#include "tp1ex5.h"
#include "tp1ex6.h"
#include "tp1ex7.h"
#include "tp1ex8.h"
#include "tp1ex9.h"
#include "tp1ex10.h"
#include "tp1ex11.h"
#include "tp1ex12.h"
#include "tp1ex13.h"

int main() {

    srand(time(NULL));

    printf("TP_1: initiated\n");
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

    variable("ivLVIlGg");
    /*
     * i: int
     * I: int pointer
     * v: void
     * V: void pointer
     * l: long int
     * L: long int pointer
     * g: long long int
     * G: long long int pointer
     */

    //https://www.tutorialspoint.com/cprogramming/c_data_types.htm
    //Why do my longs take only 4 bytes...? I do have a 64bit OS... Is my IDE compiler based on a 32bit OS?
    //My local Ubuntu does say 8 bytes... huh

    ////
    printf("\nEX#4\n");

    void *Z = malloc(10 * 4);
    if (Z != NULL) {
        int *X = Z;
        AfficheTab(X, 10);
        AfficheTab((int *) ((char *) X + 8), 8);
        free(X);
    } else {
        MALLOC_FAIL
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
    // redundancy between the 2, may make the program faster, should run the stats
    // TODO check stats?
    int arr5[N] = {1, 9, 5, 6, 8, 2, 4, 7, 0, 10, 11, 9}; // isPermutation = 0 (missing 3)
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

    int *arr7 = createRdmPerm(N);
    free(arr7);
    int *arr8 = createRdmPerm(N);
    free(arr8);

    ////
    printf("\nEX#7\n");
    //error in instructions: example shows a string with 9 chars and an array with 8 ints

    char *str = malloc(sizeof(char) * 13);
    if (str != NULL) {
        sprintf(str, "abcdefghijkl");//hard-coding this is probably a bad idea
        int *arr9 = createRdmPerm(N);
        //(!) array and string need to be same size. Crash or bug if array is smaller...?
        printf("%s\n", str);
        printf("%s\n", permuteString(str, arr9));
        free(arr9);
        free(str);
    } else {
        MALLOC_FAIL
    }

    ////
    printf("\nEX#8 & 9\n");
    float **mat1 = createMat_f(ROWS, COLS);
    fillMat_f(mat1, ROWS, COLS);

    ////
    printf("\nEX#10\n");
    float **mat2 = rotateRightMat(mat1, ROWS, COLS);
    ////
    printf("\nEX#11\n");
    freeMat(mat1, ROWS, COLS);
    freeMat(mat2, COLS, ROWS);
// TODO how can we see whether memory was freed?

    ////
    printf("\nEX#12\n");
    int **pTri = pascalsTriangle(N);
    //free(pTri); //TODO needs a proper freeTriangle function to get all the memory back, cf. freeMat

    ////
    printf("\nEX#13\n");
    List list1 = createList();
    List *list1_ptr = &list1;

    printf("\nlistlen(list1) = %d\n", listlen(list1));

    addToStart_list(list1_ptr, 7);
    showList(list1);

    addToEnd_list(list1_ptr, 5);
    showList(list1);

    addToStart_list(list1_ptr, 4);
    showList(list1);

    printf("\nlistlen(list1) = %d\n", listlen(list1));

    printf("start value = %d\n", startVal_list(list1));
    printf("end value = %d\n", endVal_list(list1));

    //free(list1); //TODO needs a proper freeList function to get all the memory back, cf. freeMat

    return 0;
}
