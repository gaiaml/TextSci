#ifndef GEN_CODE_H
#define GEN_CODE_H

#include "quad.h"

// affectation
void gen_init_var(quad q);
void gen_affec_var(quad q);
//arithemtic
void gen_arithmetic(quad q);

//syscall
void gen_syscall_print_int(quad q);

// BOOL_EXPR
void gen_boolexpr_equal(quad q);

// permet de savoir quel registre est utilise.
// nous utilisons uniquement : $t1 et $t2 pour le calcul arithmetique
int temp_register[2];


/*
Nous generons au debut du programme des fonctions de comparaisons :
(= , >=, <=, !=). Cela evite la duplication de code a chaque comparaison.
Le resultat de cette comparaison est stocke dans v0:
Si v0 = 1 : test reussi
Si v0 = 0 : test echoue

*/
void gen_precompiled_comparison();

#endif
