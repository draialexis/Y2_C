//
// Created by draia on 23/09/2021.
//

#ifndef TP1_PA_EX3_H
#define TP1_PA_EX3_H

void variable(const char *types) {
    int i = 0;
    while (*types != '\0') {
        switch (*types) {
            case 'i':
                printf("arg[%d]: int | size: %llu\n", i, sizeof(int));
                break;
            case 'I':
                printf("arg[%d]: int pointer | size: %llu\n", i, sizeof(int *));
                break;
            case 'v':
                printf("arg[%d]: void | size: %llu\n", i, sizeof(void));
                break;
            case 'V':
                printf("arg[%d]: void pointer | size: %llu\n", i, sizeof(void *));
                break;
            case 'l':
                printf("arg[%d]: long int | size: %llu\n", i, sizeof(long));
                break;
            case 'L':
                printf("arg[%d]: long int pointer | size: %llu\n", i, sizeof(long *));
                break;
        }
        i++;
        types++;
    }
}

#endif //TP1_PA_EX3_H
