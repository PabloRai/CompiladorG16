
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 ".\\Sintactico.y"

#include <stdio.h>
#include <stdlib.h>
#include "symbol.h"
#include "tree.h"
#include <string.h>

#define YYDEBUG 1
extern int yylex();
extern int yyparse();
extern yylineno;
extern FILE* yyin;
void yyerror(const char* s);
void saveIdentifierDeclarationType();
char currentIdentifierDeclarationType[7];
void validateIdIsDeclared();
void compareIdentificators();

ast* tree;


/* Line 189 of yacc.c  */
#line 95 "Sintactico.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     WHILE = 258,
     IF = 259,
     FOR = 260,
     DEFVAR = 261,
     ENDDEF = 262,
     INT_TYPE = 263,
     FLOAT_TYPE = 264,
     STRING_TYPE = 265,
     NEXT = 266,
     TO = 267,
     DISPLAY = 268,
     GET = 269,
     COMMENT = 270,
     FLOAT_CONSTANT = 271,
     STRING_CONSTANT = 272,
     INTEGER_CONSTANT = 273,
     ID = 274,
     OPENING_PARENTHESIS = 275,
     CLOSING_PARENTHESIS = 276,
     ASSIGNMENT_OPERATOR = 277,
     OPENING_KEY = 278,
     CLOSING_KEY = 279,
     OPENING_SQUARE_BRACKET = 280,
     CLOSING_SQUARE_BRACKET = 281,
     SEMICOLON = 282,
     COLON = 283,
     SUM_OPERATOR = 284,
     MINUS_OPERATOR = 285,
     DIVIDE_OPERATOR = 286,
     MULTIPLIER_OPERATOR = 287,
     EQUALS_LOGIC_OPERATOR = 288,
     NOT_EQUALS_LOGIC_OPERATOR = 289,
     NOT_LOGIC_OPERATOR = 290,
     GREATER_LOGIC_OPERATOR = 291,
     GREATER_OR_EQUAL_LOGIC_OPERATOR = 292,
     LOWER_LOGIC_OPERATOR = 293,
     LOWER_OR_EQUAL_LOGIC_OPERATOR = 294
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 90 ".\\Sintactico.y"

  int integer_value;
  float float_value;
  char string_value[30];
  struct treeNode* ast;
  char* auxLogicOperator;



