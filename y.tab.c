/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "grammar/texcc.y" /* yacc.c:339  */

  #include <stdio.h>
  #include <stdlib.h>
  #include "include/symbol_array.h"
  #include "include/quad.h"
  #include "include/gen_code.h"
  #define TEXCC_ERROR_GENERAL 4


  // Functions and global variables provided by Lex.
  int yylex();
  int id_label;
  int id_str; // tmp
  void texcc_lexer_free();
  extern FILE* yyin;
  extern int yylineno;
  extern char* yytext;

  symbol_array symbol_table;
  quad all_quad;
  void yyerror(char* s)
  {
    printf("Ligne %d: %s sur le token : %s\n", yylineno, s, yytext);
  }

#line 92 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 27 "grammar/texcc.y" /* yacc.c:355  */

  char* name;
  int value;
  symbol variable;
  enum TYPE type;

  struct{
    symbol variable;
    quad listquad;
  }code;

#line 200 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 217 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   229

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  48
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  157

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    38,     2,     2,     2,
      39,    40,    34,    32,    41,    33,     2,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      30,    29,    31,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    42,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    37,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    67,    67,    68,    72,    85,    86,    88,    90,    92,
      97,    99,   105,   110,   116,   129,   139,   143,   149,   175,
     190,   205,   233,   254,   275,   296,   318,   323,   329,   335,
     349,   357,   365,   373,   381,   389,   397,   411,   412,   415,
     416,   419,   420,   423,   424,   427,   429,   433,   449
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TEXSCI_BEGIN", "TEXSCI_END",
  "BLANKLINE", "AFFECTATION", "INF_EQUAL", "SUP_EQUAL", "MBOX",
  "PRINT_INT_TK", "PRINT_TEXT_TK", "PRINT_REAL_TK", "INPUT_DECLARATION",
  "OUTPUT_DECLARATION", "GLOBAL_DECLARATION", "LOCAL_DECLARATION",
  "IN_KEY", "WHILE", "FOR", "KWTO", "TYPE_KEY", "ID", "ID_VARS", "IF",
  "EIF", "NUMBER", "STRING", "REAL", "'='", "'<'", "'>'", "'+'", "'-'",
  "'*'", "'/'", "'{'", "'}'", "'$'", "'('", "')'", "','", "'^'", "$accept",
  "algorithm_list", "algorithm", "LIST_CODE", "CODE", "CONDITION_FOR",
  "M_WHILE", "M_BOOL", "AFFEC", "FUNCTION", "EXPRESSION", "BOOL_EXPR",
  "DECLARATIONS", "INPUT", "OUTPUT", "GLOBAL", "LOCAL", "LIST_VARS",
  "VARIABLE", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    61,
      60,    62,    43,    45,    42,    47,   123,   125,    36,    40,
      41,    44,    94
};
# endif

