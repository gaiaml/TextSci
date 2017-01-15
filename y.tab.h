/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TEXSCI_BEGIN = 258,
    TEXSCI_END = 259,
    BLANKLINE = 260,
    AFFECTATION = 261,
    INF_EQUAL = 262,
    SUP_EQUAL = 263,
    MBOX = 264,
    PRINT_INT_TK = 265,
    PRINT_TEXT_TK = 266,
    PRINT_REAL_TK = 267,
    INPUT_DECLARATION = 268,
    OUTPUT_DECLARATION = 269,
    GLOBAL_DECLARATION = 270,
    LOCAL_DECLARATION = 271,
    IN_KEY = 272,
    WHILE = 273,
    FOR = 274,
    KWTO = 275,
    TYPE_KEY = 276,
    ID = 277,
    ID_VARS = 278,
    IF = 279,
    EIF = 280,
    NUMBER = 281,
    STRING = 282,
    REAL = 283
  };
#endif
/* Tokens.  */
#define TEXSCI_BEGIN 258
#define TEXSCI_END 259
#define BLANKLINE 260
#define AFFECTATION 261
#define INF_EQUAL 262
#define SUP_EQUAL 263
#define MBOX 264
#define PRINT_INT_TK 265
#define PRINT_TEXT_TK 266
#define PRINT_REAL_TK 267
#define INPUT_DECLARATION 268
#define OUTPUT_DECLARATION 269
#define GLOBAL_DECLARATION 270
#define LOCAL_DECLARATION 271
#define IN_KEY 272
#define WHILE 273
#define FOR 274
#define KWTO 275
#define TYPE_KEY 276
#define ID 277
#define ID_VARS 278
#define IF 279
#define EIF 280
#define NUMBER 281
#define STRING 282
#define REAL 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 27 "grammar/texcc.y" /* yacc.c:1909  */

  char* name;
  int value;
  symbol variable;
  enum TYPE type;

  struct{
    symbol variable;
    quad listquad;
  }code;

#line 122 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
