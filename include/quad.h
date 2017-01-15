#ifndef QUAD_H
#define QUAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_array.h"

enum OP_CODE {OP_PLUS, OP_MINUS, OP_TIMES,OP_DIV,
							OP_AFFEC, OP_INIT_VAR,OP_INIT_VAR_ARRAY,
							OP_BOOL_EQUAL,OP_BOOL_IEQUAL,OP_BOOL_SEQUAL,
							OP_BOOL_INF, OP_BOOL_SUP,OP_BOOL_SUP0,
							PRINT_INTEGER, PRINT_STRING, PRINT_REAL,
							OP_LOOP_FOR};

typedef struct quad_struct{
	int index;
	int label_id;
	enum OP_CODE op;
	symbol arg1;
	symbol arg2;
	symbol res;
	struct quad_struct *next_quad;

} *quad, s_quad;

quad init_quad();
quad create_quad(quad qlist, enum OP_CODE,symbol arg1, symbol arg2, symbol res);
quad quad_concat(quad qlist1, quad qlist2);
void print_quad(quad qlist);
void gen_quad(quad q);
void mips_generate(quad qlist);
void mips_generate_symbol(symbol_array s);
void free_quad(quad qlist);

#endif
