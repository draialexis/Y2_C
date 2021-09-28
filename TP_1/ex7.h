//
// Created by draia on 23/09/2021.
//

#ifndef Y2_C_EX7_H
#define Y2_C_EX7_H

char *permuteString(char *str, int *arr) {
    char *res = malloc(sizeof(char) * strlen(str));
    if (res == NULL) {
        MALLOC_FAIL
    }

    sprintf(res, "%s", str); //initializing the string

    for (int i = 0; i < strlen(str); i++) {
        res[arr[i]] = str[i];
        printf("res[%d] = %c / str[%d] = %c\n", arr[i], res[arr[i]], i, str[i]);
    }
    return res;
}

#endif //Y2_C_EX7_H
