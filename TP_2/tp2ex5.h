//
// Created by draia on 13/10/2021.
//

#ifndef Y2_C_TP2EX5_H
#define Y2_C_TP2EX5_H

#define BFR 512

void permuteSubString(char *str, int *perm, int n);

void permuteString(char *txt_f_name, char *res_f_name, int *perm, int n);

void encode(char *txt_f_name, char *perm_f_name);

void permuteSubString(char *str, int *perm, int n) {
    char *tmp = mkStr(n);
    for (int i = 0; i < n; i++) {
        tmp[perm[i]] = str[i];
    }
    for (int i = 0; i < n; i++) {
        str[i] = tmp[i];
    }
    free(tmp);
}

void permuteString(char *txt_f_name, char *res_f_name, int *perm, int n) {
    if (strlen(txt_f_name) > 0 && txt_f_name != NULL && perm != NULL) {
        FILE *encoded = fopen(res_f_name, "w+");
        checkFopen(encoded);
        FILE *orig = fopen(txt_f_name, "r");
        checkFopen(orig);

        int ctr;
        char *bfr = mkStr(n);

        do {
            ctr = (int) fread(bfr, sizeof(char), n, orig);
            if (ctr == n) {
                permuteSubString(bfr, perm, n);
            }
            fwrite(bfr, sizeof(char), ctr, encoded);
        } while (ctr != 0);
        fclose(encoded);
        fclose(orig);
    } else {
        EMPTY_OR_NULL
    }
}

int *findPerm(char *perm_f_name, int *nPtr) {
    FILE *fp_perm = fopen(perm_f_name, "r");
    checkFopen(fp_perm);

    char *txt_perm = (char *) malloc(sizeof(char) * BFR);
    sprintf(txt_perm, "%c", '\0');

    int tmpVal = 0;
    while (!feof(fp_perm)) {
        fscanf(fp_perm, "%d", &tmpVal);
        *nPtr += 1;
    }

    int *perm = mkIntArr(*nPtr);
    fseek(fp_perm, 0, SEEK_SET);

    for (int i = 0; i < *nPtr; i++) {
        fscanf(fp_perm, "%d", &tmpVal);
        perm[i] = tmpVal;
    }
    fclose(fp_perm);
    return perm;
}

void encode(char *txt_f_name, char *perm_f_name) {
    int n = 0;
    int *perm = findPerm(perm_f_name, &n);
    if (isPermutation(perm, n)) {
        permuteString(txt_f_name, "encoded.txt", perm, n);
    } else {
        printf("the sequence of numbers was evaluated as _not a permutation_\n");
    }
}

#endif //Y2_C_TP2EX5_H
