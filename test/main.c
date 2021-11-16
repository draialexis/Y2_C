#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//================================================================

#define DEBUG printf("file %s; line %d\n", __FILE__, __LINE__);
#define FAIL_OUT DEBUG exit(EXIT_FAILURE);
#define MALLOC_FAIL printf("!_malloc failed_!\n"); FAIL_OUT
#define EMPTY_OR_NULL printf("this data structure doesn't have a positive int value as its size, or the pointer to it isn't valid\n");

//================================================================

void showIntArr(const int *arr, int n);

int *mkIntArr(int n);

void checkFopen(FILE *f, char *f_name);

char *mkStr(int n);

void freeFloatMat(float **mat, int rows);

float **mkFloatMat(int rows, int cols);

void showFloatMat(float **mat, int rows, int cols);

int *mkIntArr(int n) {
    if (n < 0) {
        EMPTY_OR_NULL
        FAIL_OUT
    }

    int *res = NULL;
    res = malloc(sizeof(int) * n);
    if (res == NULL) {
        MALLOC_FAIL
    }
    return res;
}

void showIntArr(const int *arr, int n) {
    if (arr == NULL || n < 0) {
        EMPTY_OR_NULL
        FAIL_OUT
    }

    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) { printf(", "); }
    }
    printf("]\n");
}

void checkFopen(FILE *f, char *f_name) {
    if (f == NULL) {
        EMPTY_OR_NULL
        printf("error while opening file %s\n", f_name);
        FAIL_OUT
    }
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

void freeFloatMat(float **mat, int rows) {
    if (rows < 1 || mat == NULL) {
        EMPTY_OR_NULL
    }
    for (int i = 0; i < rows; i++) {
        if (mat[i] != NULL) { free(mat[i]); }
    }
    free(mat);
}

float **mkFloatMat(int rows, int cols) {
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
        freeFloatMat(mat, rows);
        MALLOC_FAIL
    } else {
        return mat;
    }
}

void showFloatMat(float **mat, int rows, int cols) {
    if (rows < 1 || cols < 1 || mat == NULL) { EMPTY_OR_NULL }
    printf("[\n");
    for (int i = 0; i < rows; i++) {
        printf("[");
        for (int j = 0; j < cols; j++) {
//                printf("%+.2f ", *(*(mat + i) + j));
            printf("%f", mat[i][j]);
            if (j < cols - 1) { printf(", "); }
        }
        printf("]\n");
    }
    printf("]\n");
}

//================================================================

void LibereM(int **arr, int n);

int **CreerM(const int *arr, int n, int *sizes);

void AfficheM(const int **arr, int n, const int *sizes);

float **getCoordsFromFile(char *txt_f_name, int *n);

double perim(float **arr, int n);

void LibereM(int **arr, int n) {
    if (arr != NULL) {
        for (int i = 0; i < n; i++) {
            if (arr[i] != NULL) {
                free(arr[i]);
            }
        }
        free(arr);
    }
}

void AfficheM(const int **arr, int n, const int *sizes) {
    if (arr == NULL || n < 0 || sizes == NULL) {
        EMPTY_OR_NULL
        FAIL_OUT
    }

    printf("[\n");
    for (int j = 0; j < n; ++j) {
        showIntArr(arr[j], sizes[j]);
    }
    printf("]\n");
}

int **CreerM(const int *arr, int n, int *sizes) {
    if (arr == NULL || n < 0 || sizes == NULL) {
        EMPTY_OR_NULL
        FAIL_OUT
    }

    int count;
    int **res = NULL;
    res = malloc(sizeof(int *) * n);
    if (res == NULL) { MALLOC_FAIL }

    int hasFailed = 0;
    int i = 0;
    while (i < n && !hasFailed) {
        count = 0;
        res[i] = NULL;
        if (arr[i] < 0) {
            printf("only positive ints are allowed in T\n");
            FAIL_OUT
        }
        for (int j = 0; j < n; j++) {
//            printf("i=%d: %d mod %d = %d\n", i, arr[j], i + 1, (arr[j] % (i + 1)));
            if (arr[j] % (i + 1) != 0) {
//                printf("___counting\n");
                count++;
            }
        }
//        printf("====== i=%d: recording %d\n", i, count);
        sizes[i] = count;
        res[i] = malloc(sizeof(int) * count);
        if (res[i] == NULL) {
            hasFailed = 1;
        }
        i++;
    }

    if (hasFailed) {
        LibereM(res, n);
        MALLOC_FAIL
    }
    for (i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = j; k < n; k++) {
                if (arr[k] % (i + 1) != 0) {
                    res[i][j] = arr[k];
                    j++;
                }
            }
        }
    }

    return res;
}

