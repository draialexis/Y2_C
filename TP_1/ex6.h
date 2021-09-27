//
// Created by draia on 23/09/2021.
//

#ifndef TP1_PA_EX6_H
#define TP1_PA_EX6_H

// it was tempting to "divide and rule", create a modular ensemble of small, simple functions
// but the instructions said "_une_ fonction", so here we go

int * createRdmPerm(int n) {
    int * arr = malloc(sizeof(int) * n); // we have the size of the array as a parameter, not a constant. Perfect for malloc

    if (arr == NULL) { // this is just in case the memory allocation fails. If that happens, we have to get out
        MALLOC_FAIL
    }

    int * arrStart = arr;
    // this is to keep track of the start of the array. at this point in the program,
    // "arr" contains (the pointer to / the address of) the first item in the array.
    for (int i = 0; i < n; i++) {
        // here is a way to navigate an array without the [] notation
        *arr = i; // "*arr" is the value contained in the pointer "arr" ; at "i = 0", arr is the first item in the array
        arr++;
        /*
         * we basically said arr[i] = i, which is weird, but makes sense for these "permutations"
         * by using an increment, we make sure we keep going through the array. Without [] notation, 'i' is
         * just a counter to make sure we don't go out of bounds
         * remember that an array is guaranteed to have its items in succession ; they are immediate neighbours, in the memory
         *
         * NB: I actually think we could use the [] notation, though... maybe check it out
         */
    }
    printf("before: ");

    arr = arrStart; // we've iterated all the way through the array already, so we rewind to the start

    AfficheTab(arr, n); // we're done making a simple, sorted array with values from 0 to n-1

    // now let's shuffle it

    /*
     * in the main, do make sure to include:
     * ...
     * #include <time.h>
     * ...
     * int main() {
     * srand(time(NULL));
     * ...
     * }
     */
    int tmp; //this temporary variable will be useful for swapping items in the array, without having to create a new array
    int j = 0;
    for (int i = 0; i < n; i++) { // could actually be much smaller than 'n', just like you don't need to move 54 cards to shuffle a pack
        while (j == i) {// we want to avoid 'randoming' a 'j' that is the same as our initial 'i'
            j = rand() % n; //that's how we use 'rand'. This would inevitably shuffle even a size-2 array... or would it? hmm
        }
        tmp = arr[j]; // we place the item at index 'j' (!= i) into our temporary variable
        arr[j] = arr[i]; // we put the item at index 'i' into the box for the item at index 'j'
        arr[i] = tmp; // we take back the item that came from index 'j', and put it into the box at index 'i'
    }
    printf("after: ");// we jubilate.

    AfficheTab(arr, n);

    // here we can call our function from ex5 to chack the validity of our result
    printf("array is a permutation: %s\n", isPermutation(arr, n) ? "true" : "false");

    return arr;
}

#endif //TP1_PA_EX6_H
