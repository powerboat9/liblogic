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
                if (last == n) return;
                last = p;
            }
        } else if (p->type == OP_IFELSE) {
            p = (struct node *) ((struct node_opif *) p)->els;
            ((struct node_opif *) last)->els = NULL;
            last = p;
        } else if (isNodeChain(p)) {
            if (((struct node_id_chain) p)->next == NULL) {
                p = (struct node *) p->last;
                free(last);
                if (last == n) return;
                last = p;
            } else {
                p = (struct node *) ((struct node_id_chain) p)->next;
                ((struct node_id_chain) last)->next = NULL:
                last = p;
            }
        } else if (p->type == TYPE_STRING) {
            free(((struct node_str) p)->data);
            p = (struct node *) p->last;
            free(last);
            if (last == n) return;
            last = p;
        } else if (isNodeEnd(p)) {
            p = (struct node *) p->last;
            free(last);
            if (last == n) return;
            last = p;
        } else if (p->type == DEF_SAVEVAR) {
            if (((struct node_save *) p)->value == NULL) {
                p = (struct node *) p->last;
                free(last);
                if (last == n) return;
                last = p;
            } else {
                p = (struct node *) ((struct node_save *) p)->value;
                ((struct node_save *) last)->value = NULL;
                last = p;
            }
        } else {
            p = (struct node *) p->last;
            free(last);
            if (last == n) return;
            last = p;
        }
    }
}

void eval(struct node *n) {
    if
