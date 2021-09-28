//
// Created by draia on 28/09/2021.
//

#ifndef Y2_C_TP1EX12_H
#define Y2_C_TP1EX12_H

int **pascalsTriangle(int n) {
    if (n > 0) {
        int **res = malloc(
                sizeof(int *) * n); // the first array is going to be an array of pointers to a single integer
        if (res == NULL) {
            MALLOC_FAIL
        }
        int hasFailed = 0;
        for (int i = 0; i < n; i++) {
            res[i] = malloc(sizeof(float) * i + 1);
            // at 0th iteration, create a size1 array, etc.
            if (res[i] == NULL) {
                hasFailed = 1;
            }
            if(hasFailed){
                for (int j = 0; j < i; ++j) {
                    if(res[i] != NULL){
                        free(res[i]);
                    }
                }
                free(res);
                MALLOC_FAIL
            }
            for (int j = 0; j < i; j++) {
                if (j == 0 || j == i - 1) {
                    res[i][j] = 1;
                } else {
                    res[i][j] = (res[i - 1][j] + res[i-1][j - 1]);
                }
                printf("%+5d", res[i][j]);
                //TODO create a printTriangle function?
            }
            printf("\n");
        }

        return res;
    } else {
        EMPTY_OR_NULL
        return NULL;
    }
}

#endif //Y2_C_TP1EX12_H
