#ifndef SYMBOL_ARRAY_H
#define SYMBOL_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH_SYMBOL_ARRAY 128

enum BOOLEAN{FALSE, TRUE};
enum TYPE {INT_TYPE, REAL_TYPE, CST_TYPE};
enum SCOPE {SCOPE_INPUT, SCOPE_OUTPUT, SCOPE_GLOBAL, SCOPE_LOCAL};
enum UNIT {SCALAR, VECTOR};

typedef struct symbol{
	int index;
	int isconst;
	int is_tmp;
	char *name;
	char *address;

	union{
		int int_value;
		float float_value;
		enum BOOLEAN bool_value;
	}value;

	enum TYPE type;
	enum SCOPE scope;
	enum UNIT unit;
} *symbol, s_symbol;



typedef struct array_symbol{
	symbol symbol[LENGTH_SYMBOL_ARRAY];
	int hash_index;
	int length;
} *symbol_array, s_symbol_array;


int get_hash_index(char *chaine);

/**
 @but : Renvoie l'index du symbole dans la table de symbole
 @param : symbole analyser, table des symboles
 @return : -1 si symbole inexistant, index sinon
**/
symbol search(char* name, symbol_array arraySymbol);
/**
 @but : Ajout d'un symbole dans la table des symboles
 @param : symbole a ajouter, table des symboles
 @return : le symbole ajouté
**/
symbol add_to_symbol_array(symbol s, symbol_array arraySymbol);
void print_symbol_table(symbol_array symbol_table, char* name);
void free_symbol_array(symbol_array arraySymbol);


#endif
