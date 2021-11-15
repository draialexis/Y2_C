//
// Created by draia on 14/11/2021.
//

#include "toolbox.h"

//=======================================TP1=================================================

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
                printf("not a permutation: element %d wasn't found\n", i - 1);
                return 0;
            }
        }

        count = 0;

        for (int j = 0; j < n; j++) {
            if (arr[j] >= n || arr[j] < 0) {
                printf("not a permutation: element %d out of bounds\n", arr[j]);
                return 0;
            }
            if (arr[j] == i) {
                count++;
                if (count > 1) {
                    printf("not a permutation: element %d appears more than once\n", arr[j]);
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

char *mkStrPerm(const char *orig, const int *arr, int n) {
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

List createList() {
    List *list = NULL;
    list = (List *) malloc(sizeof(List));
    if (list == NULL) { MALLOC_FAIL }
    list->nb_elements_ = 0;
    list->head_ = NULL;
    list->tail_ = NULL;
    return *list;
}

int listlen(List list) {
    return list.nb_elements_;
}

Element *mkElement(int val) {
    Element *res = NULL;
    res = (Element *) malloc(sizeof(Element));
    if (res == NULL) { MALLOC_FAIL }
    res->next_ = NULL;
    res->prev_ = NULL;
    res->val_ = val;
    return res;
}

int addToList(List *listPtr, int val, char mode) {
    if (listPtr == NULL) {
        EMPTY_OR_NULL
        FAIL_OUT
    }

    Element *element = mkElement(val);

    if (listPtr->head_ == NULL && listPtr->tail_ == NULL) {
        listPtr->head_ = element;
        listPtr->tail_ = element;
    } else if (listPtr->head_ == NULL || listPtr->tail_ == NULL) {
        EMPTY_OR_NULL
        printf("the list has a tail and no head, or vice versa...\n");
        return 0;
    } else {
        if (mode == 's') {
            listPtr->head_->prev_ = element;
            element->next_ = listPtr->head_;
            listPtr->head_ = element;
        } else {
            if (mode != 'e') { printf("couldn't understand mose; using ADD_TO_END by default"); }
            listPtr->tail_->next_ = element;
            element->prev_ = listPtr->tail_;
            listPtr->tail_ = element;
        }
    }

    listPtr->nb_elements_ += 1;
    return 1;
}

int endVal_list(List list) {
    return list.tail_->val_;
}

int startVal_list(List list) {
    return list.head_->val_;
}

void showList(List list) {
    int n = listlen(list);
    printf("list: {<x ");
    Element *currentPtr = list.head_;

    for (int i = 0; i < n; i++) {
        printf("%d", currentPtr->val_);
        currentPtr = currentPtr->next_;
        if (i < n - 1) { printf(" <-> "); }
    }
    printf(" x>}\n");
}

//=======================================TP2=================================================

void checkFopen(FILE *f, char *f_name) {
    if (f == NULL) {
        EMPTY_OR_NULL
        printf("error while opening file %s\n", f_name);
        FAIL_OUT
    }
}

void copyOrAppendFile(char *f1_name, char *f2_name, ...) {
    int c;

    FILE *f1 = NULL;
    f1 = fopen(f1_name, "r");
    checkFopen(f1, f1_name);
    FILE *f2 = NULL;

    va_list l;
    va_start(l, f2_name); //f2_name is irrelevant here
    int mode = va_arg(l, int);
    va_end(l);

    if (mode == 'a') {
        f2 = fopen(f2_name, "a+");
        printf("using 'APPEND' mode\n");
    } else if (mode == 'c') {
        f2 = fopen(f2_name, "w+");
        printf("using 'COPY' mode\n");
    } else {
        printf("couldn't understand instructions: using 'APPEND' mode\n");
        f2 = fopen(f2_name, "a+");
    }
    checkFopen(f2, f2_name);

    while (1) {
        if (feof(f1) || feof(f2)) { break; }
        c = fgetc(f1);
        if (c == EOF) { break; }
        fputc(c, f2);
    }
    fclose(f1);
    fclose(f2);
}

void showDiff(char *f1_name, char *f2_name) {
    int c1, c2;
    int char_num = 1;
    int line_num = 1;

    FILE *f1 = NULL;
    f1 = fopen(f1_name, "r");
    checkFopen(f1, f1_name);

    FILE *f2 = NULL;
    f2 = fopen(f2_name, "r");
    checkFopen(f2, f2_name);

    while (1) {
        c1 = fgetc(f1);
        c2 = fgetc(f2);
        if (c1 != c2) {
            printf("difference detected at line %d, char %d:\n%c != %c\n", line_num, char_num, c1, c2);
            break;
        }
        if (feof(f1) && feof(f2)) {
            printf("perfect copy\n");
            break;
        }
        if (c1 < 0 || c1 > 255 || c2 < 0 || c2 > 255) {
            printf("non-char detected at line %d, char %d\n", line_num, char_num);
            break;
        }
        if (c1 == '\n') {
            line_num++;
        }
        char_num++;
    }
    fclose(f1);
    fclose(f2);
}

void removeVowels(char *f_name) {
    int c;
    FILE *f = NULL;
    f = fopen(f_name, "r");
    checkFopen(f, f_name);
    char *b = mkStr(BUFFER_SIZE);

    while (1) {
        c = fgetc(f);
        if (feof(f)) {
            break;
        }
        if (c != 'a' && c != 'A' &&
            c != 'e' && c != 'E' &&
            c != 'i' && c != 'I' &&
            c != 'o' && c != 'O' &&
            c != 'u' && c != 'U' &&
            c != 'y' && c != 'Y') {
            sprintf(b + strlen(b), "%c", c);
        }
    }
    fclose(f);
    f = fopen(f_name, "w+");
    fputs(b, f);
    fclose(f);
}

void permSubStr(char *str, const int *perm, int n) {
    if (str[0] == '\0' || perm == NULL || n < 1) {
        EMPTY_OR_NULL
        FAIL_OUT
    }

    char *tmp = mkStr(n);
    for (int i = 0; i < n; i++) {
        tmp[perm[i]] = str[i];
    }
    for (int i = 0; i < n; i++) {
        str[i] = tmp[i];
    }
    free(tmp);
}

void permuteString(char *txt_f_name, char *res_f_name, const int *perm, int n) {
    if (strlen(txt_f_name) < 1 || txt_f_name == NULL || perm == NULL || n < 1) {
        EMPTY_OR_NULL
        FAIL_OUT
    }

    FILE *encoded = fopen(res_f_name, "w+");
    checkFopen(encoded, res_f_name);
    FILE *orig = fopen(txt_f_name, "r");
    checkFopen(orig, txt_f_name);
    int read_count;
    char *bfr = mkStr(n);

    do {
        read_count = (int) fread(bfr, sizeof(char), n, orig);
        if (read_count == n) {
            permSubStr(bfr, perm, n);
        }
        fwrite(bfr, sizeof(char), read_count, encoded);
    } while (read_count != 0);

    fclose(encoded);
    fclose(orig);
}

int *findPerm(char *perm_f_name, int *nPtr) {
    if (nPtr == NULL) {
        EMPTY_OR_NULL
        return NULL;
    }

    FILE *f_perm = NULL;
    f_perm = fopen(perm_f_name, "r");
    checkFopen(f_perm, perm_f_name);
    *nPtr = 0;

    int tmpVal = 0;
    while (!feof(f_perm)) {
        fscanf(f_perm, "%d", &tmpVal);
        *nPtr += 1;
    }

    int *perm = mkIntArr(*nPtr);
    fseek(f_perm, 0, SEEK_SET);

    for (int i = 0; i < *nPtr; i++) {
        fscanf(f_perm, "%d", &tmpVal);
        perm[i] = tmpVal;
    }

    fclose(f_perm);
    return perm;
}

void encode(char *txt_f_name, char *perm_f_name, char *res_f_name) {
    int n;
    int *perm = findPerm(perm_f_name, &n);
    if (isPermutation(perm, n)) {
        permuteString(txt_f_name, res_f_name, perm, n);
    } else {
        printf("the sequence of numbers was evaluated as _not a permutation_\n");
    }
}

void decode(char *txt_f_name, char *perm_f_name, char *res_f_name) {
    int n;
    int *perm = findPerm(perm_f_name, &n);
    int *deperm = mkIntArr(n);
    if (isPermutation(perm, n)) {
        for (int i = 0; i < n; i++) {
            deperm[perm[i]] = i;
        }
        permuteString(txt_f_name, res_f_name, deperm, n);
    } else {
        printf("the original sequence of numbers was evaluated as _not a permutation_\n");
    }
}

void caesar(char *txt_f_name, char *txt_res_name, int n) {
    FILE *orig = NULL;
    orig = fopen(txt_f_name, "r");
    checkFopen(orig, txt_f_name);
    FILE *enciphered = NULL;
    enciphered = fopen(txt_res_name, "w+");
    checkFopen(enciphered, txt_res_name);
    int c;

    if (n < 0 || n > 255) {
        printf("n: %d was changed to ", n);
        n = abs(n % 255);
        printf("n: %d\n", n);
    }

    while (1) {
        c = fgetc(orig);
        if (feof(orig)) { break; }
        if (c < 0 || c > 255 || fputc((c + n) % 255, enciphered) == EOF) {
            printf("non-char detected or fputc failure\n");
            FAIL_OUT
        }
    }
}

void writeListToFile(List l, char *txt_res_name) {
    int n = listlen(l);
    FILE *f = NULL;
    f = fopen(txt_res_name, "w+");
    checkFopen(f, txt_res_name);

    char *tmp = mkStr(32);//large enough for any int..?

    char *str = mkStr(BUFFER_SIZE);//large, for a long-ish list
    sprintf(str, "list: [%d] ", n);

    Element *currentPtr = l.head_;

    for (int i = 0; i < n; i++) {
        sprintf(tmp, "%d", currentPtr->val_);
        strcat(str, tmp);
        currentPtr = currentPtr->next_;
        if (i != n - 1) {
            strcat(str, ", ");
        }
    }
    fwrite(str, sizeof(char), strlen(str), f);
    fclose(f);
}

void getListFromFile(char *txt_f_name, List *lPtr) {
    if (lPtr == NULL) {
        EMPTY_OR_NULL
        FAIL_OUT
    }

    FILE *f = NULL;
    f = fopen(txt_f_name, "r");
    checkFopen(f, txt_f_name);

    fseek(f, 10, SEEK_SET);//start after the preambule
    char c;
    char *tmp = mkStr(32);

    while (!feof(f)) {
        c = (char) fgetc(f);
        if (c != ',') {
            strcat(tmp, &c);
        } else {
            fseek(f, 1, SEEK_CUR);// skip the comma and whitespace
            addToList(lPtr, strtol(tmp, NULL, 10), 'e');
            sprintf(tmp, "%c", '\0');
        }
    }
    addToList(lPtr, strtol(tmp, NULL, 10), 'e');
    fclose(f);
}

//=======================================TP3=================================================

char **getIntsFromStr(char *input, int *count) {
    if (input == NULL || input[0] == '\0' || count == NULL) {
        EMPTY_OR_NULL
        return NULL;
    }

    int isFirstDigitFound = 0;
    int isDigitPrev = 0;
    *count = 0;
    unsigned long long n = strlen(input);

    //find number of numbers in string
    for (int i = 0; i < n; i++) {
        char ch = input[i];
        if (isdigit(ch)) {
            if (!isFirstDigitFound) { isFirstDigitFound = 1; }
            if (i == n - 1) { *count += 1; }
            isDigitPrev = 1;
        } else {
            if (isDigitPrev) {
                *count += 1;
                isDigitPrev = 0;
            }
        }
    }

    isFirstDigitFound = 0; // !
    isDigitPrev = 0; // !
    int j = 0;
    int isMinus;

    char *tmp = mkStr(2);//...just one char, pretty much
    char *num = mkStr(64);//a number; will be appended on
    char **res = NULL; // an array of strings
    res = malloc(sizeof(char *) * *count);
    if (res == NULL) { MALLOC_FAIL }
    for (int i = 0; i < *count; i++) { res[i] = mkStr(64); }

    for (int i = 0; i < *count; i++) {
        while (j < n) {
            if (strcmp(num, "-") == 0) {
                isMinus = 1;
            } else {
                isMinus = 0;
            }

            char ch = input[j];

            if (isdigit(ch)) { //it's a digit, we add it to our num string in construction
                if (!isFirstDigitFound) { isFirstDigitFound = 1; }
                sprintf(tmp, "%c", ch);
                strcat(num, tmp);
                isDigitPrev = 1;//we note that we just saw a digit
                if (j == n - 1) { strcpy(res[i], num); }
                //it's the last char and it's an digit, we're ready to copy it to the array (no next digit to wait for)
            } else if (ch == '-') { //it's part of a digit too, but it's the beginning of one.
                if (isDigitPrev && !isMinus) {
                    // if we just saw part of an int, we can copy that into the array now
                    strcpy(res[i], num);
                    sprintf(num, "%c", ch);//and start our new int
                    isDigitPrev = 0;
                    j++;
                    break;
                    // we just copied a digit into res[i], we're ready for the next i loop
                }
                sprintf(num, "%c", ch);//and start our new int
                isDigitPrev = 0;
            } else { // ch is not a digit or a '-',
                if (isDigitPrev) {
                    //so the last digit that we just saw was the last part of an int that we can now copy
                    isDigitPrev = 0;
                    strcpy(res[i], num);
                    sprintf(num, "%c", '\0');
                    j++;
                    break;
                } //or we're going through our n-th non-int char
                sprintf(num, "%c", '\0'); //to purge our num in case of trailing '-'s
            }
            j++;
        }
    }
    return res;
}

void showStrArr(char **arr, int n) {
    if (n < 1 || arr == NULL) {
        EMPTY_OR_NULL
        FAIL_OUT
    }
    printf("showing an array of strings\n");
    int i;
    printf("[");
    for (i = 0; i < n; i++) {
        printf("%s", arr[i]);
        if (i < n - 1) {
            printf(",");
        } else {
            printf("]\n");
        }
    }
}

void myWc(char *f_name) {
    FILE *f = NULL;
    f = fopen(f_name, "r");
    checkFopen(f, f_name);

    int w = 0;
    int c = 0;
    int l = 0;
    int ch;
    int isCharPrev;

    while (!feof(f)) {
        ch = fgetc(f);
        c++;

        if (isalpha(ch)) {
            isCharPrev = 1;
        } else if (isspace(ch) && isCharPrev) {
            w++;
            isCharPrev = 0;
        } else if (ch == '\n') {
            l++;
            if (isCharPrev) {
                w++;
            }
            isCharPrev = 0;
        }
    }
    printf("  %d  %d %d %s\n", l, w, c, f_name);
}

double avg(int n, ...) {
    double a = 0;
    va_list l;
    va_start(l, n);
    for (int i = 0; i < n; i++) {
        a += va_arg(l, int);
    }
    va_end(l);
    a /= (float) n;
    return a;
}


//=======================================TP4=================================================

