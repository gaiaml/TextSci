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

  gen_quad(newQuad);

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

void print_quad(quad qlist)
{
  quad tmp = qlist;
  while(tmp != NULL)
	{

    printf("%s = %s", tmp->res->name, tmp->arg1->name);
    switch (tmp->op)
    {
      case OP_PLUS:
        printf("+");
        break;
      case OP_MINUS:
        printf("-");
        break;
      default:
        break;
    }
    if(tmp->arg2->name != NULL)
      printf("%s", tmp->arg2->name);
		tmp = tmp->next_quad;
    printf("\n");
	}
}

void gen_quad(quad q)
{
  switch (q->op)
  {
    case OP_INIT_VAR:
      gen_init_var(q);
      break;
    case OP_AFFEC:
      gen_affec_var(q);
      break;
    case OP_PLUS:
    case OP_TIMES:
      gen_arithmetic(q);
      break;
    case PRINT_INTEGER:
      gen_syscall_print_int(q);
      break;
    case OP_BOOL_EQUAL:
      gen_boolexpr_equal(q);
      break;
    default:
      break;
  }
}

void free_quad(quad qlist)
{

}