/* Line 214 of yacc.c  */
#line 180 "Sintactico.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 192 "Sintactico.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   128

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  52
/* YYNRULES -- Number of states.  */
#define YYNSTATES  96

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    15,    17,    19,
      21,    23,    25,    27,    35,    39,    47,    58,    68,    71,
      74,    77,    80,    83,    85,    89,    92,    96,    98,   100,
     102,   104,   106,   108,   112,   116,   118,   122,   126,   128,
     130,   132,   134,   136,   140,   144,   147,   149,   153,   155,
     157,   159,   163
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,    42,    -1,    42,    44,    -1,    57,    -1,
      44,    -1,    43,    44,    -1,    45,    -1,    46,    -1,    47,
      -1,    48,    -1,    49,    -1,    50,    -1,     4,    20,    51,
      21,    23,    43,    24,    -1,    19,    22,    54,    -1,     3,
      20,    51,    21,    23,    43,    24,    -1,     5,    19,    22,
      54,    12,    54,    18,    43,    11,    19,    -1,     5,    19,
      22,    54,    12,    54,    43,    11,    19,    -1,    13,    19,
      -1,    13,    18,    -1,    13,    16,    -1,    13,    17,    -1,
      14,    19,    -1,    52,    -1,    52,    53,    52,    -1,    35,
      52,    -1,    54,    53,    54,    -1,    33,    -1,    34,    -1,
      36,    -1,    37,    -1,    38,    -1,    39,    -1,    54,    29,
      55,    -1,    54,    30,    55,    -1,    55,    -1,    55,    32,
      56,    -1,    55,    31,    56,    -1,    56,    -1,    19,    -1,
      18,    -1,    16,    -1,    17,    -1,    20,    54,    21,    -1,
       6,    58,     7,    -1,    58,    59,    -1,    59,    -1,    60,
      28,    61,    -1,     8,    -1,     9,    -1,    10,    -1,    61,
      27,    19,    -1,    19,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   101,   101,   104,   105,   108,   109,   112,   113,   114,
     115,   116,   117,   120,   122,   124,   126,   130,   136,   137,
     138,   139,   142,   144,   145,   146,   149,   152,   153,   154,
     155,   156,   157,   160,   161,   162,   165,   166,   167,   170,
     171,   172,   173,   174,   179,   183,   184,   186,   189,   190,
     191,   194,   195
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "WHILE", "IF", "FOR", "DEFVAR", "ENDDEF",
  "INT_TYPE", "FLOAT_TYPE", "STRING_TYPE", "NEXT", "TO", "DISPLAY", "GET",
  "COMMENT", "FLOAT_CONSTANT", "STRING_CONSTANT", "INTEGER_CONSTANT", "ID",
  "OPENING_PARENTHESIS", "CLOSING_PARENTHESIS", "ASSIGNMENT_OPERATOR",
  "OPENING_KEY", "CLOSING_KEY", "OPENING_SQUARE_BRACKET",
  "CLOSING_SQUARE_BRACKET", "SEMICOLON", "COLON", "SUM_OPERATOR",
  "MINUS_OPERATOR", "DIVIDE_OPERATOR", "MULTIPLIER_OPERATOR",
  "EQUALS_LOGIC_OPERATOR", "NOT_EQUALS_LOGIC_OPERATOR",
  "NOT_LOGIC_OPERATOR", "GREATER_LOGIC_OPERATOR",
  "GREATER_OR_EQUAL_LOGIC_OPERATOR", "LOWER_LOGIC_OPERATOR",
  "LOWER_OR_EQUAL_LOGIC_OPERATOR", "$accept", "program", "sentence",
  "algorithms", "algorithm", "decision", "assignment", "while_loop",
  "for_loop", "display", "get", "condition", "comparation",
  "logic_operator", "expression", "term", "factor",
  "variable_declaration_block", "variable_declarations",
  "variable_declaration", "variable_type", "variable_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    44,    44,    44,
      44,    44,    44,    45,    46,    47,    48,    48,    49,    49,
      49,    49,    50,    51,    51,    51,    52,    53,    53,    53,
      53,    53,    53,    54,    54,    54,    55,    55,    55,    56,
      56,    56,    56,    56,    57,    58,    58,    59,    60,    60,
      60,    61,    61
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     7,     3,     7,    10,     9,     2,     2,
       2,     2,     2,     1,     3,     2,     3,     1,     1,     1,
       1,     1,     1,     3,     3,     1,     3,     3,     1,     1,
       1,     1,     1,     3,     3,     2,     1,     3,     1,     1,
       1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     4,    48,    49,    50,     0,    46,
       0,     1,     0,     0,     0,     0,     0,     0,     3,     7,
       8,     9,    10,    11,    12,    44,    45,     0,     0,     0,
       0,    20,    21,    19,    18,    22,     0,    52,    47,    41,
      42,    40,    39,     0,     0,     0,    23,     0,    35,    38,
       0,     0,    14,     0,     0,    25,     0,    27,    28,    29,
      30,    31,    32,     0,     0,     0,     0,     0,     0,     0,
       0,    51,    43,     0,    24,    33,    34,    26,    37,    36,
       0,     0,     0,     5,     0,     0,    15,     6,    13,     0,
       0,     0,     0,     0,    17,    16
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    82,    83,    19,    20,    21,    22,    23,
      24,    45,    46,    63,    47,    48,    49,     4,     8,     9,
      10,    38
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -38
static const yytype_int8 yypact[] =
{
      58,    90,    21,    88,   -38,   -38,   -38,   -38,    87,   -38,
     -23,   -38,    35,    39,    48,    99,    61,    64,   -38,   -38,
     -38,   -38,   -38,   -38,   -38,   -38,   -38,    70,    31,    31,
      81,   -38,   -38,   -38,   -38,   -38,    53,   -38,    56,   -38,
     -38,   -38,   -38,    53,    53,    85,     3,    75,    26,   -38,
      89,    53,     5,   102,   -15,   -38,   100,   -38,   -38,   -38,
     -38,   -38,   -38,    53,    53,    53,    53,    53,    53,   101,
      15,   -38,   -38,    88,   -38,    26,    26,     5,   -38,   -38,
      88,    53,     6,   -38,    19,    -1,   -38,   -38,   -38,    88,
      49,    71,   103,   106,   -38,   -38
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -38,   -38,   -38,   -24,    -3,   -38,   -38,   -38,   -38,   -38,
     -38,    97,   -37,    80,   -35,    13,    52,   -38,   -38,   120,
     -38,   -38
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      18,    52,    12,    13,    14,    27,    72,    55,    54,    12,
      13,    14,    15,    16,    64,    65,    70,    89,    17,    15,
      16,    11,    12,    13,    14,    17,    74,    81,    64,    65,
      86,    77,    15,    16,    64,    65,    57,    58,    17,    59,
      60,    61,    62,    88,    64,    65,    85,    39,    40,    41,
      42,    43,    12,    13,    14,    28,    84,    67,    68,    29,
      92,    90,    15,    16,     1,    91,    44,    30,    17,    39,
      40,    41,    42,    43,    12,    13,    14,    75,    76,    87,
      35,    87,    93,    53,    15,    16,    36,    87,    87,    37,
      17,    12,    13,    14,    25,     5,     6,     7,     5,     6,
       7,    15,    16,    51,    64,    65,    56,    17,    57,    58,
      69,    59,    60,    61,    62,    31,    32,    33,    34,    78,
      79,    71,    94,    73,    80,    95,    50,    66,    26
};

