#include "../include/quad.h"
#include "../include/gen_code.h"


quad init_quad()
{
  return (quad)NULL;
}
quad create_quad(quad qlist, enum OP_CODE op, symbol arg1, symbol arg2, symbol res)
{
  quad newQuad = (quad)malloc(sizeof(s_quad));
  newQuad->op = op;
  newQuad->arg1 = arg1;
  newQuad->arg2 = arg2;
  newQuad->res = res;
  newQuad->next_quad = NULL;
  if(qlist == NULL)
    return newQuad;
  else
  {
    quad tmp = qlist;
    while(tmp->next_quad != NULL)
      tmp = tmp->next_quad;
    tmp->next_quad = newQuad;
    return qlist;
  }

}
quad quad_concat(quad list1, quad list2)
{
   quad q;
   if(list1 == NULL)
   {
       list1 = list2;
       return list1;
   }
   if(list2 == NULL)
       return list1;

   q = list1;
   while(q->next_quad != NULL)
       q = q->next_quad;
   q->next_quad = list2;

   return list1;
}

void print_quad(quad qlist)
{
  quad tmp = qlist;
  while(tmp != NULL)
	{

    printf("OPCODE :%d\n",tmp->op);
		tmp = tmp->next_quad;
    printf("\n");
	}
}

void mips_generate(quad qlist)
{
  quad tmp = qlist;
  while(tmp != NULL)
	{
    gen_quad(tmp);
    tmp = tmp->next_quad;
	}
}
void mips_generate_symbol(symbol_array s)
{
  for(int i = 0; i < s->length; i++)
  {
    if(s->symbol[i]->type == TEXT_TYPE || !s->symbol[i]->isconst)
    {
      quad q;
      if(s->symbol[i]->unit == VECTOR)
        q = create_quad(NULL, OP_INIT_VAR_ARRAY, NULL,NULL,s->symbol[i]);
      else
        q = create_quad(NULL, OP_INIT_VAR, NULL,NULL,s->symbol[i]);
      gen_quad(q);
    }
  }
}

void gen_quad(quad q)
{
  switch (q->op)
  {
    case OP_INIT_VAR:
      gen_init_var(q);
      break;
    case OP_INIT_VAR_ARRAY:
      gen_init_var_array(q);
      break;
    case OP_AFFEC:
      gen_affec_var(q);
      break;
    case OP_PLUS:
    case OP_TIMES:
    case OP_MINUS:
    case OP_DIV:
      gen_arithmetic(q);
      break;
    case PRINT_INTEGER:
      gen_syscall_print_int(q);
      break;
    case PRINT_STRING:
      gen_syscall_print_text(q);
      break;
    case PRINT_REAL:
      gen_syscall_print_real(q);
      break;
    case OP_BOOL_EQUAL:
      gen_boolexpr_equal(q);
      break;
    case OP_BOOL_IEQUAL:
      gen_boolexpr_iequal(q);
      break;
    case OP_BOOL_SEQUAL:
      gen_boolexpr_sequal(q);
      break;
    case OP_BOOL_INF:
      gen_boolexpr_inf(q);
      break;
    case OP_BOOL_SUP:
      gen_boolexpr_sup(q);
      break;
    case OP_BOOL_SUP0:
      gen_boolexpr_sup0(q);
    case OP_LOOP_FOR:
      gen_loop_increment(q);
      break;
    default:
      break;
  }
}

void free_quad(quad qlist)
{

}
