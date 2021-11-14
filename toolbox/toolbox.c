//
// Created by draia on 14/11/2021.
//

#include "toolbox.h"

int randInRange(int min, int max) {
    if (min == max) {
        DEBUG
        printf("min == max...\n");
        return min;
    } else if (min > max) {
        DEBUG
        printf("min > max...\n");
        min = max;
        max = min;
    }
    return (rand() % max + 1 - min) + min;
}

char *mkStr(int n) {
    if (n < 1) {
        EMPTY_OR_NULL
        return NULL;
    }

    char *res = NULL;
    res = malloc(sizeof(char) * n);
    if (res == NULL) { MALLOC_FAIL }
    sprintf(res, "%c", '\0');
    return res;
}

int *mkIntArr(int n) {
    if (n < 1) {
        EMPTY_OR_NULL
        return NULL;
    }

    int *res = NULL;
    res = malloc(sizeof(int) * n);
    if (res == NULL) {
        MALLOC_FAIL
    }
    return res;
}

void showIntArr(int *T, int n) {
    if (T == NULL || n < 1) { EMPTY_OR_NULL }

    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", T[i]);
        if (i < n - 1) { printf(", "); }
    }
    printf("]\n");
}

void fillIntArrRdm(int *T, int n, int min, int max) {
    if (T == NULL || n < 1) {
        EMPTY_OR_NULL
        FAIL_OUT
    }

    for (int i = 0; i < n; i++) {
        T[i] = randInRange(min, max);
    }
}

int fiboRec(int n) {
    if (n < 0) {
        EMPTY_OR_NULL
        return -1;
    }

    if (n == 0 || n == 1) { return n; }
    else { return (fiboRec(n - 1) + fiboRec(n - 2)); }
}

int fiboImp(int n) {
    if (n < 0) {
        EMPTY_OR_NULL
        return -1;
    }

    if (n == 0 || n == 1) {
        return n;
    } else {
        int n_2 = 0;
        int n_1 = 1;
        int res;
        for (int i = 1; i < n; i++) {
            res = n_1 + n_2;
            n_2 = n_1;
            n_1 = res;
        }
        return res;
    }
}

int *mkFiboArr(int n) {
    if (n < 1) {
        EMPTY_OR_NULL
        return NULL;
    }

    int *arr = mkIntArr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = fiboImp(i);
    }
    return arr;
}

int isPermutation(const int *arr, int n) {
    if (n < 1 || arr == NULL) {
        EMPTY_OR_NULL
        return 0;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            if (count != 1) {
                printf("element: %d wasn't found\n", i - 1);
                return 0;
            }
        }

        count = 0;

        for (int j = 0; j < n; j++) {
            if (arr[j] >= n || arr[j] < 0) {
                printf("element: %d out of bounds\n", arr[j]);
                return 0;
            }
            if (arr[j] == i) {
                count++;
                if (count > 1) {
                    printf("element: %d appears more than once\n", arr[j]);
                    return 0;
                }
            }
        }
    }
    return 1;
}

int *mkRdmPerm(int n) {
    if (n < 1) {
        EMPTY_OR_NULL
        return NULL;
    }

    int *arr = mkIntArr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }

    int tmp;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j == i) {
            j = rand() % n;
        }
        tmp = arr[j];
        arr[j] = arr[i];
        arr[i] = tmp;
    }
    return arr;
}

char *permuteString(const char *orig, const int *arr, int n) {
    if (strlen(orig) < 1 || orig == NULL || arr == NULL) {
        EMPTY_OR_NULL
        return NULL;
    }
    if (strlen(orig) != n) {
        DEBUG
        printf("the string and the permutation need to be of the same size\n");
        return NULL;
    }

    char *res = mkStr((int) strlen(orig));
    strcpy(res, orig);
    for (int i = 0; i < strlen(orig); i++) {
        res[arr[i]] = orig[i];
    }
    return res;
}

void showMat_f(float **mat, int rows, int cols) {
    if (rows < 1 || cols < 1 || mat == NULL) { EMPTY_OR_NULL }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
//                printf("%+.2f ", *(*(mat + i) + j));
            printf("%+.2f ", mat[i][j]);
        }
        printf("\n");
    }
}

float **mkMat_f(int rows, int cols) {
    if (rows < 1 || cols < 1) {
        EMPTY_OR_NULL
        FAIL_OUT
    }

    float **mat = NULL;
    mat = malloc(sizeof(float *) * rows);
    if (mat == NULL) { MALLOC_FAIL }

    int hasFailed = 0;
    for (int i = 0; i < rows; i++) {
        mat[i] = NULL;
        mat[i] = malloc(sizeof(float) * cols);
        if (mat[i] == NULL) { hasFailed = 1; }
    }

    if (hasFailed) {
        freeMat_f(mat, rows, cols);
        MALLOC_FAIL
    } else {
        return mat;
    }
}

#define GET_INPUT_FILL_MAT_F  printf("row: %d | col: %d | >", i + 1, j + 1); fgets(input, 20, stdin); x = strtof(input, &endptr); printf("%f\n", x);

void fillMat_f(float **mat, int rows, int cols) {
    if (rows < 1 || cols < 1 || mat == NULL) {
        EMPTY_OR_NULL
        FAIL_OUT
    }

    printf("Please select floats as coefficients for this matrix (rows = %d, columns = %d)\n"
           "_(!)_(Please use '.' instead of ',' with floats, or they WILL be trunked)\n", rows, cols);
    float x;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            char *input = mkStr(20);
            char *endptr;
            errno = 0;
            GET_INPUT_FILL_MAT_F
            while (x == 0 && (errno != 0 || endptr == input)) { GET_INPUT_FILL_MAT_F }
            mat[i][j] = x;
        }
    }
}

float **rotateRightMat_f(float **mat, int mrows, int mcols) {
    if (mrows < 1 || mcols < 1 || mat == NULL) {
        EMPTY_OR_NULL
        return NULL;
    }

    int cols = mrows;
    int rows = mcols;
    float **res = mkMat_f(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = cols - 1; j >= 0; j--) {
            res[i][cols - 1 - j] = mat[j][i];
        }
    }
    return res;
}

void freeMat_f(float **mat, int rows, int cols) {
    if (rows < 1 || cols < 1 || mat == NULL) {
        EMPTY_OR_NULL
    }
    for (int i = 0; i < rows; i++) {
        if (mat[i] != NULL) { free(mat[i]); }
    }
    free(mat);
}

int **pascalsTriangle(int n) {
    if (n < 1) {
        EMPTY_OR_NULL
        return NULL;
    }

    int **res = NULL;
    res = malloc(sizeof(int *) * n);
    if (res == NULL) {
        MALLOC_FAIL
    }

    int hasFailed = 0;
    for (int i = 0; i < n; i++) {
        res[i] = NULL;
        res[i] = malloc(sizeof(float) * i + 1);
        // at 0th iteration, create a size1 array, etc.
        if (res[i] == NULL) {
            hasFailed = 1;
        }

        if (hasFailed) {
            for (int j = 0; j < i; j++) {
                if (res[i] != NULL) {
                    free(res[i]);
                }
            }
            free(res);
            MALLOC_FAIL
        }

        for (int j = 0; j < i; j++) {
            if (j == 0 || j == i - 1) {
                res[i][j] = 1;
            } else {
                res[i][j] = (res[i - 1][j] + res[i - 1][j - 1]);
            }
            printf("%+5d", res[i][j]);
        }
        printf("\n");
    }
    return res;
}