static const yytype_uint8 yycheck[] =
{
       3,    36,     3,     4,     5,    28,    21,    44,    43,     3,
       4,     5,    13,    14,    29,    30,    51,    18,    19,    13,
      14,     0,     3,     4,     5,    19,    63,    12,    29,    30,
      24,    66,    13,    14,    29,    30,    33,    34,    19,    36,
      37,    38,    39,    24,    29,    30,    81,    16,    17,    18,
      19,    20,     3,     4,     5,    20,    80,    31,    32,    20,
      11,    85,    13,    14,     6,    89,    35,    19,    19,    16,
      17,    18,    19,    20,     3,     4,     5,    64,    65,    82,
      19,    84,    11,    27,    13,    14,    22,    90,    91,    19,
      19,     3,     4,     5,     7,     8,     9,    10,     8,     9,
      10,    13,    14,    22,    29,    30,    21,    19,    33,    34,
      21,    36,    37,    38,    39,    16,    17,    18,    19,    67,
      68,    19,    19,    23,    23,    19,    29,    47,     8
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    41,    42,    57,     8,     9,    10,    58,    59,
      60,     0,     3,     4,     5,    13,    14,    19,    44,    45,
      46,    47,    48,    49,    50,     7,    59,    28,    20,    20,
      19,    16,    17,    18,    19,    19,    22,    19,    61,    16,
      17,    18,    19,    20,    35,    51,    52,    54,    55,    56,
      51,    22,    54,    27,    54,    52,    21,    33,    34,    36,
      37,    38,    39,    53,    29,    30,    53,    31,    32,    21,
      54,    19,    21,    23,    52,    55,    55,    54,    56,    56,
      23,    12,    43,    44,    43,    54,    24,    44,    24,    18,
      43,    43,    11,    11,    19,    19
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 101 ".\\Sintactico.y"
    {printf("\nSUCCESSFUL COMPILATION\n"); (yyval.ast) = (yyvsp[(1) - (1)].ast); tree = (yyval.ast);;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 104 ".\\Sintactico.y"
    {(yyval.ast) = (yyvsp[(2) - (2)].ast);;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 105 ".\\Sintactico.y"
    {;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 108 ".\\Sintactico.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 109 ".\\Sintactico.y"
    {(yyval.ast) = newNode("CUERPO_ALGORITMH", (yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast));;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 112 ".\\Sintactico.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 113 ".\\Sintactico.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 114 ".\\Sintactico.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 115 ".\\Sintactico.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 116 ".\\Sintactico.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 117 ".\\Sintactico.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 120 ".\\Sintactico.y"
    {(yyval.ast) = newNode("IF", (yyvsp[(3) - (7)].ast), (yyvsp[(6) - (7)].ast));;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 122 ".\\Sintactico.y"
    {validateIdIsDeclared((yyvsp[(1) - (3)].string_value)); (yyval.ast) = newNode("=", newLeaf((yyvsp[(1) - (3)].string_value)), (yyvsp[(3) - (3)].ast));;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 124 ".\\Sintactico.y"
    {(yyval.ast) = newNode("WHILE", (yyvsp[(3) - (7)].ast), (yyvsp[(6) - (7)].ast));;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 126 ".\\Sintactico.y"
    {
    compareIdentificators((yyvsp[(2) - (10)].string_value), (yyvsp[(10) - (10)].string_value));
    (yyval.ast) = newNode("FOR", newNode("=", newLeaf((yyvsp[(2) - (10)].string_value)), newNode("FOR_OPCIONAL", newNode("TO", (yyvsp[(4) - (10)].ast), (yyvsp[(6) - (10)].ast)), newLeaf(getSymbolName(&((yyvsp[(7) - (10)].integer_value)),1)))), newNode("CUERPO_FOR", (yyvsp[(8) - (10)].ast), newNode("NEXT", newLeaf((yyvsp[(2) - (10)].string_value)), NULL)));
    ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 130 ".\\Sintactico.y"
    {
    compareIdentificators((yyvsp[(2) - (9)].string_value), (yyvsp[(9) - (9)].string_value));
    (yyval.ast) = newNode("FOR", newNode("=", newLeaf((yyvsp[(2) - (9)].string_value)), newNode("TO", (yyvsp[(4) - (9)].ast), (yyvsp[(6) - (9)].ast))), newNode("CUERPO_FOR", (yyvsp[(7) - (9)].ast), newNode("NEXT", newLeaf((yyvsp[(2) - (9)].string_value)), NULL)));
    ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 136 ".\\Sintactico.y"
    {validateIdIsDeclared((yyvsp[(2) - (2)].string_value)); (yyval.ast) = newNode("DISPLAY", newLeaf((yyvsp[(2) - (2)].string_value)), NULL);;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 137 ".\\Sintactico.y"
    {(yyval.ast) = newNode("DISPLAY",newLeaf(getSymbolName(&((yyvsp[(2) - (2)].integer_value)),1)), NULL);;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 138 ".\\Sintactico.y"
    {(yyval.ast) = newNode("DISPLAY",newLeaf(getSymbolName(&((yyvsp[(2) - (2)].float_value)),2)), NULL);;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 139 ".\\Sintactico.y"
    {(yyval.ast) = newNode("DISPLAY",newLeaf(getSymbolName(&((yyvsp[(2) - (2)].string_value)),3)), NULL);;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 142 ".\\Sintactico.y"
    {(yyval.ast) = newNode("GET", newLeaf((yyvsp[(2) - (2)].string_value)), NULL);;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 144 ".\\Sintactico.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 145 ".\\Sintactico.y"
    {(yyval.ast) = newNode((yyvsp[(2) - (3)].auxLogicOperator), (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 146 ".\\Sintactico.y"
    {(yyval.ast) = newNode("!", (yyvsp[(2) - (2)].ast), NULL);;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 149 ".\\Sintactico.y"
    {(yyval.ast) = newNode((yyvsp[(2) - (3)].auxLogicOperator), (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 152 ".\\Sintactico.y"
    {(yyval.auxLogicOperator) = "=";;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 153 ".\\Sintactico.y"
    {(yyval.auxLogicOperator) = "!=";;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 154 ".\\Sintactico.y"
    {(yyval.auxLogicOperator) = ">";;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 155 ".\\Sintactico.y"
    {(yyval.auxLogicOperator) = ">=";;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 156 ".\\Sintactico.y"
    {(yyval.auxLogicOperator) = "<";;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 157 ".\\Sintactico.y"
    {(yyval.auxLogicOperator) = "<=";;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 160 ".\\Sintactico.y"
    {(yyval.ast) = newNode("+", (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 161 ".\\Sintactico.y"
    {(yyval.ast) = newNode("-", (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 162 ".\\Sintactico.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 165 ".\\Sintactico.y"
    {(yyval.ast) = newNode("*", (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 166 ".\\Sintactico.y"
    {(yyval.ast) = newNode("/", (yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast));;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 167 ".\\Sintactico.y"
    {(yyval.ast) = (yyvsp[(1) - (1)].ast);;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 170 ".\\Sintactico.y"
    {(yyval.ast) = newLeaf((yyvsp[(1) - (1)].string_value));;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 171 ".\\Sintactico.y"
    {(yyval.ast) = newLeaf(getSymbolName(&((yyvsp[(1) - (1)].integer_value)),1));;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 172 ".\\Sintactico.y"
    {(yyval.ast) = newLeaf(getSymbolName(&((yyvsp[(1) - (1)].float_value)),2));;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 173 ".\\Sintactico.y"
    {(yyval.ast) = newLeaf(getSymbolName((yyvsp[(1) - (1)].string_value),3));;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 174 ".\\Sintactico.y"
    {(yyval.ast) = (yyvsp[(2) - (3)].ast);;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 186 ".\\Sintactico.y"
    {putTypeIdentifierOnSymbolTable(currentIdentifierDeclarationType);;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 189 ".\\Sintactico.y"
    {saveIdentifierDeclarationType((yyvsp[(1) - (1)].string_value));;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 190 ".\\Sintactico.y"
    {saveIdentifierDeclarationType((yyvsp[(1) - (1)].string_value));;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 191 ".\\Sintactico.y"
    {saveIdentifierDeclarationType((yyvsp[(1) - (1)].string_value));;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 194 ".\\Sintactico.y"
    {insertIdentifier((yyvsp[(3) - (3)].string_value));;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 195 ".\\Sintactico.y"
    {insertIdentifier((yyvsp[(1) - (1)].string_value));;}
    break;



/* Line 1455 of yacc.c  */
#line 1823 "Sintactico.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 199 ".\\Sintactico.y"


int main(int argc, char *argv[]) {
	yyin = fopen(argv[1], "r");
  #ifdef YYDEBUG
    yydebug = 1;
  #endif
  printf("STARTING COMPILATION\n");
  symbolTable = NULL;
	do {
		yyparse();
	} while(!feof(yyin));
  printTable();
  saveTable();
  printf("\n --- INTERMEDIA --- \n");
  printAST(tree);
	return 0;
}
void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s on line %d\n", s, yylineno);
	exit(1);
}

void saveIdentifierDeclarationType(char* identiferName) {
  strcpy(currentIdentifierDeclarationType, identiferName);
}

void validateIdIsDeclared(char* id) {
  symbolNode* symbol = findSymbol(id);
  if (symbol == NULL || symbol->type == NULL) {
    fprintf(stderr, "\nVariable: %s is not declared on the declaration block on line %d\n", id, yylineno);
    exit(1);
  }
}

void compareIdentificators(char* firstIdentificator, char* secondIdentificator) {
  if (strcmp(firstIdentificator, secondIdentificator) != 0) {
    fprintf(stderr, "\n Identificators are not the same, line: %d\n", yylineno);
    exit(1);
  }
}

