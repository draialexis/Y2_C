//
// Created by draia on 23/09/2021.
//

#ifndef TP1_PA_EX7_H
#define TP1_PA_EX7_H

char *permuteString(char *str, const int *arr) {
    char *res = malloc(sizeof(char) * strlen(str));
    if (res == NULL) {
        printf("!_malloc failed_!\n");
        DEBUG
        return NULL;
    }

    for (int i = 0; i < strlen(str); ++i) {
//        printf("res[%d] = %c / str[%i] = %c\n", arr[i], res[arr[i]], i, str[i]);
        res[arr[i]] = str[i];
    }
    return res;
}

#endif //TP1_PA_EX7_H
