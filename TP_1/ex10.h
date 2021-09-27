//
// Created by draia on 27/09/2021.
//

#ifndef Y2_C_EX10_H
#define Y2_C_EX10_H

float ** rotateRightMat(float **mat, int rows, int cols) { //we use the rows of the original matrix as the columns of the new one
	
    float **res = malloc(sizeof(float *) * cols);

    if (res == NULL) {
        MALLOC_FAIL
    }
    for (int i = 0; i < cols; ++i) {

        res[i] = malloc(rows * sizeof(float)); 
        if (res[i] == NULL) {
            MALLOC_FAIL
        }
    }
	// at this point, a mat(3, 2) should have given us a res(2,3)
	
	
	//TODO https://www.geeksforgeeks.org/rotate-matrix-right-k-times/
	for (int i = 0; i < cols; i++) {//3
        for (int j = 0; j < rows; j++) {//2
			printf("i=%d, j=%d, res[i][j]=%.2f, mat[j][i]=%.2f\n", i, j, res[i][j], mat[j][i]);
			res[i][j] = mat[j][i];
        }
    }
	
    return res;
}

#endif //Y2_C_EX10_H