float **getCoordsFromFile(char *txt_f_name, int *n) {
    FILE *f = NULL;
    f = fopen(txt_f_name, "r");
    checkFopen(f, txt_f_name);
    char c;

    *n = 1;
    while (!feof(f)) {
        c = (char) fgetc(f);
        if (c == '\n') {
            *n += 1;
        }
    }

    fseek(f, 0, SEEK_SET);

    char *tmp = mkStr(1);
    char *str = mkStr(1024);

    while (!feof(f)) {
        c = (char) fgetc(f);
        sprintf(tmp, "%c", c);
        strcat(str, tmp);
    }

    char *endPtr;

    float **res = mkFloatMat(*n, 2);
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < 2; j++) {
            res[i][j] = strtof(str, &endPtr);
            strcpy(str, endPtr);
        }
    }

    printf("\n");
    fclose(f);
    return res;
}

double perim(float **arr, int n) {
    double res = 0;
    double delta_x, delta_y;
    int next;
    for (int i = 0; i < n; i++) {
        if (i < n - 1) { next = i + 1; } else { next = 0; }
        delta_x = fabsf(arr[i][0] - arr[next][0]);
        delta_y = fabsf(arr[i][1] - arr[next][1]);
        res += sqrt(pow(delta_x, 2) + pow(delta_y, 2));
    }
    return res;
}

typedef union IntChar {
    int int_val;
    char bytes[4];
} IntChar;

IntChar createIntChar() {
    IntChar *x = NULL;
    x = (IntChar *) malloc(sizeof(IntChar));
    if (x == NULL) { MALLOC_FAIL }
    return *x;
}

void ModifieI(IntChar *x) {
    char tmp;

    tmp = x->bytes[0];
    x->bytes[0] = x->bytes[2];
    x->bytes[2] = tmp;

    tmp = x->bytes[1];
    x->bytes[1] = x->bytes[3];
    x->bytes[3] = tmp;
}

void Code(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        IntChar x = createIntChar();
        IntChar *xPtr = &x;
        int orig = arr[i];
        xPtr->int_val = orig;
        ModifieI(xPtr);
        arr[i] = xPtr->int_val;
//        free(xPtr);
    }
}

void Decode(int *arr, int n) {
    Code(arr, n);
}

int main() {

    //TODO compile and execute using:
    // gcc -Wall main.c -o main -lm
    // then :
    // ./main

    //// ex1_1)

    /*
     * T: [1, 2, 3, 4]
     * M: [
     * []
     * [1, 3]
     * [1, 2, 4]
     * [1, 2, 3]
     * ]
     */

    //// ex1_2)

    int n = 4;
    int *sizes = mkIntArr(n);

    int T[] = {4, 0, 3, 58};
    printf("=====EX1=====\nT: ");
    showIntArr(T, n);
    int **M = CreerM(T, n, sizes);

    //// ex1_3)

    printf("M: ");
    AfficheM((const int **) M, n, sizes);

    //// ex1_4)

    LibereM(M, n);
//    printf("M: ");
//    AfficheM(M, sizes, n);

/* will fail out */

    //// ex2_1)

    printf("=====EX2=====\nPolygone: ");

    int rows;
    float **C = getCoordsFromFile("test.txt", &rows);
    showFloatMat(C, rows, 2);

    //// ex2_2)

    printf("Perimetre = %f\n", perim(C, rows));

    //// ex3_1)

    int origVal = 13;
    IntChar X = createIntChar();
    IntChar *XPtr = &X;
    XPtr->int_val = origVal;
    printf("=====EX3=====\nval inside is %d\n", X.int_val);
    ModifieI(XPtr);
    printf("NOW val inside is %d\n", X.int_val);

    //// ex3_2)

    int v_n = 5;
    int *V = mkIntArr(v_n);
    for (int i = 0; i < v_n; i++) {
        V[i] = i * 3;
    }

    printf("original:\n");
    showIntArr(V, v_n);

    Code(V, v_n);
    printf("encoded:\n");
    showIntArr(V, v_n);

    //// ex3_3)

    Decode(V, v_n);
    printf("decoded:\n");
    showIntArr(V, v_n);

    return 0;
}