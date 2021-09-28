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
List createList() {
    List *list = malloc(sizeof(List));
    if (list == NULL) {
        MALLOC_FAIL
    }
    list->nb_elements_ = 0;
    list->head_ = NULL;
    list->tail_ = NULL;
    printf("empty list created\n");
    return *list;//return the list proper instead of a pointer to it...?
}

//2)
int listlen(List list) {
    return list.nb_elements_;
}

//3)

int addToEnd_list(List *listPtr, int val) {//1 for success, 0 for failure
    Element *element = (Element *) malloc(sizeof(Element));
    element->next_ = NULL;
    element->prev_ = NULL;
    element->val_ = val;

    if (listPtr->head_ == NULL && listPtr->tail_ == NULL) {//first element (added to an empty list)
        listPtr->head_ = element;
        listPtr->tail_ = element;
    } else if (listPtr->head_ == NULL || listPtr->tail_ == NULL) {//the list has a tail and no head, or vice versa...
        EMPTY_OR_NULL
        printf("that's weird...\n");
        return 0;
    } else {//list has both tail and head (may be the same element for size1)
        listPtr->tail_->next_ = element;
        element->prev_ = listPtr->tail_;
        listPtr->tail_ = element;
    }
    listPtr->nb_elements_ += 1;
    return 1;
}

//TODO refactor these functions, DRY
//4)
int addToStart_list(List *listPtr, int val) { //1 for success, 0 for failure
    Element *element = (Element *) malloc(sizeof(Element));
    element->next_ = NULL;
    element->prev_ = NULL;
    element->val_ = val;

    if (listPtr->head_ == NULL && listPtr->tail_ == NULL) {
        listPtr->head_ = element;
        listPtr->tail_ = element;
    } else if (listPtr->head_ == NULL || listPtr->tail_ == NULL) {
        EMPTY_OR_NULL
        printf("that's weird...\n");
        return 0;
    } else {
        listPtr->head_->prev_ = element;
        element->next_ = listPtr->head_;
        listPtr->head_ = element;
    }
    listPtr->nb_elements_ += 1;
    return 1;
}

//5)
int endVal_list(List list) {
    return list.tail_->val_;
}

//6)
int startVal_list(List list) {
    return list.head_->val_;
}

//7)
//struct LIterator {
//
//};
//typedef struct LIterator Iterator;

////

void showList(List list) {
    printf("\nprinting list\n");
    Element *currentPtr = list.head_;
    for (int i = 0; i < listlen(list); i++) {
        printf("value at 'list[%d]' = %d\n", i, currentPtr->val_);
        currentPtr = currentPtr->next_;
    }
}

#endif //Y2_C_TP1EX13_H
