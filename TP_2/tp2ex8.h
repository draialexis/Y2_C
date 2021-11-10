//
// Created by draia on 10/11/2021.
//

#ifndef Y2_C_TP2EX8_H
#define Y2_C_TP2EX8_H

#define BFR 512

void writeListToFile(List l);

void writeListToFile(List l) {
    int n = listlen(l);
    FILE *f = fopen("ex8_res.txt", "w+");
    checkFopen(f);
    char *str = mkStr(BFR);
    char *tmp = mkStr(32);
    sprintf(str, "list: [%d] ", n);

    Element *currentPtr = l.head_;

    for (int i = 0; i < n; i++) {
        sprintf(tmp, "%d", currentPtr->val_);
        strcat(str, tmp);
        currentPtr = currentPtr->next_;
        if (i != n - 1) {
            strcat(str, ", ");
        }
    }
    fwrite(str, sizeof(char), strlen(str), f);
    fclose(f);
}

#endif //Y2_C_TP2EX8_H
