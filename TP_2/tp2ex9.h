//
// Created by draia on 10/11/2021.
//

#ifndef Y2_C_TP2EX9_H
#define Y2_C_TP2EX9_H


void getListFromFile(char *txt_f_name, List *lPtr);

void getListFromFile(char *txt_f_name, List *lPtr) {
    FILE *f = fopen(txt_f_name, "r");
    checkFopen(f);

    fseek(f, 10, SEEK_SET);
    char c;
    char *tmp = mkStr(64);

    while (!feof(f)) {
        c = (char) fgetc(f);
        if (c != ',') {
            strcat(tmp, &c);
        } else {
            fseek(f, 1, SEEK_CUR);// skip the comma and whitespace
            addToEnd_list(lPtr, strtol(tmp, NULL, 10));
            sprintf(tmp, "%c", '\0');
        }
    }
    addToEnd_list(lPtr, strtol(tmp, NULL, 10));

    fclose(f);
}

#endif //Y2_C_TP2EX9_H
