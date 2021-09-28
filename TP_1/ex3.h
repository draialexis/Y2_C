//
// Created by draia on 23/09/2021.
//

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wformat"

// conflicts between: MinGW on Windows, and expected formats for a C program
// compiled and executed on a Unix OS
#ifndef Y2_C_EX3_H
#define Y2_C_EX3_H

void variable(const char *types) {
    int i = 0;
    while (*types != '\0') {
        switch (*types) {
            case 'i':
                printf("arg[%d]: int | size: %lu\n", i, sizeof(int));
                break;
            case 'I':
                printf("arg[%d]: int pointer | size: %lu\n", i, sizeof(int *));
                break;
            case 'v':
                printf("arg[%d]: void | size: %lu\n", i, sizeof(void));
                break;
            case 'V':
                printf("arg[%d]: void pointer | size: %lu\n", i, sizeof(void *));
                break;
            case 'l':
                printf("arg[%d]: long int | size: %lu\n", i, sizeof(long int));
                break;
            case 'L':
                printf("arg[%d]: long int pointer | size: %lu\n", i, sizeof(long int *));
                break;
            case 'g':
                printf("arg[%d]: long long int | size: %lu\n", i, sizeof(long long int));
                break;
            case 'G':
                printf("arg[%d]: long long int pointer | size: %lu\n", i, sizeof(long long int *));
                break;
        }
        i++;
        types++;
    }
}

#endif //Y2_C_EX3_H
#pragma clang diagnostic pop
