
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
#line 1 "sysY.y"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "translate.h"

int yylex(void);
void yyerror(char*);

extern FILE* yyin;
extern FILE* yyout;
extern int lineno;
struct TreeNode* root;
char *input, *output;

//struct TreeNode* tempNode;
// %right ASSIGN
// %left AND OR
// %left EQ NEQ
// %left LS LSE GR GRE
// %left PLUS MINUS
// %left MUL MOD DIV
// %right NO


/* Line 189 of yacc.c  */
#line 101 "sysY.tab.c"

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
     CONST = 258,
     INT = 259,
     VOID = 260,
     IF = 261,
     ELSE = 262,
     WHILE = 263,
     BREAK = 264,
     CONTINUE = 265,
     RETURN = 266,
     COMMA = 267,
     EOL = 268,
     LPRN = 269,
     RPRN = 270,
     LBRA = 271,
     RBRA = 272,
     LCUR = 273,
     RCUR = 274,
     ASSIGN = 275,
     PLUS = 276,
     MINUS = 277,
     NO = 278,
     MUL = 279,
     DIV = 280,
     MOD = 281,
     LS = 282,
     GR = 283,
     LSE = 284,
     GRE = 285,
     EQ = 286,
     NEQ = 287,
     AND = 288,
     OR = 289,
     INT_CONST = 290,
     IDENT = 291,
     ERROR = 292,
     IFX = 293
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 45 "sysY.y"

	int value;
	char* name;
	struct TreeNode* node;



