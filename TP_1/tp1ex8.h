//
// Created by draia on 25/09/2021.
//

#ifndef Y2_C_TP1EX8_H
#define Y2_C_TP1EX8_H

float **createMat(int rows, int cols) {

    float **mat = malloc(sizeof(float *) * rows);

    if (mat == NULL) {
        MALLOC_FAIL
    }
    for (int i = 0; i < rows; i++) {

        mat[i] = malloc(cols * sizeof(float));

        if (mat[i] == NULL) {
            MALLOC_FAIL
        }
    }
    return mat;
}

#endif //Y2_C_TP1EX8_H
