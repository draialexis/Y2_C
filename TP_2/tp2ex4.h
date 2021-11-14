//
// Created by draia on 10/10/2021.
//

#ifndef Y2_C_TP2EX4_H
#define Y2_C_TP2EX4_H

#define N 512

void copyArray(char *f_name) {
    FILE *fp = fopen(f_name, "w");
    checkFopen(fp);

    int *T = (int *) malloc(sizeof(int) * N);
    if (T == NULL) {
        MALLOC_FAIL
    }
    for (int i = 0; i < N; i++) {
        T[i] = i;
    }

    fwrite(T, sizeof(int), N, fp);
    fclose(fp);

}

#endif //Y2_C_TP2EX4_H
