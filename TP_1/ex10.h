//
// Created by draia on 27/09/2021.
//

#ifndef Y2_C_EX10_H
#define Y2_C_EX10_H

float ** rotateRightMat(float **mat, int mrows, int mcols) { //we use the rows of the original matrix as the columns of the new one
	int cols = mrows;
	int rows = mcols;
    float **res = malloc(sizeof(float *) * rows);
	int counter = 1;

    if (res == NULL) {
        MALLOC_FAIL
    }
    for (int i = 0; i < rows; i++) {
        res[i] = malloc(cols * sizeof(float)); 
        if (res[i] == NULL) {
            MALLOC_FAIL
        }
		for (int j = 0; j < cols; j++) {
			res[i][j] = counter++;
		}
    }
	// at this point, a mat(3, 2) should have given us a res(2,3)
	/*
	for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%+.2f ", *(*(res + i) + j));
        }
        printf("\n");
    }
	*/
	
	
	//TODO https://www.geeksforgeeks.org/rotate-matrix-right-k-times/
	
	for (int i = 0; i < rows; i++) {//3
        for (int j = 0; j < cols; j++) {//2
			//*(*(res + i) + j) = *(*(mat + j) + i);
			res[i][j] = mat[j][i];
			//printf("i=%d, j=%d, res[i][j]=%.2f, mat[j][i]=%.2f\n", i, j, res[i][j], mat[j][i]);
		}
    }
    return res;
}

#endif //Y2_C_EX10_H
