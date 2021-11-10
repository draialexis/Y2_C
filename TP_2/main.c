//
// Created by draia on 10/10/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "toolbox.h"
#include "tp2ex1.h"
#include "tp2ex2.h"
#include "tp2ex3.h"
#include "tp2ex4.h"
#include "tp2ex5.h"
#include "tp2ex6.h"
#include "tp2ex7.h"
#include "..\TP_1\tp1ex13.h"
#include "tp2ex8.h"
#include "tp2ex9.h"

int main(int argc, char *argv[]) {
    //ex1
    //doing it with a binary file seems to work: no diff, and it executes well when using the same arguments
    if (argc == 4) {
        char *mode = argv[1];
        char *f1_name = argv[2];
        char *f2_name = argv[3];
        if (strcmp(mode, "copie") == 0) {
            copyFile(f1_name, f2_name);
        } else if (strcmp(mode, "diff") == 0) {
            showDiff(f1_name, f2_name);
        } else if (strcmp(mode, "concatene") == 0) {
            //ex2
            appendFile(f1_name, f2_name);
        } else {
            printf("argument 1 is supposed to be \"copie\", \"diff\", or \"concatene\"\n");
        }
    } else if (argc == 3) {
        char *mode = argv[1];
        char *f1_name = argv[2];
        if (strcmp(mode, "vwl") == 0) {
            //ex3
            removeVowels(f1_name);
        }
    } else if (argc == 2) {
        //ex4
        // & wc ex4
        // 2    2 2048 ex4
        // size of int = 4 ; 4 * 512 = 2048 ; coherent
        // od also seems consistent
        char *f_name = argv[1];
        copyArray(f_name);
    } else {
        printf("no arguments? doing part 2...\n");
        char *permName = "perm_f.txt";
        encode("txt_f.txt", permName);
        decode("encoded.txt", permName);
        cesar("ex7_orig.txt", 1);
        printf("and part 3\n");
        List l1 = createList();
        int nums[] = {1, 25, 9, 3, 6, 9, 8, 247, -15};
        for (int i = 0; i < 9; i++) {
            addToEnd_list(&l1, nums[i]);
        }
        writeListToFile(l1);
        List l2 = createList();
        getListFromFile("ex8_res.txt", &l2);
        showList(l2);
    }

    return 0;
}