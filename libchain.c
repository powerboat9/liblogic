#include <stdlib.h>

struct section {
    void *address;
    unsigned long length;
}

struct env {
    void *fbase;
    void *base;
    void *stack;
    unsigned long stackSize;
}

struct branched_list {
    void *p1;
    void *p2;
    void *value;
    unsigned 1:hasP1;
    unsigned 1:hasP2;
}

void preformOp(struct *env e, unsigned long opID)

struct section findNoun(struct section *sect) {
    struct section found;
    found.address = NULL:
    found.length = 0;
    if ((sect.address == NULL) || (sect.length == 0)) return found;
    int i = 0;
    while (1) {
        if (i == sec
