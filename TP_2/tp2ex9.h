//
// Created by draia on 10/11/2021.
//

#ifndef Y2_C_TP2EX9_H
#define Y2_C_TP2EX9_H

#define BFR 512

void getListFromFile(char *txt_f_name, List *l);

void getListFromFile(char *txt_f_name, List *l) {
    FILE *f = fopen(txt_f_name, "r");
    checkFopen(f);

//    int num;
    int n = 0;

    while (!feof(f)) {
        fgetc(f);
        n++;
    }
    fseek(f, 0, SEEK_SET);

    char *str = mkStr(n);
    char *tmp = mkStr(1);

    while(!feof(f)){
        sprintf(tmp,"%c", fgetc(f));
        strcat(str, tmp);
    }
//    fread(str, sizeof(char), n, f);
    printf("%s\n", str);
    fclose(f);
}

#endif //Y2_C_TP2EX9_H
