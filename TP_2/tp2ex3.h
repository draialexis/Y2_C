//
// Created by draia on 10/10/2021.
//

#ifndef Y2_C_TP2EX3_H
#define Y2_C_TP2EX3_H

#define BUFFER_SIZE 32768 //~8000 chars

void removeVowels(char *f_name) {
    FILE *fp = fopen(f_name, "r");
    int c;
    checkFopen(fp);
    char *b = (char *) malloc(sizeof(char) * BUFFER_SIZE);
    sprintf(b, "%c", '\0');
    if (b == NULL) {
        MALLOC_FAIL
    }
    while (1) {
        c = fgetc(fp);
        if (feof(fp)) {
            break;
        }
        if (c != 'a' && c != 'A' &&
            c != 'e' && c != 'E' &&
            c != 'i' && c != 'I' &&
            c != 'o' && c != 'O' &&
            c != 'u' && c != 'U' &&
            c != 'y' && c != 'Y') {
            sprintf(b + strlen(b), "%c", c);// could have used strncat...?
        }
    }
    fclose(fp);
    fp = fopen(f_name, "w");
    fputs(b, fp);
    fclose(fp);
}

#endif //Y2_C_TP2EX3_H
