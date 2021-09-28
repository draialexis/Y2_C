//
// Created by draia on 25/09/2021.
//

#ifndef Y2_C_TP1EX8_H
#define Y2_C_TP1EX8_H

void showMat_f(float **mat, int rows, int cols) {
    if (rows > 0 && cols > 0 && mat != NULL) {
        printf("matrix:\n");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%+.2f ", *(*(mat + i) + j));
//            printf("%+.2f ", mat[i][j]);
            }
            printf("\n");
        }
    } else {
        EMPTY_OR_NULL
    }
}

float **createMat_f(int rows, int cols) {
    if (rows > 0 && cols > 0) {
        float **mat = malloc(sizeof(float *) * rows);

        if (mat == NULL) {
            MALLOC_FAIL
        }
        int hasFailed = 0;
        for (int i = 0; i < rows; i++) {

            mat[i] = malloc(cols * sizeof(float));

            if (mat[i] == NULL) {
                hasFailed = 1;
            }
        }
        if (hasFailed) {
            for (int i = 0; i < rows; i++) {
                if (mat[i] != NULL) {
                    free(mat[i]);
                }
            }
            free(mat);
            MALLOC_FAIL
        }
        showMat_f(mat, rows, cols);
        return mat;
    } else {
        EMPTY_OR_NULL
        return NULL;
    }
}

#endif //Y2_C_TP1EX8_H