/* Line 214 of yacc.c  */
#line 183 "sysY.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 195 "sysY.tab.c"

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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   211

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNRULES -- Number of states.  */
#define YYNSTATES  165

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

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
      35,    36,    37,    38
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    11,    13,    15,    17,    22,
      24,    28,    32,    35,    37,    41,    43,    45,    49,    53,
      55,    59,    61,    65,    67,    71,    73,    76,    78,    82,
      88,    95,   101,   108,   110,   114,   117,   123,   128,   129,
     133,   136,   139,   140,   145,   147,   150,   152,   158,   166,
     172,   175,   178,   181,   185,   187,   189,   191,   196,   200,
     202,   204,   206,   208,   212,   217,   220,   222,   224,   226,
     228,   232,   234,   238,   242,   246,   248,   252,   256,   258,
     262,   266,   270,   274,   276,   280,   284,   286,   290,   292,
     296
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      40,     0,    -1,    40,    41,    -1,    41,    -1,    40,    54,
      -1,    54,    -1,    42,    -1,    48,    -1,     3,     4,    43,
      13,    -1,    44,    -1,    43,    12,    44,    -1,    45,    20,
      46,    -1,    36,    57,    -1,    75,    -1,    18,    47,    19,
      -1,    52,    -1,    46,    -1,    47,    12,    46,    -1,     4,
      49,    13,    -1,    50,    -1,    49,    12,    50,    -1,    45,
      -1,    45,    20,    51,    -1,    61,    -1,    18,    53,    19,
      -1,    52,    -1,    18,    19,    -1,    51,    -1,    53,    12,
      51,    -1,     4,    36,    14,    15,    58,    -1,     4,    36,
      14,    55,    15,    58,    -1,     5,    36,    14,    15,    58,
      -1,     5,    36,    14,    55,    15,    58,    -1,    56,    -1,
      55,    12,    56,    -1,     4,    36,    -1,     4,    36,    16,
      17,    57,    -1,    57,    16,    75,    17,    -1,    -1,    18,
      59,    19,    -1,    59,    41,    -1,    59,    60,    -1,    -1,
      63,    20,    61,    13,    -1,    13,    -1,    61,    13,    -1,
      58,    -1,     6,    14,    62,    15,    60,    -1,     6,    14,
      62,    15,    60,     7,    60,    -1,     8,    14,    62,    15,
      60,    -1,     9,    13,    -1,    10,    13,    -1,    11,    13,
      -1,    11,    61,    13,    -1,    70,    -1,    74,    -1,    36,
      -1,    63,    16,    61,    17,    -1,    14,    61,    15,    -1,
      63,    -1,    65,    -1,    35,    -1,    64,    -1,    36,    14,
      15,    -1,    36,    14,    68,    15,    -1,    67,    66,    -1,
      21,    -1,    22,    -1,    23,    -1,    61,    -1,    68,    12,
      61,    -1,    66,    -1,    69,    24,    66,    -1,    69,    25,
      66,    -1,    69,    26,    66,    -1,    69,    -1,    70,    21,
      69,    -1,    70,    22,    69,    -1,    70,    -1,    71,    27,
      70,    -1,    71,    29,    70,    -1,    71,    28,    70,    -1,
      71,    30,    70,    -1,    71,    -1,    72,    31,    71,    -1,
      72,    32,    71,    -1,    72,    -1,    73,    33,    72,    -1,
      73,    -1,    74,    34,    73,    -1,    70,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    54,    54,    59,    65,    70,    78,    81,    86,    98,
     101,   108,   115,   129,   132,   142,   148,   151,   158,   170,
     173,   180,   184,   191,   194,   204,   210,   213,   216,   223,
     227,   238,   242,   255,   258,   265,   269,   284,   291,   294,
     310,   317,   324,   327,   332,   333,   334,   335,   340,   346,
     351,   354,   357,   360,   366,   371,   376,   379,   396,   399,
     402,   407,   413,   416,   419,   428,   457,   460,   463,   468,
     471,   478,   481,   486,   491,   498,   501,   506,   513,   516,
     521,   526,   531,   538,   541,   546,   553,   556,   563,   566,
     573
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CONST", "INT", "VOID", "IF", "ELSE",
  "WHILE", "BREAK", "CONTINUE", "RETURN", "COMMA", "EOL", "LPRN", "RPRN",
  "LBRA", "RBRA", "LCUR", "RCUR", "ASSIGN", "PLUS", "MINUS", "NO", "MUL",
  "DIV", "MOD", "LS", "GR", "LSE", "GRE", "EQ", "NEQ", "AND", "OR",
  "INT_CONST", "IDENT", "ERROR", "IFX", "$accept", "CompUnit", "Decl",
  "ConstDecl", "ConstDefList", "ConstDef", "ConstLVal", "ConstInitVal",
  "ConstInitValList", "VarDecl", "VarDefList", "VarDef", "InitVal",
  "EmptyBlock", "InitValList", "FuncDef", "FuncFParams", "FuncFParam",
  "ConstSuffix", "Block", "BlockItem", "Stmt", "Exp", "Cond", "LVal",
  "PrimaryExp", "Number", "UnaryExp", "UnaryOp", "FuncRParams", "MulExp",
  "AddExp", "RelExp", "EqExp", "LAndExp", "LOrExp", "ConstExp", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    40,    40,    40,    41,    41,    42,    43,
      43,    44,    45,    46,    46,    46,    47,    47,    48,    49,
      49,    50,    50,    51,    51,    51,    52,    53,    53,    54,
      54,    54,    54,    55,    55,    56,    56,    57,    57,    58,
      59,    59,    59,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    61,    62,    63,    63,    64,    64,
      64,    65,    66,    66,    66,    66,    67,    67,    67,    68,
      68,    69,    69,    69,    69,    70,    70,    70,    71,    71,
      71,    71,    71,    72,    72,    72,    73,    73,    74,    74,
      75
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     1,     1,     1,     4,     1,
       3,     3,     2,     1,     3,     1,     1,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     2,     1,     3,     5,
       6,     5,     6,     1,     3,     2,     5,     4,     0,     3,
       2,     2,     0,     4,     1,     2,     1,     5,     7,     5,
       2,     2,     2,     3,     1,     1,     1,     4,     3,     1,
       1,     1,     1,     3,     4,     2,     1,     1,     1,     1,
       3,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     1,     3,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     3,     6,     7,     5,     0,
      38,    21,     0,    19,     0,     1,     2,     4,    38,     0,
       9,     0,     0,    12,     0,     0,    18,     0,     0,     8,
       0,     0,     0,     0,    33,     0,     0,     0,    66,    67,
      68,    61,    56,    22,    25,    23,    59,    62,    60,    71,
       0,    75,    54,    20,     0,     0,    10,     0,    11,    15,
      90,    13,    35,    42,    29,     0,     0,     0,     0,    26,
      27,     0,     0,     0,    65,     0,     0,     0,     0,     0,
      31,     0,    16,     0,     0,     0,    34,    30,    37,    58,
       0,    24,    63,    69,     0,     0,    72,    73,    74,    76,
      77,    32,     0,    14,    38,     0,     0,     0,     0,     0,
       0,    44,    39,    40,    46,    41,     0,    59,    28,     0,
      64,    57,    17,    36,     0,     0,    50,    51,    52,     0,
      45,     0,    70,     0,    78,    83,    86,    88,    55,     0,
      53,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    43,    47,    79,    81,    80,    82,    84,    85,
      87,    89,    49,     0,    48
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,    19,    20,    11,    58,    83,     7,
      12,    13,    43,    44,    71,     8,    33,    34,    23,   114,
      85,   115,   116,   133,    46,    47,    48,    49,    50,    94,
      51,    52,   135,   136,   137,   138,    61
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -124
static const yytype_int16 yypact[] =
{
     102,     6,   -19,    16,    58,  -124,  -124,  -124,  -124,    41,
      74,   103,    53,  -124,   111,  -124,  -124,  -124,  -124,    72,
    -124,   110,    40,   119,    68,    41,  -124,    42,    41,  -124,
     149,   108,   130,     0,  -124,   159,   159,   124,  -124,  -124,
    -124,  -124,   135,  -124,  -124,  -124,   134,  -124,  -124,  -124,
     159,    49,    80,  -124,   130,    30,  -124,   143,  -124,  -124,
      80,  -124,   136,  -124,  -124,   147,   130,   138,   141,  -124,
    -124,    -3,   154,   159,  -124,   159,   159,   159,   159,   159,
    -124,   130,  -124,    20,   157,   118,  -124,  -124,  -124,  -124,
      68,  -124,  -124,  -124,    39,   166,  -124,  -124,  -124,    49,
      49,  -124,   149,  -124,  -124,    41,   144,   172,   174,   175,
      57,  -124,  -124,  -124,  -124,  -124,   178,    48,  -124,   159,
    -124,  -124,  -124,   119,   159,   159,  -124,  -124,  -124,   179,
    -124,   159,  -124,   181,    80,    70,    78,   160,   163,   183,
    -124,   186,    12,   159,   159,   159,   159,   159,   159,   159,
     159,    12,  -124,   193,    80,    80,    80,    80,    70,    70,
      78,   160,  -124,    12,  -124
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -124,  -124,    -2,  -124,  -124,   173,    15,   -49,  -124,  -124,
    -124,   177,   -31,   -26,  -124,   199,   180,   139,   101,   -25,
    -124,  -123,   -23,    81,   -82,  -124,  -124,   -39,  -124,  -124,
      33,   -30,   -14,    59,    60,  -124,   176
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      60,    45,    16,   117,    59,    60,    70,    64,    82,    90,
       9,    74,    65,    68,    45,    66,    91,    10,   106,   153,
     107,   108,   109,   110,    21,   111,    36,    60,   162,    80,
      63,    59,   102,    38,    39,    40,    96,    97,    98,   103,
     164,    87,    65,    21,    31,    81,    31,    41,    42,    93,
      95,   119,    14,   122,   120,    32,   101,    54,    15,   118,
     117,     1,     2,     3,    73,    25,    26,    45,   131,   117,
     128,    36,    60,    75,    76,    77,    59,    18,    38,    39,
      40,   117,    36,   113,    28,    29,    37,   129,    22,    38,
      39,    40,    41,    42,   134,   134,   132,   143,   144,   145,
     146,    78,    79,    41,    42,     1,     2,     3,   141,   147,
     148,    99,   100,   154,   155,   156,   157,   134,   134,   134,
     134,     1,   105,    24,   106,    27,   107,   108,   109,   110,
      30,   111,    36,   158,   159,    35,    63,   112,    36,    38,
      39,    40,    37,    69,    62,    38,    39,    40,    63,    72,
      73,    31,    84,    41,    42,    88,    89,    36,   124,    41,
      42,    57,    69,    36,    38,    39,    40,    57,    36,    92,
      38,    39,    40,    36,   104,    38,    39,    40,    41,    42,
      38,    39,    40,   121,    41,    42,   125,   126,   127,    41,
      42,   130,   140,   149,    41,    42,   142,   150,   151,   152,
     163,    56,    53,    17,    86,   123,   139,    55,   160,     0,
     161,    67
};

