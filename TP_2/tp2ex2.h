//
// Created by draia on 10/10/2021.
//

#ifndef Y2_C_TP2EX2_H
#define Y2_C_TP2EX2_H

void appendFile(char *f1_name, char *f2_name) {
    int c;

    FILE *f1 = fopen(f1_name, "r");
    checkFopen(f1);

    FILE *f2 = fopen(f2_name, "a");
    checkFopen(f2);

    while (1) {
        c = fgetc(f1);
        if (feof(f1)) {
            break;
        }
        if(fputc(c, f2) == EOF){//writes each character while checking if the writing was succesful
            FAIL_OUT
        }
    }
    fclose(f1);
    fclose(f2);
}

#endif //Y2_C_TP2EX2_H
