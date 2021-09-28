//
// Created by draia on 28/09/2021.
//

#ifndef Y2_C_TP1EX12_H
#define Y2_C_TP1EX12_H

int **pascalsTriangle(int n) {
    int **res = malloc(sizeof(int *) * n); // the first array is going to be an array of pointers to a single integer
    if (res == NULL) {
        MALLOC_FAIL
    }
    /*for (int i = 0; i < rows; i++) {
        res[i] = malloc(sizeof(float) * cols);
        if (res[i] == NULL) {
            MALLOC_FAIL
        }
        for (int j = 0; j < cols; j++) {
            res[i][j] = counter++;
        }
    }*/
}

#endif //Y2_C_TP1EX12_H
