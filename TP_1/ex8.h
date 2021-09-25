//
// Created by draia on 25/09/2021.
//

#ifndef Y2_C_EX8_H
#define Y2_C_EX8_H

float *createMat2d(int rows, int cols) {
    float *mat = malloc(sizeof(float) * rows * cols);
    if (mat == NULL) {
        printf("!_malloc failed_!\n");
        DEBUG
        return NULL;
    }
    return mat;
}

#endif //Y2_C_EX8_H
