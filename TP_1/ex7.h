//
// Created by draia on 23/09/2021.
//

#ifndef TP1_PA_EX7_H
#define TP1_PA_EX7_H

char *permuteString(const char *str, const int *arr) {
    char *res = malloc(sizeof(char) * strlen(str));
    if (res == NULL) {
        MALLOC_FAIL
    }
		
	sprintf(res, "%s", str); //initializing the string 
	
    for (int i = 0; i < strlen(str); ++i) {
		res[arr[i]] = str[i];
        printf("res[%d] = %c / str[%d] = %c\n", arr[i], res[arr[i]], i, str[i]);
    }
    return res;
}

#endif //TP1_PA_EX7_H
