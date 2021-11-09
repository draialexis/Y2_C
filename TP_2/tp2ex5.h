//
// Created by draia on 13/10/2021.
//

#ifndef Y2_C_TP2EX5_H
#define Y2_C_TP2EX5_H

#define BFR 512

char *permuteString(char *str, int *perm, int n) {
    // more user input validation? seems rough in C, esp. given the _cahier des charges_
    if (strlen(str) > 0 && str != NULL && perm != NULL) {
        char *res = mkStr((int) strlen(str));

        sprintf(res, "%s", str); //initializing the string

        int e_counter = 0;
        int i_counter = n;
        while (i_counter == n && e_counter < strlen(str) - n) {
            i_counter = 0;
            for (int i = 0; i < n; i++) {
                res[perm[i] + e_counter] = str[i + e_counter];
//                printf("res[%d] = %c / str[%d] = %c\n",
//                       perm[i] + e_counter, res[perm[i] + e_counter], i + e_counter, str[i + e_counter]);
                i_counter++;
            }
            e_counter += n;
        }
        return res;
    } else {
        EMPTY_OR_NULL
        return NULL;
    }
}

int isPermutation(const int *arr, int n) {
    if (n > 0 && arr != NULL) {//make sure that the pointer does point to an address, check for size0, exit otherwise

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
    } else {
        EMPTY_OR_NULL
        return 0;
    }
}

char *encode(char *txt_f_name, char *perm_f_name) {
    FILE *fp_txt = fopen(txt_f_name, "r");
    checkFopen(fp_txt);
    FILE *fp_perm = fopen(perm_f_name, "r");
    checkFopen(fp_perm);

    int c;
    char *txt = mkStr(BFR);
    int *perm = mkIntArr(BFR);

    while (1) {
        c = fgetc(fp_txt);
        if (feof(fp_txt)) {
            break;
        }
        sprintf(txt + strlen(txt), "%c", c);
    }

    printf("%s\n", txt);
    char *txt_perm = (char *) malloc(sizeof(char) * BFR);
    sprintf(txt_perm, "%c", '\0');

    int n = 0;
    while (1) {
        c = fgetc(fp_perm);
        if (feof(fp_perm)) {
            break;
        }
        // vomitting face emoji : couldn't manage to extract a string from the file,
        // so extracted chars, converted to string, then converted to int
        sprintf(txt_perm, "%c", c);
        perm[n] = atoi(txt_perm);
        n++;
    }

    for (int i = 0; i < n; ++i) {
        printf("%d", perm[i]);
    }
    printf("\n");

    fclose(fp_txt);
    fclose(fp_perm);
    if (isPermutation(perm, n)) {
        return permuteString(txt, perm, n);
    } else {
        return "the sequence of numbers was evaluated as _not a permutation_";
    }
}

#endif //Y2_C_TP2EX5_H
