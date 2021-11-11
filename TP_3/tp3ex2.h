
//
// Created by draia on 27/10/2021.
//

#ifndef Y2_C_TP3EX2_H
#define Y2_C_TP3EX2_H


str *decoupage(str input, int *count) {
    if (input == NULL || strcmp(input, "") == 0 || count == NULL) {
        EMPTY_OR_NULL
    }
    int isFirstDigitFound = 0;
    int isDigitPrev = 0;
    *count = 0;
    unsigned long long n = strlen(input);

    for (int i = 0; i < n; i++) {
        char ch = input[i];
        if (isdigit(ch)) {
            if (!isFirstDigitFound) {
                isFirstDigitFound = 1;
            }
            if (i == n - 1) {
                *count += 1;
            }
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
    str tmp = mkStr(64);
    str num = mkStr(64);
    str *res = NULL; // an array of strings
    res = malloc(sizeof(str) * *count);
    if (res == NULL) {
        MALLOC_FAIL
    }
    for (int i = 0; i < *count; ++i) {
        res[i] = mkStr(64);
    }
    int j = 0;

    for (int i = 0; i < *count; ++i) {
        while (j < n) {
            int isMinus = strcmp(num, "-") == 0 ? 1 : 0;
            char ch = input[j];
            if (isdigit(ch)) { //it's a digit, we add it to our num string in construction
                if (!isFirstDigitFound) {
                    isFirstDigitFound = 1;
                }
                sprintf(tmp, "%c", ch);
                strcat(num, tmp);
                isDigitPrev = 1;//we note that we just saw a digit
                if (j == n - 1) {
                    //it's the last char and it's an digit, we're ready to copy it to the array (no next digit to wait for)
                    strcpy(res[i], num);
                    printf("lres[%d]=%s\n", i, res[i]);
                }
            } else if (ch == '-') { //it's part of a digit too, but it's the beginning of one.
                if (isDigitPrev && !isMinus) {
                    // if we just saw part of an int, we can copy that into the array now
                    strcpy(res[i], num);
                    printf("-res[%d]=%s\n", i, res[i]);
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
                    printf("nres[%d]=%s\n", i, res[i]);
                    sprintf(num, "%c", '\0');
                    j++;
                    break;
                } //or we're going through our n-th non-int char
                sprintf(num, "%c", '\0'); //to purge our num in case of trailing '-'s
            }
            j++;
        }
    }
//    isDigitPrev = 0;
    return res;
}


#endif //Y2_C_TP3EX2_H