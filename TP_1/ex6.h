//
// Created by draia on 23/09/2021.
//

#ifndef TP1_PA_EX6_H
#define TP1_PA_EX6_H

int *createRdmPerm(int n) {
    int *arr = malloc(sizeof(int) * n);
    if (arr == NULL) {
        printf("malloc failed\n");
        return NULL;
    }
    int *arrStart = arr;
    int i;
    for (i = 0; i < n; i++) {
        *arr = i;
        arr++;
    }
    printf("before: ");

    arr = arrStart;

    AfficheTab(arr, n);

    int tmp;
    int j = 0;
    for (i = 0; i < n; i++) { // could actually be < n, just like you don't need to move 54 cards to shuffle a pack
        while (j == i) {
            j = rand() % n; //would inevitably shuffle even a size-2 array... or would it?
        }
        tmp = arr[j]; //is there a way to do that with pointers? what are the trade-offs?
        arr[j] = arr[i];
        arr[i] = tmp;
    }
    printf("after: ");

    arr = arrStart;

    AfficheTab(arr, n);
    printf("array is a permutation: %s\n", isPermutation(arr, n) ? "true" : "false");

    return arr;
}

#endif //TP1_PA_EX6_H
