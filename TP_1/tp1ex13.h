//
// Created by draia on 28/09/2021.
//

#ifndef Y2_C_TP1EX13_H
#define Y2_C_TP1EX13_H

typedef struct LElement Element;
struct LElement {
    Element *next_;
    Element *prev_;
    int val_;
};

struct LList {
    int nb_elements_;
    Element *head_;
    Element *tail_;
};
typedef struct LList List;

//1)
List *createList() {
    List *list = malloc(sizeof(List));
    if (list == NULL) {
        MALLOC_FAIL
    }
    list->nb_elements_ = 0;
    list->head_ = NULL;
    list->tail_ = NULL;

    return list;
}

//2)
int listlen(List list) {
    Element *crntPtr = list.head_;
    int counter = 0;
    while (crntPtr != NULL) {
        counter++;
        crntPtr++;
    }
    return counter;
}


#endif //Y2_C_TP1EX13_H