static const yytype_int16 yycheck[] =
{
      30,    24,     4,    85,    30,    35,    37,    32,    57,    12,
       4,    50,    12,    36,    37,    15,    19,    36,     6,   142,
       8,     9,    10,    11,     9,    13,    14,    57,   151,    54,
      18,    57,    12,    21,    22,    23,    75,    76,    77,    19,
     163,    66,    12,    28,     4,    15,     4,    35,    36,    72,
      73,    12,    36,   102,    15,    15,    81,    15,     0,    90,
     142,     3,     4,     5,    16,    12,    13,    90,    20,   151,
      13,    14,   102,    24,    25,    26,   102,    36,    21,    22,
      23,   163,    14,    85,    12,    13,    18,   110,    14,    21,
      22,    23,    35,    36,   124,   125,   119,    27,    28,    29,
      30,    21,    22,    35,    36,     3,     4,     5,   131,    31,
      32,    78,    79,   143,   144,   145,   146,   147,   148,   149,
     150,     3,     4,    20,     6,    14,     8,     9,    10,    11,
      20,    13,    14,   147,   148,    16,    18,    19,    14,    21,
      22,    23,    18,    19,    36,    21,    22,    23,    18,    14,
      16,     4,    16,    35,    36,    17,    15,    14,    14,    35,
      36,    18,    19,    14,    21,    22,    23,    18,    14,    15,
      21,    22,    23,    14,    17,    21,    22,    23,    35,    36,
      21,    22,    23,    17,    35,    36,    14,    13,    13,    35,
      36,    13,    13,    33,    35,    36,    15,    34,    15,    13,
       7,    28,    25,     4,    65,   104,   125,    27,   149,    -1,
     150,    35
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    40,    41,    42,    48,    54,     4,
      36,    45,    49,    50,    36,     0,    41,    54,    36,    43,
      44,    45,    14,    57,    20,    12,    13,    14,    12,    13,
      20,     4,    15,    55,    56,    16,    14,    18,    21,    22,
      23,    35,    36,    51,    52,    61,    63,    64,    65,    66,
      67,    69,    70,    50,    15,    55,    44,    18,    46,    52,
      70,    75,    36,    18,    58,    12,    15,    75,    61,    19,
      51,    53,    14,    16,    66,    24,    25,    26,    21,    22,
      58,    15,    46,    47,    16,    59,    56,    58,    17,    15,
      12,    19,    15,    61,    68,    61,    66,    66,    66,    69,
      69,    58,    12,    19,    17,     4,     6,     8,     9,    10,
      11,    13,    19,    41,    58,    60,    61,    63,    51,    12,
      15,    17,    46,    57,    14,    14,    13,    13,    13,    61,
      13,    20,    61,    62,    70,    71,    72,    73,    74,    62,
      13,    61,    15,    27,    28,    29,    30,    31,    32,    33,
      34,    15,    13,    60,    70,    70,    70,    70,    71,    71,
      72,    73,    60,     7,    60
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
#line 54 "sysY.y"
    {
		(yyvsp[(1) - (2)].node)->suc = (yyvsp[(2) - (2)].node);
		(yyvsp[(2) - (2)].node)->pre = (yyvsp[(1) - (2)].node);
		(yyval.node) = (yyvsp[(2) - (2)].node);
  ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 59 "sysY.y"
    {
    struct TreeNode* tempNode;
    tempNode = new_node(TN_ROOT, lineno, NULL);
    tempNode->child[0] = (yyvsp[(1) - (1)].node);(yyvsp[(1) - (1)].node)->parent = tempNode;
    root = tempNode;
  ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 65 "sysY.y"
    {
    (yyvsp[(1) - (2)].node)->suc = (yyvsp[(2) - (2)].node);
		(yyvsp[(2) - (2)].node)->pre = (yyvsp[(1) - (2)].node);
		(yyval.node) = (yyvsp[(2) - (2)].node);
  ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 70 "sysY.y"
    {
    struct TreeNode* tempNode;
    tempNode = new_node(TN_ROOT, lineno, NULL);
    tempNode->child[0] = (yyvsp[(1) - (1)].node);(yyvsp[(1) - (1)].node)->parent = tempNode;
    root = tempNode;
  ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 78 "sysY.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 81 "sysY.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 86 "sysY.y"
    {
    (yyval.node) = new_node(TN_CDECL, lineno, NULL);
    struct TreeNode* tempNode;
    tempNode = (yyvsp[(3) - (4)].node);
    while(tempNode->pre){
      tempNode->parent = (yyval.node);
      tempNode = tempNode->pre;
    }
    (yyval.node)->child[0] = tempNode; tempNode->parent = (yyval.node);
  ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 98 "sysY.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 101 "sysY.y"
    {
    (yyvsp[(1) - (3)].node)->suc = (yyvsp[(3) - (3)].node);
    (yyvsp[(3) - (3)].node)->pre = (yyvsp[(1) - (3)].node);
    (yyval.node) = (yyvsp[(3) - (3)].node);
  ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 108 "sysY.y"
    {
    (yyval.node) = new_node(TN_CDEF, lineno, (yyvsp[(1) - (3)].node)->name);
    (yyval.node)->child[0] = (yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
    (yyval.node)->child[1] = (yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);
  ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 115 "sysY.y"
    {
    (yyval.node) = new_node(TN_CLVAL, lineno, strdup((yyvsp[(1) - (2)].name)));
    if((yyvsp[(2) - (2)].node)){
      (yyvsp[(2) - (2)].node)->parent = (yyval.node);
      struct TreeNode* tempNode;
      tempNode = (yyvsp[(2) - (2)].node);
      while(tempNode->pre){
        tempNode = tempNode->pre;
      }
      (yyval.node)->child[0] = tempNode; tempNode->parent = (yyval.node);
    }
  ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 129 "sysY.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 132 "sysY.y"
    {
    (yyval.node) = new_node(TN_CINITVAL, lineno, NULL);
    struct TreeNode* tempNode;
    tempNode = (yyvsp[(2) - (3)].node);
    while(tempNode->pre){
      tempNode->parent = (yyval.node);
      tempNode = tempNode->pre;
    }
    (yyval.node)->child[0] = tempNode; tempNode->parent = (yyval.node);
  ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 142 "sysY.y"
    {
    (yyval.node) = new_node(TN_CINITVAL, lineno, NULL);
    (yyval.node)->value = 0;
  ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 148 "sysY.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 151 "sysY.y"
    {
    (yyvsp[(1) - (3)].node)->suc = (yyvsp[(3) - (3)].node);
    (yyvsp[(3) - (3)].node)->pre = (yyvsp[(1) - (3)].node);
    (yyval.node) = (yyvsp[(3) - (3)].node);
  ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 158 "sysY.y"
    {
    (yyval.node) = new_node(TN_VDECL, lineno, NULL);
    struct TreeNode* tempNode;
    tempNode = (yyvsp[(2) - (3)].node);
    while(tempNode->pre){
      tempNode->parent = (yyval.node);
      tempNode = tempNode->pre;
    }
    (yyval.node)->child[0] = tempNode; tempNode->parent = (yyval.node);
  ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 170 "sysY.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 173 "sysY.y"
    {
    (yyvsp[(1) - (3)].node)->suc = (yyvsp[(3) - (3)].node);
    (yyvsp[(3) - (3)].node)->pre = (yyvsp[(1) - (3)].node);
    (yyval.node) = (yyvsp[(3) - (3)].node);
  ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 180 "sysY.y"
    {
    (yyval.node) = new_node(TN_VDEF, lineno, (yyvsp[(1) - (1)].node)->name);
    (yyval.node)->child[0] = (yyvsp[(1) - (1)].node); (yyvsp[(1) - (1)].node)->parent = (yyval.node);
  ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 184 "sysY.y"
    {
    (yyval.node) = new_node(TN_VDEF, lineno, (yyvsp[(1) - (3)].node)->name);
    (yyval.node)->child[0] = (yyvsp[(1) - (3)].node); (yyvsp[(1) - (3)].node)->parent = (yyval.node);
    (yyval.node)->child[1] = (yyvsp[(3) - (3)].node); (yyvsp[(3) - (3)].node)->parent = (yyval.node);
  ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 191 "sysY.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 194 "sysY.y"
    {
    (yyval.node) = new_node(TN_INITVAL, lineno, NULL);
    struct TreeNode* tempNode;
    tempNode = (yyvsp[(2) - (3)].node);
    while(tempNode->pre){
      tempNode->parent = (yyval.node);
      tempNode = tempNode->pre;
    }
    (yyval.node)->child[0] = tempNode; tempNode->parent = (yyval.node);
  ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 204 "sysY.y"
    {
    (yyval.node) = new_node(TN_INITVAL, lineno, NULL);
    (yyval.node)->value = 0;
  ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 210 "sysY.y"
    {;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 213 "sysY.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 216 "sysY.y"
    {
    (yyvsp[(1) - (3)].node)->suc = (yyvsp[(3) - (3)].node);
    (yyvsp[(3) - (3)].node)->pre = (yyvsp[(1) - (3)].node);
    (yyval.node) = (yyvsp[(3) - (3)].node);
  ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 223 "sysY.y"
    {
    (yyval.node) = new_node(TN_FUNCDEF_INT, lineno, (yyvsp[(2) - (5)].name));
    (yyval.node)->child[0] = (yyvsp[(5) - (5)].node);(yyvsp[(5) - (5)].node)->parent = (yyval.node);
  ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 227 "sysY.y"
    {
    (yyval.node) = new_node(TN_FUNCDEF_INT, lineno, (yyvsp[(2) - (6)].name));
    struct TreeNode* tempNode;
    tempNode = (yyvsp[(4) - (6)].node);
    while(tempNode->pre){
      tempNode->parent = (yyval.node);
      tempNode = tempNode->pre;
    }
    (yyval.node)->child[0] = (yyvsp[(6) - (6)].node);(yyvsp[(6) - (6)].node)->parent = (yyval.node);
    (yyval.node)->child[1] = tempNode;tempNode->parent = (yyval.node);
  ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 238 "sysY.y"
    {
    (yyval.node) = new_node(TN_FUNCDEF_VOID, lineno, (yyvsp[(2) - (5)].name));
    (yyval.node)->child[0] = (yyvsp[(5) - (5)].node);(yyvsp[(5) - (5)].node)->parent = (yyval.node);
  ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 242 "sysY.y"
    {
    (yyval.node) = new_node(TN_FUNCDEF_VOID, lineno, (yyvsp[(2) - (6)].name));
    struct TreeNode* tempNode;
    tempNode = (yyvsp[(4) - (6)].node);
    while(tempNode->pre){
      tempNode->parent = (yyval.node);
      tempNode = tempNode->pre;
    }
    (yyval.node)->child[0] = (yyvsp[(6) - (6)].node);(yyvsp[(6) - (6)].node)->parent = (yyval.node);
    (yyval.node)->child[1] = tempNode;tempNode->parent = (yyval.node);
  ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 255 "sysY.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 258 "sysY.y"
    {
    (yyvsp[(1) - (3)].node)->suc = (yyvsp[(3) - (3)].node);
    (yyvsp[(3) - (3)].node)->pre = (yyvsp[(1) - (3)].node);
    (yyval.node) = (yyvsp[(3) - (3)].node);
  ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 265 "sysY.y"
    {
    (yyval.node) = new_node(TN_FUNCFP, lineno, NULL);
    (yyval.node)->name = (yyvsp[(2) - (2)].name);
  ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 269 "sysY.y"
    {
    (yyval.node) = new_node(TN_FUNCFP, lineno, NULL);
    (yyval.node)->name = (yyvsp[(2) - (5)].name);
    struct TreeNode* tempNode;
    tempNode = (yyvsp[(5) - (5)].node);
    if(tempNode){
      while(tempNode){
        tempNode->parent = (yyval.node);
        tempNode = tempNode->pre;
      }
    }
    (yyval.node)->child[0] = (yyvsp[(5) - (5)].node);
  ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 284 "sysY.y"
    {
    if((yyvsp[(1) - (4)].node)){
      (yyvsp[(1) - (4)].node)->suc = (yyvsp[(3) - (4)].node);
    }
    (yyvsp[(3) - (4)].node)->pre = (yyvsp[(1) - (4)].node);
    (yyval.node) = (yyvsp[(3) - (4)].node);
  ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 291 "sysY.y"
    {(yyval.node) = NULL;;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 294 "sysY.y"
    {
    (yyval.node) = new_node(TN_BLOCK, lineno, NULL);
    struct TreeNode* tempNode;
    if((yyvsp[(2) - (3)].node)){
      tempNode = (yyvsp[(2) - (3)].node);
      while(tempNode->pre){
        tempNode->parent = (yyval.node);
        tempNode = tempNode->pre;
      }
      tempNode->parent = (yyval.node);
    }
    else tempNode = (yyvsp[(2) - (3)].node);
    (yyval.node)->child[0] = tempNode;
  ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 310 "sysY.y"
    {
    if((yyvsp[(1) - (2)].node)){
      (yyvsp[(1) - (2)].node)->suc = (yyvsp[(2) - (2)].node);
    }
    (yyvsp[(2) - (2)].node)->pre = (yyvsp[(1) - (2)].node);
    (yyval.node) = (yyvsp[(2) - (2)].node);
  ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 317 "sysY.y"
    {
    if((yyvsp[(1) - (2)].node)){
      (yyvsp[(1) - (2)].node)->suc = (yyvsp[(2) - (2)].node);
    }
    (yyvsp[(2) - (2)].node)->pre = (yyvsp[(1) - (2)].node);
    (yyval.node) = (yyvsp[(2) - (2)].node);
  ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 324 "sysY.y"
    {(yyval.node) = NULL;;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 327 "sysY.y"
    {
    (yyval.node) = new_node(TN_STMT_ASSIGN, lineno, NULL);
    (yyval.node)->child[0] = (yyvsp[(1) - (4)].node);(yyvsp[(1) - (4)].node)->parent = (yyval.node);
    (yyval.node)->child[1] = (yyvsp[(3) - (4)].node);(yyvsp[(3) - (4)].node)->parent = (yyval.node);
  ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 332 "sysY.y"
    {;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 333 "sysY.y"
    {(yyval.node) = (yyvsp[(1) - (2)].node);;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 334 "sysY.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 335 "sysY.y"
    {
    (yyval.node) = new_node(TN_STMT_IF, lineno, NULL);
    (yyval.node)->child[0] = (yyvsp[(3) - (5)].node);(yyvsp[(3) - (5)].node)->parent = (yyval.node);
    (yyval.node)->child[1] = (yyvsp[(5) - (5)].node);(yyvsp[(5) - (5)].node)->parent = (yyval.node);
  ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 340 "sysY.y"
    {
    (yyval.node) = new_node(TN_STMT_IF, lineno, NULL);
    (yyval.node)->child[0] = (yyvsp[(3) - (7)].node);(yyvsp[(3) - (7)].node)->parent = (yyval.node);
    (yyval.node)->child[1] = (yyvsp[(5) - (7)].node);(yyvsp[(5) - (7)].node)->parent = (yyval.node);
    (yyval.node)->child[2] = (yyvsp[(7) - (7)].node);(yyvsp[(7) - (7)].node)->parent = (yyval.node);
  ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 346 "sysY.y"
    {
    (yyval.node) = new_node(TN_STMT_WHILE, lineno, NULL);
    (yyval.node)->child[0] = (yyvsp[(3) - (5)].node);(yyvsp[(3) - (5)].node)->parent = (yyval.node);
    (yyval.node)->child[1] = (yyvsp[(5) - (5)].node);(yyvsp[(5) - (5)].node)->parent = (yyval.node);
  ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 351 "sysY.y"
    {
    (yyval.node) = new_node(TN_STMT_BREAK, lineno, NULL);
  ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 354 "sysY.y"
    {
    (yyval.node) = new_node(TN_STMT_CONTINUE, lineno, NULL);
  ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 357 "sysY.y"
    {
    (yyval.node) = new_node(TN_STMT_RETURN, lineno, NULL);
  ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 360 "sysY.y"
    {
    (yyval.node) = new_node(TN_STMT_RETURN, lineno, NULL);
    (yyval.node)->child[0] = (yyvsp[(2) - (3)].node);(yyvsp[(2) - (3)].node)->parent = (yyval.node);
  ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 366 "sysY.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 371 "sysY.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 376 "sysY.y"
    {
    (yyval.node) = new_node(TN_LVAL, lineno, (yyvsp[(1) - (1)].name));
  ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 379 "sysY.y"
    {
    if((yyvsp[(1) - (4)].node)->child[0]){
      struct TreeNode* tempNode;
      tempNode = (yyvsp[(1) - (4)].node)->child[0];
      while(tempNode->suc){
        tempNode = tempNode->suc;
      }
      tempNode->suc = (yyvsp[(3) - (4)].node);(yyvsp[(3) - (4)].node)->pre = tempNode;
    }
    else{
      (yyvsp[(1) - (4)].node)->child[0] = (yyvsp[(3) - (4)].node);
    }
    (yyvsp[(3) - (4)].node)->parent = (yyvsp[(1) - (4)].node);
    (yyval.node) = (yyvsp[(1) - (4)].node);
  ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 396 "sysY.y"
    {
    (yyval.node) = (yyvsp[(2) - (3)].node);
  ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 399 "sysY.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 402 "sysY.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 407 "sysY.y"
    {
    (yyval.node) = new_node(TN_NUMBER, lineno, NULL);
    (yyval.node)->value = (yyvsp[(1) - (1)].value);
  ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 413 "sysY.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 416 "sysY.y"
    {
    (yyval.node) = new_node(TN_UEXP, lineno, (yyvsp[(1) - (3)].name));
  ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 419 "sysY.y"
    {
    (yyval.node) = new_node(TN_UEXP, lineno, (yyvsp[(1) - (4)].name));
    struct TreeNode* tempNode;
    tempNode = (yyvsp[(3) - (4)].node);
    while(tempNode->pre){
      tempNode = tempNode->pre;
    }
    (yyval.node)->child[1] = tempNode;tempNode->parent = (yyval.node);
  ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 428 "sysY.y"
    {
    if(strcmp((yyvsp[(1) - (2)].node)->name, "+")){
      if((yyvsp[(2) - (2)].node)->type == TN_UEXP){
        if((yyvsp[(2) - (2)].node)->child[0] == NULL){
          (yyvsp[(2) - (2)].node)->child[0] = (yyvsp[(1) - (2)].node);(yyvsp[(1) - (2)].node)->parent = (yyvsp[(2) - (2)].node);
        }
        else{
          struct TreeNode* tempNode;
          tempNode = (yyvsp[(2) - (2)].node)->child[0];
          while(tempNode->pre){
            tempNode = tempNode->pre;
          }
          tempNode->pre = (yyvsp[(1) - (2)].node);
          (yyvsp[(1) - (2)].node)->suc = tempNode;
          (yyval.node) = (yyvsp[(2) - (2)].node);
        }
      }
      else{
        (yyval.node) = new_node(TN_UEXP, lineno, NULL);
        (yyval.node)->child[0] = (yyvsp[(1) - (2)].node);(yyvsp[(1) - (2)].node)->parent = (yyval.node);
        (yyval.node)->child[1] = (yyvsp[(2) - (2)].node);(yyvsp[(2) - (2)].node)->parent = (yyval.node);
      }
    }
    else{
      (yyval.node) = (yyvsp[(2) - (2)].node);
    }
  ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 457 "sysY.y"
    {
    (yyval.node) = new_node(TN_UOP, lineno, "+");
  ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 460 "sysY.y"
    {
    (yyval.node) = new_node(TN_UOP, lineno, "-");
  ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 463 "sysY.y"
    {
    (yyval.node) = new_node(TN_UOP, lineno, "!");
  ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 468 "sysY.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 471 "sysY.y"
    {
    (yyvsp[(1) - (3)].node)->suc = (yyvsp[(3) - (3)].node);
    (yyvsp[(3) - (3)].node)->pre = (yyvsp[(1) - (3)].node);
    (yyval.node) = (yyvsp[(3) - (3)].node);
  ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 478 "sysY.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 481 "sysY.y"
    {
    (yyval.node) = new_node(TN_MEXP, lineno, "*");
    (yyval.node)->child[0] = (yyvsp[(1) - (3)].node);(yyvsp[(1) - (3)].node)->parent = (yyval.node);
    (yyval.node)->child[1] = (yyvsp[(3) - (3)].node);(yyvsp[(3) - (3)].node)->parent = (yyval.node);
  ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 486 "sysY.y"
    {
    (yyval.node) = new_node(TN_MEXP, lineno, "/");
    (yyval.node)->child[0] = (yyvsp[(1) - (3)].node);(yyvsp[(1) - (3)].node)->parent = (yyval.node);
    (yyval.node)->child[1] = (yyvsp[(3) - (3)].node);(yyvsp[(3) - (3)].node)->parent = (yyval.node);
  ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 491 "sysY.y"
    {
    (yyval.node) = new_node(TN_MEXP, lineno, "%");
    (yyval.node)->child[0] = (yyvsp[(1) - (3)].node);(yyvsp[(1) - (3)].node)->parent = (yyval.node);
    (yyval.node)->child[1] = (yyvsp[(3) - (3)].node);(yyvsp[(3) - (3)].node)->parent = (yyval.node);
  ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 498 "sysY.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 501 "sysY.y"
    {
    (yyval.node) = new_node(TN_AEXP, lineno, "+");
    (yyval.node)->child[0] = (yyvsp[(1) - (3)].node);(yyvsp[(1) - (3)].node)->parent = (yyval.node);
    (yyval.node)->child[1] = (yyvsp[(3) - (3)].node);(yyvsp[(3) - (3)].node)->parent = (yyval.node);
  ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 506 "sysY.y"
    {
    (yyval.node) = new_node(TN_AEXP, lineno, "-");
    (yyval.node)->child[0] = (yyvsp[(1) - (3)].node);(yyvsp[(1) - (3)].node)->parent = (yyval.node);
    (yyval.node)->child[1] = (yyvsp[(3) - (3)].node);(yyvsp[(3) - (3)].node)->parent = (yyval.node);
  ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 513 "sysY.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 516 "sysY.y"
    {
    (yyval.node) = new_node(TN_REXP, lineno, "<");
    (yyval.node)->child[0] = (yyvsp[(1) - (3)].node);(yyvsp[(1) - (3)].node)->parent = (yyval.node);
    (yyval.node)->child[1] = (yyvsp[(3) - (3)].node);(yyvsp[(3) - (3)].node)->parent = (yyval.node);
  ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 521 "sysY.y"
    {
    (yyval.node) = new_node(TN_REXP, lineno, "<=");
    (yyval.node)->child[0] = (yyvsp[(1) - (3)].node);(yyvsp[(1) - (3)].node)->parent = (yyval.node);
    (yyval.node)->child[1] = (yyvsp[(3) - (3)].node);(yyvsp[(3) - (3)].node)->parent = (yyval.node);
  ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 526 "sysY.y"
    {
    (yyval.node) = new_node(TN_REXP, lineno, ">");
    (yyval.node)->child[0] = (yyvsp[(1) - (3)].node);(yyvsp[(1) - (3)].node)->parent = (yyval.node);
    (yyval.node)->child[1] = (yyvsp[(3) - (3)].node);(yyvsp[(3) - (3)].node)->parent = (yyval.node);
  ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 531 "sysY.y"
    {
    (yyval.node) = new_node(TN_REXP, lineno, ">=");
    (yyval.node)->child[0] = (yyvsp[(1) - (3)].node);(yyvsp[(1) - (3)].node)->parent = (yyval.node);
    (yyval.node)->child[1] = (yyvsp[(3) - (3)].node);(yyvsp[(3) - (3)].node)->parent = (yyval.node);
  ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 538 "sysY.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 541 "sysY.y"
    {
    (yyval.node) = new_node(TN_EEXP, lineno, "==");
    (yyval.node)->child[0] = (yyvsp[(1) - (3)].node);(yyvsp[(1) - (3)].node)->parent = (yyval.node);
    (yyval.node)->child[1] = (yyvsp[(3) - (3)].node);(yyvsp[(3) - (3)].node)->parent = (yyval.node);
  ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 546 "sysY.y"
    {
    (yyval.node) = new_node(TN_EEXP, lineno, "!=");
    (yyval.node)->child[0] = (yyvsp[(1) - (3)].node);(yyvsp[(1) - (3)].node)->parent = (yyval.node);
    (yyval.node)->child[1] = (yyvsp[(3) - (3)].node);(yyvsp[(3) - (3)].node)->parent = (yyval.node);
  ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 553 "sysY.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 556 "sysY.y"
    {
    (yyval.node) = new_node(TN_LAEXP, lineno, NULL);
    (yyval.node)->child[0] = (yyvsp[(1) - (3)].node);(yyvsp[(1) - (3)].node)->parent = (yyval.node);
    (yyval.node)->child[1] = (yyvsp[(3) - (3)].node);(yyvsp[(3) - (3)].node)->parent = (yyval.node);
  ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 563 "sysY.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 566 "sysY.y"
    {
    (yyval.node) = new_node(TN_LOEXP, lineno, NULL);
    (yyval.node)->child[0] = (yyvsp[(1) - (3)].node);(yyvsp[(1) - (3)].node)->parent = (yyval.node);
    (yyval.node)->child[1] = (yyvsp[(3) - (3)].node);(yyvsp[(3) - (3)].node)->parent = (yyval.node);
  ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 573 "sysY.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  ;}
    break;



/* Line 1455 of yacc.c  */
#line 2535 "sysY.tab.c"
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
#line 577 "sysY.y"


void yyerror(char* s){
  extern char* yytext;
	fprintf(stderr, ">> ERROR@L%d: %s at %s\n", lineno, s, yytext);
	exit(-3);
}

int main(int argc, char** argv){
  fopen_s(&yyin, "testfile", "r");
  fopen_s(&yyout, "eeyore", "w");

  FILE* f;
  fopen_s(&f, "tree", "w");
  FILE* f1;
  fopen_s(&f1, "symtab", "w");

  n_treenode = 0;
  InitEnv();
  InitTrans();

  yyparse();

  PrintTree(root, 0, f);
  SetEnv(root, RootEnv);
  PrintEnv(RootEnv, 0, f1);
  ToEeyore(root, RootEnv, yyout, "");
	return 0;
}
