//
// Created by draia on 27/09/2021.
//

#ifndef Y2_C_TP1EX11_H
#define Y2_C_TP1EX11_H

void freeMat(float **mat, int rows, int cols) {
    if (rows > 0 && cols > 0 && mat != NULL) {
        for(int i = 0; i < rows; i++) {
            if(mat[i] != NULL){
                free(mat[i]);
            }
        }
        free(mat);
    } else {
        EMPTY_OR_NULL
    }

}

#endif //Y2_C_TP1EX11_H
