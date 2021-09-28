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
        float **res = createMat_f(rows, cols);
        if (res == NULL) {
            return NULL;
        }
        //copy lines of res into an aux, but backwards
        //then replace that line of res by aux
        //then free aux
        for (int i = 0; i < rows; i++) {
            for (int j = cols - 1; j >= 0; j--) { //going backwards
                res[i][cols - 1 - j] = mat[j][i];
            }
        }
        showMat_f(res, rows, cols);
        return res;
    } else {
        EMPTY_OR_NULL
        return NULL;
    }
}

#endif //Y2_C_TP1EX10_H
