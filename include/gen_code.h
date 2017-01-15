#ifndef GEN_CODE_H
#define GEN_CODE_H

#include "quad.h"

enum REGISTER_INT   { T0, T1, T2};
enum REGISTER_FLOAT { F0, F1, F2};



// affectation
void gen_init_var(quad q);
void gen_affec_var(quad q);
void gen_init_var_array(quad q);
//arithemtic
void gen_arithmetic(quad q);
void gen_loop_increment(quad q);
//syscall
void gen_syscall_print_int(quad q);
void gen_syscall_print_text(quad q);
void gen_syscall_print_real(quad q);
// BOOL_EXPR
void gen_boolexpr_equal(quad q);
void gen_boolexpr_iequal(quad q);
void gen_boolexpr_sequal(quad q);
void gen_boolexpr_inf(quad q);
void gen_boolexpr_sup(quad q);
void gen_boolexpr_sup0(quad q);
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

// recupere l'adresse ou est stocke le symbol et l'affecte dans le registre reg
// en respectant les types.
// ex si c'est un flottant on aura : li.s $t0, number
void gen_affect_var(char *reg, symbol s);

#endif
