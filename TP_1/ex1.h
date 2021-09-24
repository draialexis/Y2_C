//
// Created by draia on 23/09/2021.
//

#ifndef TP1_PA_EX1_H
#define TP1_PA_EX1_H

void AfficheTab(int *arr, int n) {
    if (arr == NULL) {
        printf("abort\n");
        return;
    }
    int i;
    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(",");
        } else {
            printf("\n");
        }
    }
}

#endif //TP1_PA_EX1_H