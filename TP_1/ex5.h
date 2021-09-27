//
// Created by draia on 23/09/2021.
//

#ifndef TP1_PA_EX5_H
#define TP1_PA_EX5_H

int isPermutation(const int *arr, int n) {
    if (arr == NULL) {
        printf("abort\n");
        return 0;
    }

    int count = 0;
    
	for (int i = 0; i < n; i++) {
        if (i > 0) {
            if (count != 1) {
                printf("element: %d wasn't found\n", i - 1);
                return 0;
            }
        }
		
        count = 0;

        for (int j = 0; j < n; j++) {
            if (arr[j] >= n || arr[j] < 0) {
                printf("element: %d out of bounds\n", arr[j]);
                return 0;
            }
            if (arr[j] == i) {
                count++;
                if (count > 1) {
                    printf("element: %d appears more than once\n", arr[j]);
                    return 0;
                }
            }
        }
    }
    return 1;
}

#endif //TP1_PA_EX5_H
