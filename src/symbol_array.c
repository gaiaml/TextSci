#include "../include/symbol_array.h"


int get_hash_index(char *chaine)
{
	int index = 0;
	for(int i = 0; i < strlen(chaine); i++)
		index += chaine[i];
	return index % LENGTH_SYMBOL_ARRAY;
}


symbol search(symbol s, symbol_array symbol_table)
{
	int found = 0;
	symbol result;
	result.name = NULL;
	for(int i = 0; i < symbol_table->length && !found; i++)
	{
		if(strcmp(s.name, symbol_table->symbol[i].name) == 0)
		{
			found = 1;
			result = symbol_table->symbol[i];
		}
	}
	return result;
}

symbol add_to_symbol_array(symbol s, symbol_array arraySymbol)
{
	arraySymbol->symbol[arraySymbol->length++] = s;
	return s;
}

void print_symbol_table(symbol_array symbol_table, char* name)
{
	printf("--------- Table des symboles pour l'algorithme : %s ---------\n", name );
	printf("#ID\t\t#TYPE\t\t#SCOPE\n\n");
	for(int i =0; i < symbol_table->length; i++)
	{
		symbol s = symbol_table->symbol[i];
		printf("%s\t\t", s.name);
		switch (s.type)
		{
			case INT_TYPE:
				printf("INTEGER\t\t");
				break;
			case REAL_TYPE:
				printf("REAL \t\t");
				break;
		}
		switch (s.scope)
		{
			case SCOPE_INPUT:
				printf("INPUT \t\t");
				break;
			case SCOPE_OUTPUT:
				printf("OUTPUT \t\t");
				break;
			case SCOPE_GLOBAL:
				printf("GLOBAL \t\t");
				break;
			case SCOPE_LOCAL:
				printf("LOCAL \t\t");
				break;
		}
		printf("\n");
	}
}
void free_symbol_array(symbol_array arraySymbol)
{

}
