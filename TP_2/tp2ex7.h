//
// Created by draia on 10/11/2021.
//

#ifndef Y2_C_TP2EX7_H
#define Y2_C_TP2EX7_H

void cesar(char *txt_f_name, int n);

void cesar(char *txt_f_name, int n) {
    FILE *f1 = fopen(txt_f_name, "r");
    checkFopen(f1);
    FILE *f2 = fopen("ex7_res.txt", "w+");
    checkFopen(f2);
    n = abs(n % 255); //just in case n was out of bounds at start
    int c;
    while (1) {
        c = fgetc(f1);
        if (feof(f1)) {
            break;
        }
        if (c < 0 || c > 255 || fputc((c + n) % 255, f2) == EOF) {
            //writes each character while checking if the writing was successful
            printf("non-char detected or fputc failure\n");
            FAIL_OUT
        }
    }
}

#endif //Y2_C_TP2EX7_H
