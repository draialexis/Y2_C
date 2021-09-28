//
// Created by draia on 27/09/2021.
//

#ifndef Y2_C_TP1EX10_H
#define Y2_C_TP1EX10_H

float **rotateRightMat(float **mat, int mrows, int mcols) {
    if (mrows > 0 && mcols > 0 && mat != NULL) {
        //we use the rows/cols of the original matrix as the cols/rows of the new one
        int cols = mrows;
        int rows = mcols;
        float **res = malloc(sizeof(float *) * rows);

        if (res == NULL) {
            MALLOC_FAIL
        }

        // at this point, a mat(3, 2) should have given us a res(2,3)

        //TODO https://www.geeksforgeeks.org/rotate-matrix-right-k-times/

        for (int i = 0; i < rows; i++) {
            res[i] = malloc(sizeof(float) * cols);
            if (res[i] == NULL) {
                MALLOC_FAIL
            }
            for (int j = 0; j < cols; j++) {
                //*(*(res + i) + j) = *(*(mat + j) + i);
                res[i][j] = mat[j][i];
                //printf("i=%d, j=%d, res[i][j]=%.2f, mat[j][i]=%.2f\n", i, j, res[i][j], mat[j][i]);
            }
        }
        //copy lines of res into an aux, but backwards
        //then replace that line of res by aux
        //then free aux
        for (int i = 0; i < rows; i++) {
            float *aux = malloc(sizeof(float) * cols);
            if (aux == NULL) {
                MALLOC_FAIL
            }
            for (int j = cols - 1; j >= 0; j--) { //going backwards
                aux[cols - 1 - j] = res[i][j];
            }
            for (int j = 0; j < cols; j++) {
                //replace
                res[i][j] = aux[j];
            }//free
            free(aux);
        }
        showMat_f(res, rows, cols);
        return res;
    } else {
        EMPTY_OR_NULL
        return NULL;
    }
}

#endif //Y2_C_TP1EX10_H
