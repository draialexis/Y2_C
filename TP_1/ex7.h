//
// Created by draia on 23/09/2021.
//

#ifndef TP1_PA_EX7_H
#define TP1_PA_EX7_H


void swap(char *ch1, char *ch2) {
    printf("swap...\n");
    printf("ch1 = %c & ch2 = %c\n", *ch1, *ch2);
    char tmp;
    printf("1...\n");
    tmp = *ch1;
    *ch1 = *ch2;
    *ch2 = tmp;
    printf("ch1 = %c & ch2 = %c\n", *ch1, *ch2);

}

char *permuteString(char *str, int *arr) {
//    (!) strings don't behave like arrays re. the '[]'
    int offset = 0;
    int strIndex = 0;
    char tmp;
    int i = 0;
    while (str[i] != '\0') {
        offset = *arr;
        tmp = *str;
        printf("tmp = %c\n", tmp);
        printf("*str = %c\n", *(str + (sizeof(char)) * (offset - strIndex)));
        *str = *(str + (sizeof(char)) * (offset - strIndex));
        printf("3...\n");
        *(str + (sizeof(char)) * (offset - strIndex)) = tmp;
        printf("4...\n");

        printf("still here");
        strIndex++;
        i++;
        arr++;
    }
    printf("out!\n");
    while (*str != '\0') {
        printf("%c", *str);
    }

    return str;
}

#endif //TP1_PA_EX7_H
