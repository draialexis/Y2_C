//
// Created by draia on 10/10/2021.
//

#ifndef Y2_C_TP2EX1_H
#define Y2_C_TP2EX1_H

void checkFopen(FILE *fileName) {
    if (fileName == NULL) {
        EMPTY_OR_NULL
        perror("error while opening file");
        FAIL_OUT
    }
}

void copyFile(char *f1_name, char *f2_name) {
    int c;

    FILE *f1 = fopen(f1_name, "r");
    checkFopen(f1);

    FILE *f2 = fopen(f2_name, "w");
    checkFopen(f2);

    while (1) {
        c = fgetc(f1);
        if (feof(f1)) {
            break;
        }
        fprintf(f2, "%c", c);
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
                   "%c != %c\n", line_num, c_a, c_b);
            break;
        }
        if (feof(f1)) {
            break;
        }
        if (c_a == '\n') {
            line_num++;
        }
    }
    fclose(f1);
    fclose(f2);
}

#endif //Y2_C_TP2EX1_H
