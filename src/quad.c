#include "../include/quad.h"



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

void print_quad(quad qlist)
{
  quad tmp = qlist;
  while(tmp != NULL)
	{

    printf("%s = %s ", tmp->res.name, tmp->arg1.name);
    switch (tmp->op)
    {
      case OP_PLUS:
        printf("+");
        break;
      case OP_MINUS:
        printf("-");
        break;
    }
		printf(" %s ", tmp->arg2.name);
		tmp = tmp->next_quad;
	}
	printf("\n");
}

void free_quad(quad qlist)
{

}
