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
        res[i] = malloc(sizeof(float) * cols); 
        if (res[i] == NULL) {
            MALLOC_FAIL
        }
		for (int j = 0; j < cols; j++) {
			res[i][j] = counter++;
		}
    }
	// at this point, a mat(3, 2) should have given us a res(2,3)

	
	
	//TODO https://www.geeksforgeeks.org/rotate-matrix-right-k-times/
	
	for (int i = 0; i < rows; i++) {
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
		float * aux = malloc(sizeof(float) * cols);
			if(aux==NULL){
				MALLOC_FAIL
			}
        for (int j = cols - 1; j >= 0; j--) { //going backwards
				aux[cols - 1 - j] = res[i][j];
			}
		for (int j = 0; j < cols; j++){
			//replace
			res[i][j] = aux[j];
		}//free
		free(aux);
    }
    return res;
}

#endif //Y2_C_EX10_H
