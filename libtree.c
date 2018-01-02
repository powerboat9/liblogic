#include <stdlib.h>

struct branched_list {
    struct branched_list *p1;
    struct branched_list *p2;
    void *value;
    long key;
}

int addElement(struct branched_list *list, long key, void *val) {
    struct branched_list *append;
    if ((append = malloc(sizeof(struct branched_list))) == NULL) return -1;
    append->p1 = NULL;
    append->p2 = NULL;
    append->value = val;
    append->key = key;
    while (true) {
        if (list->key == key) {
            return -1;
        } else if (list->key > key) {
            list = list->p1;
