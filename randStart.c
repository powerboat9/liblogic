#include <stdlib.h>

#define OP_PUSH 0 // address
#define OP_POP 1 // address
#deifne OP_CONST // value

#define OP_ADD 2
#define OP_SUB 3
#define OP_MUL 4
#define OP_DIV 5

#define OP_FREEZE 6 // ticks

#define OP_WRITE 7 / cell, address

#define GENE_SIZE 1020

struct gene {
    unsigned long energy;
    unsigned char grid[GENE_SIZE];