#define YYPACT_NINF -63

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-63)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       2,    -7,    11,   -63,    16,   -63,   -63,     0,    28,     8,
      41,    37,    14,   181,    20,    44,    38,   -63,    26,   -63,
      30,    32,   -63,   -63,    -6,   -16,    39,   -63,   -63,   -63,
     -15,    43,    46,    68,    71,    67,    65,    72,    75,    80,
      82,    88,    91,   129,    15,   -63,   -63,   -16,   -16,   -16,
     -16,    38,    98,   102,   -63,   121,   110,    38,   111,   126,
     130,   181,   -16,   -16,   134,   -16,   -63,   -13,   -13,   -63,
     -63,   113,    38,   119,   116,   -63,   -63,   -16,   122,    61,
       1,   128,   131,   125,   132,   133,    58,   136,   141,    38,
     144,   148,   142,   -63,   -16,   -16,   -16,   -16,   -16,   145,
     151,   152,   153,   154,   -63,   -63,   156,   157,   163,   164,
     166,   -15,   -15,   -15,   -15,   -15,   158,   172,   -16,   140,
     -16,   -63,   165,   173,   175,   176,   181,   181,    69,   174,
      90,   -63,   -63,   181,   -63,    93,   115,   177,   178,   182,
     137,   -63,   -63,   179,   184,   186,   -63,   188,   187,   189,
     190,   181,   -63,   -63,   -63,   159,   -63
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     3,     0,     1,     2,     0,    37,     0,
       0,    39,     0,     7,     0,    41,     0,    16,     0,    29,
       0,     0,    27,    28,     0,     0,     0,     6,     8,    10,
       9,     0,     0,    43,     0,     0,    46,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     5,     0,     0,     0,
       0,     0,     0,     0,    36,     0,     0,     0,     0,     0,
       0,     7,     0,     0,     0,     0,    26,    22,    23,    25,
      24,     0,     0,     0,    47,    38,    45,     0,     0,     0,
      35,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    14,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,    40,     0,     0,     0,     0,
       0,    31,    32,    30,    33,    34,     0,     0,     0,     0,
       0,    42,     0,     0,     0,     0,     7,     7,     0,     0,
       0,    44,    48,     7,    15,     0,     0,     0,     0,     0,
       0,    11,    17,     0,     0,     0,    13,     0,     0,     0,
       0,     7,    19,    21,    20,     0,    12
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -63,   -63,   168,   -57,   -26,   -63,   -63,   -63,   191,   -63,
     -23,   -62,   -63,   -63,   -63,   -63,   -63,   -44,   -63
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    26,    27,    39,    37,   147,    28,    29,
      30,    81,    10,    11,    15,    33,    54,    35,    36
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      46,    82,    44,    42,    79,     1,    19,    71,    94,    95,
      22,     5,    23,    76,     1,    91,    43,    47,    48,    49,
      50,    49,    50,    25,    67,    68,    69,    70,    88,     4,
      96,    97,    98,    47,    48,    49,    50,     8,     7,    80,
      80,     9,    86,    45,    12,   107,    13,    47,    48,    49,
      50,    14,    16,    46,    80,    66,    31,    17,    18,    32,
      34,    19,    38,    20,    21,    22,    40,    23,    41,   135,
     136,   111,   112,   113,   114,   115,   140,    24,    25,    17,
      18,    51,    52,    19,    53,    20,    21,    22,    55,    23,
      47,    48,    49,    50,   155,   128,   104,   130,    93,    24,
      25,    47,    48,    49,    50,    56,    57,   137,    58,    46,
      46,    17,    18,    59,    46,    19,    61,    20,    21,    22,
      62,    23,    47,    48,    49,    50,    63,    64,   139,    46,
     141,    24,    25,    17,    18,    65,    72,    19,    73,    20,
      21,    22,    74,    23,    83,    84,    85,    75,    43,    77,
      78,    87,   142,    24,    25,    17,    18,    89,    90,    19,
      92,    20,    21,    22,   101,    23,    99,   129,   110,   100,
       6,   102,   103,   105,   146,    24,    25,    17,    18,   106,
     108,    19,   116,    20,    21,    22,   109,    23,   117,   123,
     118,   119,   120,   121,   126,   122,   156,    24,    25,    17,
      18,   124,   131,    19,   125,    20,    21,    22,   127,    23,
     132,   133,   138,   134,     0,     0,   148,   143,   144,    24,
      25,   149,   145,   150,   151,   152,     0,   153,   154,    60
};

