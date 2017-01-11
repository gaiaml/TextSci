#ifndef QUAD_H
#define QUAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_array.h"

enum OP_CODE {OP_PLUS, OP_MINUS, OP_TIMES,
							OP_AFFEC, OP_INIT_VAR,
							OP_BOOL_EQUAL,
							PRINT_INTEGER};

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
void gen_quad(quad q);
void free_quad(quad qlist);

#endif
