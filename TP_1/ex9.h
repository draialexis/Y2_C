//
// Created by draia on 25/09/2021.
//

#ifndef Y2_C_EX9_H
#define Y2_C_EX9_H

#define GET_INPUT  printf("row: %d | col: %d | >", i + 1, j + 1); fgets(input, 15, stdin); x = strtof(input, &endptr); printf("%f\n", x);

void fillMat2d(float *mat, int rows, int cols) {
    printf("Please select floats as coefficients for this matrix (rows = %d, columns = %d)\n", rows, cols);
    float x;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            char input[16]; char *endptr;//arbitrarily decide how many chars can be used to make any x, for now

            GET_INPUT

            while (x == 0 && endptr == input) {
                GET_INPUT
            }

            *(mat + (i * rows) + j) = x;
        }
        mat++;
    }
}

void showMat2d(const float *mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%+02.2f ", *(mat + (i * rows) + j));
        }
        printf("\n");
        mat++;
    }
}

#endif //Y2_C_EX9_H
