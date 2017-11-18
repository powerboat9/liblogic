#include "constants.h"

void freeNodeTree(struct node *n) { /* if any of the nodes have a screwed up "last" field, things will break */
    struct node *p = n;
    struct node *last = n;
    while (true) {
        if (isSimpleBranch(p) || ((p->type == OP_IFELSE) && (((struct node_opif *) p)->els == NULL))) {
            if (((struct node_simbranch *) p)->p2 != NULL) {
                p = (struct node *) ((struct node_simbranch *) p)->p2;
                ((struct node_simbranch *) last)->p2 = NULL;
                last = p;
            } else if ((struct node_simbranch *) p)->p1 != NULL) {
                p = (struct node *) ((struct node_simbranch *) p)->p1;
                ((struct node_simbranch *) last)->p1 = NULL;
                last = p;
            } else {
                p = (struct node *) p->last;
                free(last);
                last = p;
            }
            continue;
        }
        if (p->p2 != NULL) {
            p = p->p2;
            continue;
        }
        switch (n->type) {
            case TYPE_SET:
            case TYPE_ADJECTIVE:
            case TYPE_LONG:
            case TYPE_ULONG:
            case LOADVAR:

void resolveConstants(struct node *n) {
    
