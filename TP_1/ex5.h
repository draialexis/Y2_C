//
// Created by draia on 23/09/2021.
//

#ifndef TP1_PA_EX5_H
#define TP1_PA_EX5_H

int isPermutation(const int *arr, int n) {
    if (arr == NULL) { //make sure that the pointer does point to an address, exit otherwise
        printf("abort\n");
        return 0;
    }

    int count = 0; //we want to make sure that we don't get doubles, as per the instructions
    
	for (int i = 0; i < n; i++) {//so we start a loop to go through the entire array
        if (i > 0) {
            /*
             * once we've gone through the 0th iteration, and we start the 1th iteration, we can check to make sure that 0
             * does exist in the array. If not, we don't need to keep evaluating it, and we can get out.
             * And so on until the last value in the array (n-1)
             */
            if (count != 1) {
                printf("element: %d wasn't found\n", i - 1);
                return 0;
            }
        }
		
        count = 0; // we reset 'count' to 0 -- useless for the 0th iteration, but crucial for all the others

        for (int j = 0; j < n; j++) {
             // this second loop will enable us to stop on each item from the first loop and run a few tests
            if (arr[j] >= n || arr[j] < 0) {// is the item outside the interval (0 -- n-1)? If so, we're done
                printf("element: %d out of bounds\n", arr[j]);
                return 0;
            }
            if (arr[j] == i) {
                /*
                 * because of the nature of the "permutations" we are looking for, all possible indices (0 -- n-1) should
                 * exist as items in the arrays! That's pretty unusual, and maybe a bit confusing at first
                 *
                 * so we can check that 'i' does indeed exist as an item in the array
                 */
                count++;
                if (count > 1) { //we found 'i', that's great. We found 'i' again though, and that's bad. We're out
                    printf("element: %d appears more than once\n", arr[j]);
                    return 0;
                }
            }
        }
    }
    // if our program has escaped all the fail conditions, then the statement "arr is a permutation" is true
    return 1;
}

#endif //TP1_PA_EX5_H
