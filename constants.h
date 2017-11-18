#define TYPE_SET 0
#define TYPE_ADJECTIVE 1
#define TYPE_ADJECTIVE_COMPLEX 2

#define TYPE_STRING 3

#define TYPE_LONG 4
#define TYPE_ULONG 5
#define TYPE_DOUBLE 6

#define TYPE_LOADVAR 7

#define OP_ADD 8
#define OP_SUB 9
#define OP_MUL 10
#define OP_DIV 11
#define OP_POW 12
#define OP_ROOT 13

#define OP_OR 14
#define OP_AND 15
#define OP_NOT 16

#define OP_IFELSE 17

#define DEF_IF 18
#define DEF_IFF 19
#define DEF_IFNOT 20
#define DEF_IFFNOT 21

#define DEF_SAVEVAR 22

#define SET_ALL 0
#define SET_NONE 1

#define isOP(n) ((n->type >= OP_ADD) && (n->type <= OP_IFELSE))
#define isStdOP(n) ((n->type >= OP_ADD) && (n->type < OP_IFELSE))
#define isDEF(n) ((n->type >= DEF_IF) && (n->type <= DEF_SAVEVAR))
#define isStdDEF(n) ((n->type >= DEF_IF) && (n->type < DEF_SAVEVAR))
struct node {
    void *last;
    char type;
}

#define isNodeChain(n) (n->type < 2)
struct node_id_chain { /* sets and simple adjectives */
    void *last;
    char type;
    unsigned long id;
    void *next;
}

struct node_str {
    void *last;
    char type;
    char *data;
}

#define isNodeEnd(n) ((n->type >= TYPE_LONG) && (n->type <= TYPE_LOADVAR))
#define isNodeNum(n) ((n->type >= TYPE_LONG) && (n->type <= TYPE_DOUBLE))
struct node_snum {
    void *last;
    char type;
    long n;
}

struct node_unum {
    void *last;
    char type;
    unsigned long n;
}

struct node_dnum {
    void *last;
    char type;
    double n;
}

struct node_load {
    void *last;
    char type;
    unsigned long varID;
}

#define isSimpleBranch(n) ((n->type == TYPE_ADJECTIVE_COMPLEX) || isStdOP(n) || isStdDEF(n))
struct node_simbranch { /* most OP_, most DEF_, ADJECTIVE_COMPLEX */
    void *last;
    char type;
    void *p1;
    void *p2;
}

struct node_opif {
    void *last;
    char type;
    void *i;
    void *the;
    void *els;
}

struct node_save {
    void *last;
    char type;
    unsigned long varID;
    void *value;
}
