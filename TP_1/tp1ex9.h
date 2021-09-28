//
// Created by draia on 25/09/2021.
//

#ifndef Y2_C_TP1EX9_H
#define Y2_C_TP1EX9_H

#define GET_INPUT  printf("row: %d | col: %d | >", i + 1, j + 1); fgets(input, 15, stdin); x = strtof(input, &endptr); printf("%f\n", x);

void fillMat_f(float **mat, int rows, int cols) {
    if (rows > 0 && cols > 0 && mat != NULL) {
        printf("Please select floats as coefficients for this matrix (rows = %d, columns = %d)\n"
               "_(!)_(Please use '.' instead of ',' with floats, or they WILL be trunked)\n", rows, cols);
        float x;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                char input[16];
                char *endptr;//arbitrarily decide how many chars can be used to make any x, for now
                errno = 0;
                GET_INPUT

                while (x == 0 &&
                       (errno != 0 || endptr == input)) { //input and endptr are the same if the input is invalid
                    //except maybe not always, but errno may be set to EINVAL then -- so we check for that too
                    GET_INPUT
                }
                *(*(mat + i) + j) = x;
//            mat[i][j] = x;
            }
        }
        showMat_f(mat, rows, cols);
    } else {
        EMPTY_OR_NULL
    }
}

#endif //Y2_C_TP1EX9_H
