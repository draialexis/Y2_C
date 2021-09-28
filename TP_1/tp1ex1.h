//
// Created by draia on 23/09/2021.
//

#ifndef Y2_C_TP1EX1_H
#define Y2_C_TP1EX1_H

void AfficheTab(int *arr, int n) {
    if (n > 0 && arr != NULL) {
        int i;
        for (i = 0; i < n; i++) {
            printf("%d", arr[i]);
            if (i < n - 1) {
                printf(",");
            } else {
                printf("\n");
            }
        }
    } else {
        EMPTY_OR_NULL
    }
}

void AfficheTab_f(float *arr, int n) {
    if (n > 0 && arr != NULL) {
        int i;
        for (i = 0; i < n; i++) {
            printf("%+.2f", arr[i]);
            if (i < n - 1) {
                printf(",");
            } else {
                printf("\n");
            }
        }
    } else {
        EMPTY_OR_NULL
    }
}
#endif //Y2_C_TP1EX1_H