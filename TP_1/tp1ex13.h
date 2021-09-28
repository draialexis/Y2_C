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

struct LListe {
    int nb_elements_;
    Element *head_;
    Element *tail_;
};
typedef struct LListe Liste;

//1)
Liste *createList() {
    Liste *list = malloc(sizeof(Liste));
    if (list == NULL) {
        MALLOC_FAIL
    }
    list->nb_elements_ = 0;
    list->head_ = NULL;
    list->tail_ = NULL;

    return list;
}

#endif //Y2_C_TP1EX13_H
