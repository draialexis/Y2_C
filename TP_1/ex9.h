//
// Created by draia on 25/09/2021.
//

#ifndef Y2_C_EX9_H
#define Y2_C_EX9_H

void fillMat2d(float *mat, int rows, int cols) {
    printf("Please select floats as coefficients for this matrix (i = %d, j = %d)\n", rows, cols);
    float x;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("> ");
            scanf("%f", x);
            *(mat + (i * rows) + j) = x;
        }
    }
}

void showMat2d(const float *matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%+04f ", *(matrix + (i * rows) + j));
        }
        printf("\n");
    }
}

#endif //Y2_C_EX9_H
