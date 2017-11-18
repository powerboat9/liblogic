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
    char *last;
    char type;
}

#define isNodeChain(n) (n->type < 2)
struct node_id_chain { /* sets and simple adjectives */
    char *last;
    char type;
    unsigned long id;
    char *adj;
}

struct node_str {
    char *last;
    char type;
    char *data;
}

#define isNodeNum(n) ((n->type >= TYPE_LONG) && (n->type <= TYPE_DOUBLE))
struct node_snum {
    char *last;
    char type;
    long n;
}

struct node_unum {
    char *last;
    char type;
    unsigned long n;
}

struct node_dnum {
    char *last;
    char type;
    double n;
}

struct node_load {
    char *last;
    char type;
    unsigned long varID;
}

#define isSimpleBranch(n) ((n->type == TYPE_ADJECTIVE_COMPLEX) || isStdOP(n) || isStdDEF(n))
struct node_simbranch { /* most OP_, most DEF_, ADJECTIVE_COMPLEX */
    char *last;
    char type;
    void *p1;
    void *p2;
}

struct node_opif {
    char *last;
    char type;
    char *i;
    char *the;
    char *els;
}

struct node_save {
    char *last;
    char type;
    unsigned long varID;
    char *value;
}
