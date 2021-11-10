//
// Created by draia on 10/11/2021.
//

#ifndef Y2_C_TP2EX6_H
#define Y2_C_TP2EX6_H

void decode(char *txt_f_name, char *perm_f_name) {

    int n = 0;
    int *deperm = mkIntArr(n);
    int *perm = findPerm(perm_f_name, &n);
    if (isPermutation(perm, n)) {
        for (int i = 0; i < n; i++) {
            deperm[perm[i]] = i;
        }
        permuteString(txt_f_name, "decoded.txt", deperm, n);
    } else {
        printf("the sequence of numbers was evaluated as _not a permutation_\n");
    }
}

#endif //Y2_C_TP2EX6_H
