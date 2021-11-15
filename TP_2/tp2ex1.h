//
// Created by draia on 10/10/2021.
//

#ifndef Y2_C_TP2EX1_H
#define Y2_C_TP2EX1_H

void copyFile(char *f1_name, char *f2_name) {
    int c;

    FILE *f1 = fopen(f1_name, "r");
    checkFopen(f1);

//    FILE *f2 = fopen(f2_name, "w");
//    checkFopen(f2);
    FILE *f2 = fopen(f2_name, "w");
    checkFopen(f2);

    while (!feof(f1)) {
        c = fgetc(f1);
        if (c < 0 || c > 255 || fputc(c, f2) == EOF) {
            //writes each character while checking if the writing was successful
            printf("non-char detected or fputc failure\n");
            FAIL_OUT
        }
    }
    fclose(f1);
    fclose(f2);
}

void showDiff(char *f1_name, char *f2_name) {
    int c_a, c_b;
    int line_num = 1;

    FILE *f1 = fopen(f1_name, "r");
    checkFopen(f1);

    FILE *f2 = fopen(f2_name, "r");
    checkFopen(f2);

    while (1) {
        c_a = fgetc(f1);
        c_b = fgetc(f2);
        if (c_a != c_b) {
            printf("difference detected at line %d:\n"
                   "%c != %c\n",
                   line_num, c_a, c_b);
            break;
        }
        if (feof(f1) && feof(f2)) {
            printf("perfect copy\n");
            break;
        }
        if (c_a < 0 || c_a > 255 || c_b < 0 || c_b > 255) {
            printf("non-char detected at line %d\n", line_num);
            FAIL_OUT
        }
        if (c_a == '\n') {
            line_num++;
        }
    }
    fclose(f1);
    fclose(f2);
}

#endif //Y2_C_TP2EX1_H
