#ifndef QUAD_H
#define QUAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_array.h"

enum OP_CODE {OP_PLUS, OP_MINUS};

typedef struct quad_struct{
	int index;
	enum OP_CODE op;
	symbol arg1;
	symbol arg2;
	symbol res;
	struct quad_struct *next_quad;

} *quad, s_quad;

quad init_quad();
quad create_quad(quad qlist, enum OP_CODE,symbol arg1, symbol arg2, symbol res);
void print_quad(quad qlist);
void free_quad(quad qlist);

#endif