static const yytype_int16 yycheck[] =
{
      26,    63,    25,     9,    61,     3,    22,    51,     7,     8,
      26,     0,    28,    57,     3,    77,    22,    32,    33,    34,
      35,    34,    35,    39,    47,    48,    49,    50,    72,    36,
      29,    30,    31,    32,    33,    34,    35,    37,    22,    62,
      63,    13,    65,     4,    36,    89,     5,    32,    33,    34,
      35,    14,    38,    79,    77,    40,    36,    18,    19,    15,
      22,    22,    36,    24,    25,    26,    36,    28,    36,   126,
     127,    94,    95,    96,    97,    98,   133,    38,    39,    18,
      19,    38,    36,    22,    16,    24,    25,    26,    17,    28,
      32,    33,    34,    35,   151,   118,    38,   120,    37,    38,
      39,    32,    33,    34,    35,    38,    41,    38,    36,   135,
     136,    18,    19,    38,   140,    22,    36,    24,    25,    26,
      38,    28,    32,    33,    34,    35,    38,    36,    38,   155,
      37,    38,    39,    18,    19,     6,    38,    22,    36,    24,
      25,    26,    21,    28,    10,    11,    12,    37,    22,    38,
      20,    38,    37,    38,    39,    18,    19,    38,    42,    22,
      38,    24,    25,    26,    39,    28,    38,    27,    26,    38,
       2,    39,    39,    37,    37,    38,    39,    18,    19,    38,
      36,    22,    37,    24,    25,    26,    38,    28,    37,    26,
      38,    38,    38,    37,    36,    38,    37,    38,    39,    18,
      19,    37,    37,    22,    38,    24,    25,    26,    36,    28,
      37,    36,    38,    37,    -1,    -1,    37,    40,    40,    38,
      39,    37,    40,    37,    36,    38,    -1,    38,    38,    38
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    44,    45,    36,     0,    45,    22,    37,    13,
      55,    56,    36,     5,    14,    57,    38,    18,    19,    22,
      24,    25,    26,    28,    38,    39,    46,    47,    51,    52,
      53,    36,    15,    58,    22,    60,    61,    49,    36,    48,
      36,    36,     9,    22,    53,     4,    47,    32,    33,    34,
      35,    38,    36,    16,    59,    17,    38,    41,    36,    38,
      51,    36,    38,    38,    36,     6,    40,    53,    53,    53,
      53,    60,    38,    36,    21,    37,    60,    38,    20,    46,
      53,    54,    54,    10,    11,    12,    53,    38,    60,    38,
      42,    54,    38,    37,     7,     8,    29,    30,    31,    38,
      38,    39,    39,    39,    38,    37,    38,    60,    36,    38,
      26,    53,    53,    53,    53,    53,    37,    37,    38,    38,
      38,    37,    38,    26,    37,    38,    36,    36,    53,    27,
      53,    37,    37,    36,    37,    46,    46,    38,    38,    38,
      46,    37,    37,    40,    40,    40,    37,    50,    37,    37,
      37,    36,    38,    38,    38,    46,    37
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    44,    45,    46,    46,    47,    47,    47,
      47,    47,    47,    47,    47,    48,    49,    50,    51,    52,
      52,    52,    53,    53,    53,    53,    53,    53,    53,    53,
      54,    54,    54,    54,    54,    54,    55,    56,    56,    57,
      57,    58,    58,    59,    59,    60,    60,    61,    61
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     8,     2,     1,     0,     1,     1,
       1,     9,    13,    10,     5,     7,     0,     0,     5,    11,
      11,    11,     3,     3,     3,     3,     3,     1,     1,     1,
       3,     3,     3,     3,     3,     1,     4,     0,     6,     0,
       6,     0,     6,     0,     6,     3,     1,     3,     7
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:
#line 73 "grammar/texcc.y" /* yacc.c:1646  */
    {
      fprintf(stdout, ".data\n");
      mips_generate_symbol(symbol_table);
      symbol_table->length = 0;

      fprintf(stderr, "[texcc] info: algorithm \"%s\" parsed\n", (yyvsp[-5].name));
      //print_symbol_table(symbol_table, $3);
      free((yyvsp[-5].name));
    }
#line 1409 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 88 "grammar/texcc.y" /* yacc.c:1646  */
    {}
#line 1415 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 93 "grammar/texcc.y" /* yacc.c:1646  */
    {

    }
#line 1423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 100 "grammar/texcc.y" /* yacc.c:1646  */
    {
      fprintf(stdout, "\t#FALSE LIST\n");
      fprintf(stdout, "\tIF_%d_FALSELIST:\n", (yyvsp[-5].code).listquad->label_id);
    }
#line 1432 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 106 "grammar/texcc.y" /* yacc.c:1646  */
    {
      fprintf(stdout, "\tIF_%d_END:\n", (yyvsp[-9].code).listquad->label_id);
    }
#line 1440 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 111 "grammar/texcc.y" /* yacc.c:1646  */
    {
      fprintf(stdout, "\tj WHILE_%d_BEGIN\n", (yyvsp[-5].code).listquad->label_id);
      fprintf(stdout, "\tIF_%d_FALSELIST:\n", (yyvsp[-5].code).listquad->label_id);
    }
#line 1449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 117 "grammar/texcc.y" /* yacc.c:1646  */
    {
      //lw $t0,i
      //add $t0,$t0,1
      //sw $t0,i

      // incremente le compteur
      mips_generate((yyvsp[-3].code).listquad);
      fprintf(stdout, "\tj WHILE_%d_BEGIN\n", (yyvsp[-3].code).listquad->label_id);
      fprintf(stdout, "\tIF_%d_FALSELIST:\n", (yyvsp[-3].code).listquad->label_id);
    }
#line 1464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 130 "grammar/texcc.y" /* yacc.c:1646  */
    {
      // on converti  le for en while :

      fprintf(stdout, "\tWHILE_%d_BEGIN:\n", id_label);
      mips_generate(create_quad(NULL, OP_BOOL_INF,(yyvsp[-5].code).variable,(yyvsp[-2].variable), NULL));
      (yyval.code).listquad = create_quad(NULL, OP_LOOP_FOR, (yyvsp[-5].code).variable, NULL,NULL);
    }
#line 1476 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 139 "grammar/texcc.y" /* yacc.c:1646  */
    {
      fprintf(stdout, "\tWHILE_%d_BEGIN:\n", id_label);
    }
#line 1484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 143 "grammar/texcc.y" /* yacc.c:1646  */
    {
      fprintf(stdout, "\tj IF_%d_END\n", id_label-1);
      fprintf(stdout, "\t#FALSE LIST\n");
      fprintf(stdout, "\tIF_%d_FALSELIST:\n", id_label-1);
    }
#line 1494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 150 "grammar/texcc.y" /* yacc.c:1646  */
    {
      symbol s = search((yyvsp[-3].name), symbol_table);
      if(s != NULL )
      {
        if(s->type != (yyvsp[-1].code).variable->type)
        {
          fprintf(stderr, "Erreur de typage ligne : %d entre %s et %s!\n",yylineno, s->name, (yyvsp[-1].code).variable->name);
          exit(3);
        }
        //s->isconst = FALSE;
        //s->name = strdup($2);
        mips_generate((yyvsp[-1].code).listquad);
        quad q = create_quad(NULL,OP_AFFEC,(yyvsp[-1].code).variable, NULL, s);
        mips_generate(q);
        (yyval.code).variable = s;

      }
      else
      {
        fprintf(stderr, "Erreur ligne : %d la variable %s n'est pas declare !\n",yylineno, (yyvsp[-3].name));
        exit(3);
      }
    }
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 176 "grammar/texcc.y" /* yacc.c:1646  */
    {
      if((yyvsp[-4].code).variable->type == INT_TYPE)
      {
        mips_generate((yyvsp[-4].code).listquad);
        quad q = create_quad(NULL, PRINT_INTEGER, NULL, NULL, (yyvsp[-4].code).variable);
        mips_generate(q);
      }
      else
      {
        fprintf(stderr, "Erreur de typage ligne : %d %s n'est pas de type int!\n",yylineno, (yyvsp[-4].code).variable->name);
        exit(3);
      }
    }
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 191 "grammar/texcc.y" /* yacc.c:1646  */
    {
      if((yyvsp[-4].code).variable->type == REAL_TYPE)
      {
        mips_generate((yyvsp[-4].code).listquad);
        quad q = create_quad(NULL, PRINT_REAL, NULL, NULL, (yyvsp[-4].code).variable);
        mips_generate(q);
      }
      else
      {
        fprintf(stderr, "Erreur de typage ligne : %d %s n'est pas de type real!\n",yylineno, (yyvsp[-4].code).variable->name);
        exit(3);
      }
    }
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 206 "grammar/texcc.y" /* yacc.c:1646  */
    {
      if((yyvsp[-4].variable)->type == TEXT_TYPE)
      {
        // On verifie si la chaine existe
        symbol s = search_string((yyvsp[-4].variable)->value.string_value, symbol_table);
        if(s == NULL)
        {
          char id[LENGTH_MAX_STRING];
          sprintf(id, "%d", id_str);

          (yyvsp[-4].variable)->name = strcat(strdup((yyvsp[-4].variable)->name), id);
          s = add_to_symbol_array((yyvsp[-4].variable), symbol_table);
          id_str++;
        }
        quad q = create_quad(NULL, PRINT_STRING, NULL, NULL, s);
        mips_generate(q);
      }
      else
      {
        fprintf(stderr, "Erreur de typage ligne : %d %s n'est pas de type string!\n",yylineno, (yyvsp[-4].variable)->name);
        exit(3);
      }
    }
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 234 "grammar/texcc.y" /* yacc.c:1646  */
    {
      symbol res = (symbol)malloc(sizeof(s_symbol));
      res->name = strdup("tmp_res");
      res->is_tmp = TRUE;
      res->address = strdup("$t0");
      res->type = (yyvsp[-2].code).variable->type;
      // verification du type
      if((yyvsp[-2].code).variable->type == (yyvsp[0].code).variable->type)
      {
        (yyval.code).variable = res;
        quad q = quad_concat((yyvsp[0].code).listquad, (yyvsp[-2].code).listquad);
        (yyval.code).listquad = create_quad(q, OP_PLUS, (yyvsp[-2].code).variable,(yyvsp[0].code).variable, res);
      }
      else
      {
        fprintf(stderr, "Erreur de typage ligne : %d entre %s et %s!\n",yylineno, (yyvsp[-2].code).variable->name, (yyvsp[0].code).variable->name);
        exit(3);
      }
    }
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 255 "grammar/texcc.y" /* yacc.c:1646  */
    {
      symbol res = (symbol)malloc(sizeof(s_symbol));
      res->name = strdup("tmp_res");
      res->is_tmp = TRUE;
      res->address = strdup("$t0");
      res->type = (yyvsp[-2].code).variable->type;
      // verification du type
      if((yyvsp[-2].code).variable->type == (yyvsp[0].code).variable->type)
      {
        (yyval.code).variable = res;
        quad q = quad_concat((yyvsp[0].code).listquad, (yyvsp[-2].code).listquad);
        (yyval.code).listquad = create_quad(q, OP_MINUS, (yyvsp[-2].code).variable,(yyvsp[0].code).variable, res);
      }
      else
      {
        fprintf(stderr, "Erreur de typage ligne : %d entre %s et %s!\n",yylineno, (yyvsp[-2].code).variable->name, (yyvsp[0].code).variable->name);
        exit(3);
      }
    }
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 276 "grammar/texcc.y" /* yacc.c:1646  */
    {
      symbol res = (symbol)malloc(sizeof(s_symbol));
      res->name = strdup("tmp_res");
      res->is_tmp = TRUE;
      res->address = strdup("$t0");
      res->type = (yyvsp[-2].code).variable->type;
      // verification du type
      if((yyvsp[-2].code).variable->type == (yyvsp[0].code).variable->type)
      {
        (yyval.code).variable = res;
        quad q = quad_concat((yyvsp[0].code).listquad, (yyvsp[-2].code).listquad);
        (yyval.code).listquad = create_quad(q, OP_DIV, (yyvsp[-2].code).variable,(yyvsp[0].code).variable, res);
      }
      else
      {
        fprintf(stderr, "Erreur de typage ligne : %d entre %s et %s!\n",yylineno, (yyvsp[-2].code).variable->name, (yyvsp[0].code).variable->name);
        exit(3);
      }
    }
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 297 "grammar/texcc.y" /* yacc.c:1646  */
    {
      symbol res = (symbol)malloc(sizeof(s_symbol));
      res->name = strdup("tmp_res");
      res->is_tmp = TRUE;
      res->address = strdup("$t0");
      res->type = (yyvsp[-2].code).variable->type;
      // verification du type
      if((yyvsp[-2].code).variable->type == (yyvsp[0].code).variable->type)
      {
        //all_quad = create_quad(all_quad, OP_TIMES, $1.variable,$3.variable, res);
        (yyval.code).variable = res;
        quad q = quad_concat((yyvsp[-2].code).listquad, (yyvsp[0].code).listquad);
        (yyval.code).listquad = create_quad(q, OP_TIMES, (yyvsp[-2].code).variable,(yyvsp[0].code).variable, res);
      }
      else
      {
        fprintf(stderr, "Erreur de typage ligne : %d entre %s et %s!\n",yylineno, (yyvsp[-2].code).variable->name, (yyvsp[0].code).variable->name);
        exit(3);
      }
    }
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 319 "grammar/texcc.y" /* yacc.c:1646  */
    {
      (yyval.code) = (yyvsp[-1].code);
    }
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 324 "grammar/texcc.y" /* yacc.c:1646  */
    { // ajout dans la table des symboles;
      (yyvsp[0].variable)->isconst = TRUE;
      (yyval.code).variable = add_to_symbol_array((yyvsp[0].variable), symbol_table);
    }
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 330 "grammar/texcc.y" /* yacc.c:1646  */
    {
      (yyvsp[0].variable)->isconst = TRUE;
      (yyval.code).variable = add_to_symbol_array((yyvsp[0].variable), symbol_table);
    }
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 336 "grammar/texcc.y" /* yacc.c:1646  */
    {
      symbol s = search((yyvsp[0].name), symbol_table);
      if(s == NULL)
      {
        fprintf(stderr, "Erreur ligne : %d la variable %s n'est pas declare !\n",yylineno, (yyvsp[0].name));
        exit(3);
      }
      s->address = NULL;
      (yyval.code).variable = s;
    }
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 350 "grammar/texcc.y" /* yacc.c:1646  */
    {
      quad q = quad_concat((yyvsp[-2].code).listquad, (yyvsp[0].code).listquad);
      (yyval.code).listquad = create_quad(q, OP_BOOL_EQUAL, (yyvsp[-2].code).variable, (yyvsp[0].code).variable, NULL);
      (yyval.code).listquad->label_id = id_label++;
      mips_generate((yyval.code).listquad);
    }
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 358 "grammar/texcc.y" /* yacc.c:1646  */
    {
      quad q = quad_concat((yyvsp[-2].code).listquad, (yyvsp[0].code).listquad);
      (yyval.code).listquad = create_quad(q, OP_BOOL_IEQUAL, (yyvsp[-2].code).variable, (yyvsp[0].code).variable, NULL);
      (yyval.code).listquad->label_id = id_label++;
      mips_generate((yyval.code).listquad);
    }
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 366 "grammar/texcc.y" /* yacc.c:1646  */
    {
      quad q = quad_concat((yyvsp[-2].code).listquad, (yyvsp[0].code).listquad);
      (yyval.code).listquad = create_quad(q, OP_BOOL_SEQUAL, (yyvsp[-2].code).variable, (yyvsp[0].code).variable, NULL);
      (yyval.code).listquad->label_id = id_label++;
      mips_generate((yyval.code).listquad);
    }
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 374 "grammar/texcc.y" /* yacc.c:1646  */
    {
      quad q = quad_concat((yyvsp[-2].code).listquad, (yyvsp[0].code).listquad);
      (yyval.code).listquad = create_quad(q, OP_BOOL_INF, (yyvsp[-2].code).variable, (yyvsp[0].code).variable, NULL);
      (yyval.code).listquad->label_id = id_label++;
      mips_generate((yyval.code).listquad);
    }
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 382 "grammar/texcc.y" /* yacc.c:1646  */
    {
      quad q = quad_concat((yyvsp[-2].code).listquad, (yyvsp[0].code).listquad);
      (yyval.code).listquad = create_quad(q, OP_BOOL_SUP, (yyvsp[-2].code).variable, (yyvsp[0].code).variable, NULL);
      (yyval.code).listquad->label_id = id_label++;
      mips_generate((yyval.code).listquad);
    }
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 390 "grammar/texcc.y" /* yacc.c:1646  */
    {
      (yyval.code).listquad = create_quad(NULL, OP_BOOL_SUP0, (yyvsp[0].code).variable, NULL, NULL);
      (yyval.code).listquad->label_id = id_label++;
      mips_generate((yyval.code).listquad);
    }
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 398 "grammar/texcc.y" /* yacc.c:1646  */
    {
      printf("\n");
      fprintf(stdout, "\t# Initialisation a 0 des variables\n");
      for(int i = 0; i < symbol_table->length && symbol_table->symbol[i]->name != NULL; i++)
      {
        fprintf(stdout, "\tli $t0,0\n");
        fprintf(stdout, "\tsw $t0,%s\n", symbol_table->symbol[i]->name);
      }
      printf("\n");
    }
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 411 "grammar/texcc.y" /* yacc.c:1646  */
    {}
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 415 "grammar/texcc.y" /* yacc.c:1646  */
    {}
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 419 "grammar/texcc.y" /* yacc.c:1646  */
    {}
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 423 "grammar/texcc.y" /* yacc.c:1646  */
    {}
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 427 "grammar/texcc.y" /* yacc.c:1646  */
    { (yyval.variable) = (yyvsp[-2].variable); }
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 429 "grammar/texcc.y" /* yacc.c:1646  */
    { }
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 433 "grammar/texcc.y" /* yacc.c:1646  */
    { (yyval.variable)->name = strdup((yyvsp[-2].name));
                         (yyval.variable)->type = (yyvsp[0].type);
                         // on ajoute l'element dans la table des symboles s'il n'est pas existant
                         symbol s = search((yyval.variable)->name, symbol_table);
                         if(s == NULL)
                         {
                            add_to_symbol_array((yyval.variable), symbol_table);
                            //all_quad = create_quad(all_quad, OP_INIT_VAR, NULL , NULL, $$);
                         }
                         else
                         {
                           fprintf(stderr, "Erreur ligne : %d la variable %s est deja utilise !\n",yylineno, s->name);
                           exit(3);
                         }
                       }
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 449 "grammar/texcc.y" /* yacc.c:1646  */
    {
                         (yyval.variable)->name = strdup((yyvsp[-6].name));
                         (yyval.variable)->type = (yyvsp[-4].type);
                         (yyval.variable)->unit = VECTOR;
                         (yyval.variable)->vector.size = (yyvsp[-1].variable)->value.int_value;
                         // on ajoute l'element dans la table des symboles s'il n'est pas existant
                         symbol s = search((yyval.variable)->name, symbol_table);
                         if(s == NULL)
                         {
                            add_to_symbol_array((yyval.variable), symbol_table);
                            //all_quad = create_quad(all_quad, OP_INIT_VAR, NULL , NULL, $$);
                         }
                         else
                         {
                           fprintf(stderr, "Erreur ligne : %d la variable %s est deja utilise !\n",yylineno, s->name);
                           exit(3);
                         }
                       }
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1887 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 468 "grammar/texcc.y" /* yacc.c:1906  */


int main(int argc, char* argv[]) {
  if (argc == 2) {
    if ((yyin = fopen(argv[1], "r")) == NULL) {
      fprintf(stderr, "[texcc] error: unable to open file %s\n", argv[1]);
      exit(TEXCC_ERROR_GENERAL);
    }
  } else {
    fprintf(stderr, "[texcc] usage: %s input_file\n", argv[0]);
    exit(TEXCC_ERROR_GENERAL);
  }

  id_label = 0;
  symbol_table = (symbol_array)malloc(sizeof(s_symbol_array));
  symbol_table->length = 0;
  memset(symbol_table->symbol, 0, sizeof symbol_table->symbol);
  all_quad = init_quad();
  yyparse();

  FILE * fp;
	fp = fopen ("mips.s", "w+");
	if (fp == NULL) {
	  perror("mips.s");
	  exit(EXIT_FAILURE);
	}

  fclose(yyin);

  //print_quad(all_quad);

  texcc_lexer_free();
  return EXIT_SUCCESS;
}
